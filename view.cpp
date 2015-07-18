#include "view.h"
#include <QDebug>
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


    resize(600,400);

    connect(mLogger,SIGNAL(messageLogged(QOpenGLDebugMessage)),this,SLOT(printLog(QOpenGLDebugMessage)));

}

void View::initializeGL()
{

    setDebugger(true);

    mScene->setContext(context());
    mScene->setPerspective(45.0, ((double)width()) / height(), 0, 100);
    mScene->createMeshs();




}

void View::paintGL()
{


    mScene->draw();


}

void View::resizeGL()
{

}

void View::setDebugger(bool active)
{
    if (active){
        mLogger->initialize();
        mLogger->startLogging();
    }

        mLogger->stopLogging();
}

void View::printLog(const QOpenGLDebugMessage &msg)
{
    qDebug()<<msg.id()<<" "<<msg.message();

}


} // End namespace cgl
