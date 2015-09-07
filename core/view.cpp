#include <QKeyEvent>
#include <qmath.h>
#include <QOpenGLFunctions>
#include <QTimer>
#include "spheremesh.h"
#include "annulusmesh.h"
#include "cylindermesh.h"
#include "scene.h"
#include "view.h"
namespace cgl {
//===================================================================
View::View(int refreshRate) : QOpenGLWindow(),
    mAspect(45.0), mEyePhi(0.0), mEyeR(10.0), mEyeTheta(0.0), mMouseClicked(false)
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

    setEyePosition();

    mEyeUp.setX(0.0);
    mEyeUp.setY(1.0);
    mEyeUp.setZ(0.0);

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
        mEyeTheta += 10.;
        setEyePosition();
        break;
    case Qt::Key_Left:
        mEyeTheta -= 10.;
        setEyePosition();
        break;
    case Qt::Key_Up:
        mEyePhi += 10.;
        if (mEyePhi >= 80.0)
            mEyePhi = 80;
        setEyePosition();
        break;
    case Qt::Key_Down:
        mEyePhi -= 10.;
        if (mEyePhi <= -80.0)
            mEyePhi = -80;
        setEyePosition();
        qDebug() << Q_FUNC_INFO << mEyePhi << mEyePos;
        break;
    case Qt::Key_PageUp:
        mEyeR -= 10;
        setEyePosition();
        break;
    case Qt::Key_PageDown:
        mEyeR += 10;
        setEyePosition();
        break;

    case Qt::Key_F5:
        mScene->setDebug(!mScene->isDebug());
        break;


    default:
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

        mEyeTheta += xOffset;
        mEyePhi   += yOffset;

        if (mEyePhi > 89.9)
            mEyePhi = 89.9;
        if (mEyePhi < -89.9)
            mEyePhi = -89.9;

        setEyePosition();

        mMousePosition = event->pos();
    }
    update();
}

//===================================================================
void View::mousePressEvent(QMouseEvent */*event*/)
{
    // set mouse clicked

    mMouseClicked = true;

}

void View::mouseReleaseEvent(QMouseEvent *)
{
    mMouseClicked = false;
}

//===================================================================
void View::paintGL()
{
    // makes the drawing; called each time screen is refreshed
    mScene->setPerspective(mAspect, ((double) width()) / ((double)height()), 1, 100.0f);
    mScene->lookAt(mEyePos, mEyePos + mViewCenter, mEyeUp);
    mScene->draw();
}

//===================================================================
void View::resizeGL(int w, int h)
{
    // resizes the screen

    context()->functions()->glViewport(0, 0, w, h);
}

//===================================================================
void View::setEyePosition()
{
    // position the eye viewing the scene

    double rtheta = qDegreesToRadians(mEyeTheta);
    double rphi   = qDegreesToRadians(mEyePhi);

    double x = mEyeR * qSin(rtheta) * qCos(rphi);
    double z = mEyeR * qCos(rtheta) * qCos(rphi);
    double y = mEyeR * qSin(rphi);

    mEyePos.setX(x);
    mEyePos.setZ(z);
    mEyePos.setY(y);

    mViewCenter.setX(-x);
    mViewCenter.setY(-y);
    mViewCenter.setZ(-z);
    mViewCenter.normalize();
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
