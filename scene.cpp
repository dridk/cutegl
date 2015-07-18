#include "scene.h"
#include "rectmesh.h"
#include <QDebug>
namespace  cgl {


Scene::Scene(QObject *parent)
    :QObject(parent), mContext(0)
{

    addMesh(new RectMesh(0,0,1,1));



}




void Scene::addMesh(Mesh *mesh)
{
    mMeshs.append(mesh);
}

void Scene::removeMesh(Mesh *mesh)
{
    mMeshs.removeOne(mesh);
}

QList<Mesh *> Scene::meshs() const
{
    return mMeshs;
}

void Scene::setContext(QOpenGLContext *context)
{
    mContext = context;
}

QOpenGLContext *Scene::context()
{
    return mContext;
}

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

void Scene::draw()
{
    if (!mContext)
    {
        qDebug()<<Q_FUNC_INFO<<"context not attach to the scene";
        return;
    }

    foreach (Mesh * mesh, mMeshs)
    {

        mesh->bind();
        mesh->shaders()->setUniformValueArray("projection",&mProjection,1);
        context()->functions()->glDrawArrays(GL_TRIANGLES,0,mesh->count());
        mesh->release();
    }





}

void Scene::setPerspective(float verticalAngle, float aspectRatio, float nearPlane, float farPlane)
{
    mProjection.perspective(verticalAngle,aspectRatio,nearPlane,farPlane);
}

}
