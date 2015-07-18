#include "scene.h"
#include "rectmesh.h"
#include <QDebug>
namespace  cgl {


Scene::Scene(QObject *parent)
    :QObject(parent), mContext(0)
{

    mCamera.setToIdentity();



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


  mCamera.lookAt(QVector3D(0,0,-10), QVector3D(0,0,0), QVector3D(1,0,0));
}

void Scene::draw()
{
    if (!mContext)
    {
        qDebug()<<Q_FUNC_INFO<<"context not attach to the scene";
        return;
    }


    context()->functions()->glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


    foreach (Mesh * mesh, mMeshs)
    {

        mesh->bind();


        QMatrix4x4 all = mProjection * mCamera;

        mesh->shaders()->setUniformValueArray("projection",&all,1);
        mesh->shaders()->setUniformValueArray("modelview",mesh->transform(),1);

        context()->functions()->glDrawArrays(GL_TRIANGLE_FAN,0,mesh->count());
        mesh->release();
    }





}

void Scene::setPerspective(float verticalAngle, float aspectRatio, float nearPlane, float farPlane)
{
    mProjection.perspective(verticalAngle,aspectRatio,nearPlane,farPlane);
}

}
