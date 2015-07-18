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

    if (event->key() == Qt::Key_Left)
    {
        qDebug()<<"move";
        mesh->rotate(2, QVector3D(-1,0,0));

        update();
    }


    if (event->key() == Qt::Key_Right)
    {
        mesh->rotate(-2, QVector3D(-1,0,0));

        qDebug()<<"move";


        update();
    }

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
