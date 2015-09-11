#include <QKeyevent>
#include <qmath.h>
#include <QOpenGLFunctions>
#include <QTimer>

#include "camera.h"
#include "scene.h"
#include "view.h"

namespace cgl {
//===================================================================
View::View(int refreshRate) : QOpenGLWindow(),
    mAspect(45.0), mMouseClicked(false)
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
        qDebug() << Q_FUNC_INFO;
        break;
    case Qt::Key_PageDown:
        mScene->camera()->zoom(+1);
        break;
    case Qt::Key_D:
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

        mScene->camera()->setTheta(xOffset);
        mScene->camera()->setPhi(yOffset);

        mMousePosition = event->pos();
    }
    update();
}

//===================================================================
void View::mousePressEvent(QMouseEvent */*event*/)
{
    // set mouse clicked
    mMouseClicked = !mMouseClicked;

}

//===================================================================
void View::paintGL()
{
    // makes the drawing; called each time screen is refreshed
    mScene->setPerspective(mAspect, ((double) width()) / ((double)height()), 1, 100.0f);
    mScene->lookAt(mScene->camera()->Position(), mScene->camera()->Position() + mScene->camera()->view(), mScene->camera()->up());
    mScene->draw();
}

//===================================================================
void View::resizeGL(int w, int h)
{
    // resizes the screen

    context()->functions()->glViewport(0, 0, w, h);
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
