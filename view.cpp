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

    connect(mLogger,SIGNAL(messageLogged(QOpenGLDebugMessage)),this,SLOT(printLog(QOpenGLDebugMessage)));

    mAnim = new QVariantAnimation(this);
    mAnim->setStartValue(0);
    mAnim->setEndValue(3600);


    mAnim->setDuration(20000);
    mAnim->setEasingCurve(QEasingCurve::OutBounce);

    connect(mAnim,SIGNAL(valueChanged(QVariant)),this,SLOT(anim(QVariant)));

    mAnim->start();

    mCamera = QVector3D(5,5,5);

    setMouseGrabEnabled(true);
    mClick = false;
}

void View::initializeGL()
{

    setDebugger(true);

    mScene->setContext(context());
    mScene->setPerspective(45.0, ((double)width()) / height(), 1, 100.0f);

    mesh = new CubeMesh(this);

    mScene->addMesh(mesh);
    mScene->createMeshs();


    context()->functions()->glViewport(0,0,width(),height());



}

void View::paintGL()
{

    mScene->lookAt(mCamera, QVector3D(0,0,0), QVector3D(0,1,0));

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

    if (event->key() == Qt::Key_Up)
    {
        qDebug()<<"move";
        mCamera.setX(mCamera.x() - 2);
        update();
    }

    if (event->key() == Qt::Key_Down)
    {
        qDebug()<<"move";
        mCamera.setX(mCamera.x() + 2);
        update();
    }

    if (event->key() == Qt::Key_Right)
    {
        mesh->rotate(-2, QVector3D(-1,0,0));
        qDebug()<<"move";
        update();
    }


    if (event->key() == Qt::Key_Left)
    {
        mesh->rotate(-2, QVector3D(-1,0,0));
        qDebug()<<"move";
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

        oldPos = event->pos();
        QPoint currPos = event->pos();
        if (event->pos().x() < 60)
            currPos.setX(60);

        if (event->pos().y() > 450)
            currPos.setY(450);

        QPoint diff = currPos - oldPos;

        if (diff.x() > 0)
            angle += 3.0f;
        else if (diff.x() < 0)
            angle -= 3.0f;




    }
}

void View::mouseReleaseEvent(QMouseEvent *)
{
    mClick = false;
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
