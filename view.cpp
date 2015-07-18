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
    lastPos = QPoint(400,300);

    connect(mLogger,SIGNAL(messageLogged(QOpenGLDebugMessage)),this,SLOT(printLog(QOpenGLDebugMessage)));

    mAnim = new QVariantAnimation(this);
    mAnim->setStartValue(0);
    mAnim->setEndValue(3600);


    mAnim->setDuration(20000);
    mAnim->setEasingCurve(QEasingCurve::OutBounce);

    connect(mAnim,SIGNAL(valueChanged(QVariant)),this,SLOT(anim(QVariant)));

    mAnim->start();

    mCameraPos   = QVector3D(0,0,3);
    mCameraFront = QVector3D(0,0,-1);
    mCameraUp    = QVector3D(0,1,0);

    setMouseGrabEnabled(true);
    mClick = false;

    yaw = -90.0f;
    pitch = 0.0f;
    aspect = 45.0f;
}

void View::initializeGL()
{

    setDebugger(true);

    mScene->setContext(context());

    mesh = new CubeMesh(this);

    mScene->addMesh(mesh);
    mScene->createMeshs();


    context()->functions()->glViewport(0,0,width(),height());



}

void View::paintGL()
{
    mScene->setPerspective(aspect, ((double)width()) / height(), 1, 100.0f);
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

        float xOffset  =  event->pos().x() - lastPos.x() ;
        float yOffset  =  lastPos.y() - event->pos().y();

        QPointF offset(xOffset,yOffset);

        lastPos = event->pos();

        float sensitivity = 0.05f;

        offset    *= sensitivity;

        yaw   += offset.x();
        pitch += offset.y();

        if(pitch > 89.0f)
            pitch =  89.0f;
        if(pitch < -89.0f)
            pitch = -89.0f;


        float x = qCos(qDegreesToRadians(pitch))  * cos(qDegreesToRadians(yaw));
        float y = qSin(qDegreesToRadians(pitch));
        float z = qCos(qDegreesToRadians(pitch))  * sin(qDegreesToRadians(yaw));

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

    qDebug()<<event->angleDelta()<<aspect;

    if(aspect >= 1.0f && aspect <= 45.0f)
      aspect -= event->delta()/120;
    if(aspect <= 1.0f)
      aspect = 1.0f;
    if(aspect >= 45.0f)
      aspect = 45.0f;

    update();
}

void View::printLog(const QOpenGLDebugMessage &msg)
{
    qDebug()<<msg.id()<<" "<<msg.message();

}

void View::anim(const QVariant &value)
{

    mesh->resetTransform();
    mesh->rotate(value.toFloat()/10.0, QVector3D(-1,0,0));

    update();

}


} // End namespace cgl
