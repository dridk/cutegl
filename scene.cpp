#include "scene.h"
#include "planemesh.h"
#include "axismesh.h"
#include <QDebug>
namespace  cgl {

Scene::Scene(QObject *parent)
    :QObject(parent), mContext(0)
{
    addMesh(new AxisMesh(this));
}
//-----------------------------------------
void Scene::addMesh(Mesh *mesh)
{
    mMeshs.append(mesh);
}
//-----------------------------------------

void Scene::removeMesh(Mesh *mesh)
{
    mMeshs.removeOne(mesh);
}
//-----------------------------------------

QList<Mesh *> Scene::meshs() const
{
    return mMeshs;
}
//-----------------------------------------

int Scene::count() const
{
    return mMeshs.count();
}
//-----------------------------------------

void Scene::setContext(QOpenGLContext *context)
{
    mContext = context;
}
//-----------------------------------------

QOpenGLContext *Scene::context()
{
    return mContext;
}
//-----------------------------------------

void Scene::createMeshs()
{
    if (!mContext)
    {
        qDebug()<<Q_FUNC_INFO<<"context not attach to the scene";
        return;
    }

    foreach (Mesh * mesh, mMeshs)
    {
        mesh->setDefaultShaders();
        mesh->create();
    }




}
//-----------------------------------------

void Scene::draw()
{
    if (!mContext)
    {
        qDebug()<<Q_FUNC_INFO<<"context not attach to the scene";
        return;
    }

    context()->functions()->glEnable(GL_DEPTH_TEST);
    context()->functions()->glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    foreach (Mesh * mesh, mMeshs)
    {

        mesh->bind();
        QMatrix4x4 all = mProjection * mView * mesh->model();
        mesh->shaders()->setUniformValueArray("all",&all,1);

        //        mesh->shaders()->setUniformValueArray("projection",&mProjection,1);
        //        mesh->shaders()->setUniformValueArray("model",&mesh->model(),1);
        //        mesh->shaders()->setUniformValueArray("view",&mView,1);

        context()->functions()->glDrawArrays(mesh->mode(),0,mesh->count());
        mesh->release();

    }






}
//-----------------------------------------

void Scene::setPerspective(float verticalAngle, float aspectRatio, float nearPlane, float farPlane)
{
    mProjection.setToIdentity();
    mProjection.perspective(verticalAngle,aspectRatio,nearPlane,farPlane);
}
//-----------------------------------------

void Scene::setOrtho(float left, float right, float bottom, float top, float nearPlane, float farPlane)
{
    mProjection.setToIdentity();
    mProjection.ortho(left,right,bottom,top,nearPlane, farPlane);
}
//-----------------------------------------

void Scene::lookAt(const QVector3D &eye, const QVector3D &center, const QVector3D &up)
{
    mView.setToIdentity();
    mView.lookAt(eye,center,up);


}
//-----------------------------------------

}
