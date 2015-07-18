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
        mesh->transform()->rotate(2, QVector3D(-1,0,0));
        qDebug()<<*(mesh->transform());
        update();
    }


    if (event->key() == Qt::Key_Right)
    {
        qDebug()<<"move";
        mesh->transform()->rotate(-2, QVector3D(1,0,0));
        qDebug()<<*(mesh->transform());
        update();
    }

}

void View::printLog(const QOpenGLDebugMessage &msg)
{
    qDebug()<<msg.id()<<" "<<msg.message();

}


} // End namespace cgl
