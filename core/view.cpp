#include <QKeyEvent>
#include <qmath.h>
#include <QOpenGLFunctions>
#include <QTimer>

#include "camera.h"
#include "scene.h"
#include "view.h"

namespace cgl {
//===================================================================
View::View(int refreshRate) : QOpenGLWindow(),
    mAspect(45.0), mMouseClicked(false), mOpacity(false)
{
    // ctor

    setTitle("titre");
    setScene(new Scene);

    QSurfaceFormat format;
    format.setMajorVersion(3);
    format.setMinorVersion(4);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setSamples(4);
    format.setDepthBufferSize(24);
    setFormat(format);

    mDebugLogger = new QOpenGLDebugLogger(this);
    connect(mDebugLogger, SIGNAL(messageLogged(QOpenGLDebugMessage)), this, SLOT(printLog(QOpenGLDebugMessage)));

    resize(800, 600);
    mMousePosition = QPointF(width() / 2, height() / 2);

    int second = 10000; // 1 second = 1000 ms
    int timerInterval = second / refreshRate;
    mTimer = new QTimer(this);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
   // mTimer->start(timerInterval);
    // Tu fais pas un jeux video! Tu appel update() qd tu veux rafrachir!
}

//===================================================================
void View::initializeGL()
{
    // initialisation of QOpenGL (called once)

    qDebug() << Q_FUNC_INFO;
    setDebugger(true);
    mScene->setContext(context());

    // stage(); // to be implemented by derived class

    mScene->createMeshes();
    context()->functions()->glViewport(0, 0, width(), height());
}

//===================================================================
void View::keyPressEvent(QKeyEvent *event)
{
    // define action in response to keyboard key pressed

    switch (event->key()) {
    case Qt::Key_Escape:
        close();
        break;
    case Qt::Key_F1:
        toggleFullScreen();
        break;
    case Qt::Key_Right:
        if (event->modifiers().testFlag(Qt::ShiftModifier))
            mScene->camera()->incX(+1);
        else
            mScene->camera()->incTheta(+1);
        break;
    case Qt::Key_Left:
        if (event->modifiers().testFlag(Qt::ShiftModifier))
            mScene->camera()->incX(-1);
        else
            mScene->camera()->incTheta(-1);
        break;
    case Qt::Key_Up:
        if (event->modifiers().testFlag(Qt::ShiftModifier))
            mScene->camera()->incY(+1);
        else
            mScene->camera()->incPhi(+1);
         break;
    case Qt::Key_Down:
        if (event->modifiers().testFlag(Qt::ShiftModifier))
            mScene->camera()->incY(-1);
        else
            mScene->camera()->incPhi(-1);
        break;
    case Qt::Key_PageUp:
        mScene->camera()->zoom(-1);
        break;
    case Qt::Key_PageDown:
        mScene->camera()->zoom(+1);
        break;
    case Qt::Key_Minus:
        scale(0.5);
        break;
    case Qt::Key_Plus:
        scale(1.5);
        break;
    default:
        break;
    case Qt::Key_D:
        mScene->setDebug(!mScene->isDebug());
        break;
    case Qt::Key_O:
    {
        for (int index = 0; index < scene()->meshes().size(); index++) {
            if (mOpacity) {
                scene()->meshes().at(index)->setOpacity(1);
                mOpacity = false;
            }
            else {
                scene()->meshes().at(index)->setOpacity(0.5);
                mOpacity = true;
            }
        }
    }
        break;
    case Qt::Key_R:
        mScene->camera()->reset();
        break;
    }
    update();
}

//===================================================================
void View::mouseMoveEvent(QMouseEvent *event)
{
    // define action in response to mouse moved

    if (mMouseClicked) {
        float xOffset = (event->pos().x() - mMousePosition.x());
        float yOffset = (event->pos().y() - mMousePosition.y());

        mScene->camera()->setTheta(xOffset);
        mScene->camera()->setPhi(yOffset);
        mMousePosition = event->pos();

    } else {

        // see http://antongerdelan.net/opengl/raycasting.html

        float x =  ( 2.0 * event->pos().x() ) / width() -1.0;
        float y = 1.0 - ( 2.0 * event->pos().y()) / height();              // revert the orientation of y ( 1 on the top)
        float z = 1.0; // dummy

        QVector3D posMouse(x, y, z);                                         // normalized mouse position x and y in [-1, 1], z dummy


        float w = 1.0; // dummy
        QVector4D rayClip(posMouse.x(), posMouse.y(), -posMouse.z(), w);     // clip coordinates, z negative is pointing forwards, w dummy

        QVector4D rayEye = scene()->projectionMatrix().inverted() * rayClip; // transform in the camera coordinate system
        rayEye.setZ(-1.0);
        rayEye.setW(0.0);


        QVector4D tempo = scene()->viewMatrix().inverted() * rayEye;    // in the world coordinate system
        QVector3D rayWorld;
        rayWorld.setX(tempo.x());
        rayWorld.setY(tempo.y());
        rayWorld.setZ(tempo.z());
        rayWorld.normalize();

        qDebug() << Q_FUNC_INFO << "rayWorld" << rayWorld;

        qDebug() << Q_FUNC_INFO << scene()->whereIs(rayWorld);

//        for (int index = 0; index < scene()->mMeshes.at(1)->verticesCount(); index++) {
//            QVector3D pos =  scene()->mMeshes.at(1)->vertices().at(index).pos();
//            QVector3D popo = scene()->projectionMatrix() * scene()->viewMatrix() * pos;
//            qDebug() << Q_FUNC_INFO << "before" <<  popo;
//            popo = scene()->projectionMatrix() * scene()->viewMatrix() * scene()->mMeshes.at(1)->modelMatrix() * pos;
//            qDebug() << Q_FUNC_INFO <<  "after" << popo;
//        }
    }
    update();
}

//===================================================================
void View::mousePressEvent(QMouseEvent *event)

{
    // set mouse clicked
        qDebug() << Q_FUNC_INFO;
        mMouseClicked = !mMouseClicked;

}

//===================================================================
void View::wheelEvent(QWheelEvent *event)
{
    // when wheel used
    const double kSensitivity = 0.1;
    mScene->camera()->setInc(kSensitivity);

    double delta = event->delta();
    if (delta == 0)
        delta = 1;
    short int sign = delta / qAbs(delta);

    if (event->modifiers().testFlag(Qt::ShiftModifier))
        mScene->camera()->incY(-sign);
    else if (event->modifiers().testFlag((Qt::AltModifier)))
        mScene->camera()->incX(sign);
    else {
        mScene->camera()->zoom(sign);
    }
    update();
    mScene->camera()->setInc(1.0 / kSensitivity);
}

//===================================================================
void View::paintGL()
{
    // makes the drawing; called each time screen is refreshed
    mScene->setPerspective(mAspect, ((double) width()) / ((double)height()), 1, 100.0f);
    mScene->lookAt(mScene->camera()->position(), mScene->camera()->position() + mScene->camera()->target(), mScene->camera()->up());
    mScene->draw();
}

//===================================================================
void View::resizeGL(int w, int h)
{
    // resizes the screen

    context()->functions()->glViewport(0, 0, w, h);
}

//===================================================================
void View::scale(float updown)
{
    // scales all objects in the scene (can be overwritten)


    scene()->scale(updown);


}

//===================================================================
void View::toggleFullScreen()
{
    // toggle between full screen mode
    if (mFullScreen) {
        showNormal();
        mFullScreen = false;
    } else {
        showFullScreen();
        mFullScreen = true;
    }
}

//===================================================================
void View::setDebugger(bool active)
{
    // start/stop QOpenGL debug logging
    if (active) {
        mDebugLogger->initialize();
        mDebugLogger->startLogging();
    } else {
        mDebugLogger->stopLogging();
    }
}

//===================================================================
void View::timeOutSlot()
{
    update();
}

//===================================================================
void View::printLog(const QOpenGLDebugMessage &msg)
{
    qDebug() << msg.id() << msg.message();
}
}
