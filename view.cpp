#include "view.h"
#include <QDebug>
#include "rectmesh.h"
namespace cgl {

View::View()
    :QOpenGLWindow()
{
    mScene  = new Scene(this);
    mLogger = new QOpenGLDebugLogger(this);

    QSurfaceFormat format;
    format.setMajorVersion(3);
    format.setMinorVersion(4);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setSamples(4);
    format.setDepthBufferSize(24);
    setFormat(format);


    resize(800,600);
    mLastPos     = QPoint(400,300);
    mCameraPos   = QVector3D(0,0,3);
    mCameraFront = QVector3D(0,0,-1);
    mCameraUp    = QVector3D(0,1,0);
    mClick       = false;
    mYaw         = -90.0f;
    mPitch       = 0.0f;
    mAspect      = 45.0f;

    connect(mLogger,SIGNAL(messageLogged(QOpenGLDebugMessage)),this,SLOT(printLog(QOpenGLDebugMessage)));
    setMouseGrabEnabled(true);

    mAnimation = new QVariantAnimation(this);
    mAnimation->setStartValue(0);
    mAnimation->setEndValue(360);
    mAnimation->setLoopCount(-1);
    mAnimation->setDuration(5000);

//    mAnimation->start();
    connect(mAnimation,SIGNAL(valueChanged(QVariant)),this,SLOT(anim(QVariant)));



}

void View::initializeGL()
{

    setDebugger(true);

    mScene->setContext(context());

    mesh = new ModelMesh(":/models/teapot.obj",this);

    mScene->addMesh(mesh);
    mesh->scale(0.3);

    mScene->createMeshs();


    context()->functions()->glViewport(0,0,width(),height());



}

void View::paintGL()
{
    mScene->setPerspective(mAspect, ((double)width()) / height(), 1, 100.0f);
    mScene->lookAt(mCameraPos, mCameraPos + mCameraFront, mCameraUp);
    mScene->draw();


}

void View::resizeGL()
{

    context()->functions()->glViewport(0,0,width(),height());
}

void View::setDebugger(bool active)
{
    if (active){
        mLogger->initialize();
        mLogger->startLogging();
    }

    mLogger->stopLogging();
}

void View::keyPressEvent(QKeyEvent *event)
{

    float cameraSpeed = 2;

    if (event->key() == Qt::Key_Z)
    {
        mCameraPos += cameraSpeed * mCameraFront;
        update();
    }

    if (event->key() == Qt::Key_S)
    {
        mCameraPos -= cameraSpeed * mCameraFront;
        update();
    }

    if (event->key() == Qt::Key_Q)
    {

        QVector3D v = QVector3D::crossProduct(mCameraFront, mCameraUp);
        v.normalize();
        mCameraPos-= v * cameraSpeed;
        update();
    }


    if (event->key() == Qt::Key_D)
    {
        QVector3D v = QVector3D::crossProduct(mCameraFront, mCameraUp);
        v.normalize();
        mCameraPos+= v * cameraSpeed;
        update();
    }


    if (event->key() == Qt::Key_Left)
    {
        mesh->rotate(10, QVector3D(0,0,1));
        update();
    }

    if (event->key() == Qt::Key_Right)
    {
        mesh->rotate(-10, QVector3D(0,0,1));

        update();
    }

    if (event->key() == Qt::Key_Up)
    {
        mesh->rotate(10, QVector3D(0,1,0));
        update();
    }

    if (event->key() == Qt::Key_Down)
    {
        mesh->rotate(-10, QVector3D(0,1,0));

        update();
    }
}

void View::mousePressEvent(QMouseEvent * event)
{

    if (event->button() == Qt::LeftButton)
    {
        mClick = true;
    }

    else
        mClick = false;

}

void View::mouseMoveEvent(QMouseEvent * event)
{
    if (mClick)
    {

        float xOffset  =  event->pos().x() - mLastPos.x() ;
        float yOffset  =  mLastPos.y() - event->pos().y();

        QPointF offset(xOffset,yOffset);

        mLastPos = event->pos();

        float sensitivity = 0.05f;

        offset    *= sensitivity;

        mYaw   += offset.x();
        mPitch += offset.y();

        if(mPitch > 89.0f)
            mPitch =  89.0f;
        if(mPitch < -89.0f)
            mPitch = -89.0f;


        float x = qCos(qDegreesToRadians(mPitch))  * cos(qDegreesToRadians(mYaw));
        float y = qSin(qDegreesToRadians(mPitch));
        float z = qCos(qDegreesToRadians(mPitch))  * sin(qDegreesToRadians(mYaw));

        mCameraFront = QVector3D(x,y,z);
        mCameraFront.normalize();

        update();

    }
}

void View::mouseReleaseEvent(QMouseEvent *)
{
    mClick = false;
}

void View::wheelEvent(QWheelEvent * event)
{


    if(mAspect >= 1.0f && mAspect <= 45.0f)
      mAspect -= event->delta()/120;
    if(mAspect <= 1.0f)
      mAspect = 1.0f;
    if(mAspect >= 45.0f)
      mAspect = 45.0f;

    update();
}

void View::printLog(const QOpenGLDebugMessage &msg)
{
    qDebug()<<msg.id()<<" "<<msg.message();

}

void View::anim(const QVariant &value)
{

    qDebug()<<mAnimation->currentValue().toFloat();
    mesh->resetTransform();
    mesh->rotate(mAnimation->currentValue().toFloat(), QVector3D(0,0,1));
    update();

}




} // End namespace cgl
