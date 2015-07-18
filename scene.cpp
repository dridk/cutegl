#include "scene.h"
#include "rectmesh.h"
#include "axismesh.h"
#include <QDebug>
namespace  cgl {


Scene::Scene(QObject *parent)
    :QObject(parent), mContext(0)
{

    mModel.setToIdentity();
    mView.lookAt(QVector3D(5,5,5), QVector3D(0,0,0), QVector3D(0,1,0));

    addMesh(new AxisMesh(this));
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


  addMesh(new AxisMesh);

}

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

        mesh->shaders()->setUniformValueArray("projection",&mProjection,1);
        mesh->shaders()->setUniformValueArray("model",&mModel,1);
        mesh->shaders()->setUniformValueArray("view",&mView,1);


//        mesh->shaders()->setUniformValueArray("modelview",mesh->transform(),1);

        context()->functions()->glDrawArrays(mesh->mode(),0,mesh->count());
        mesh->release();
    }





}

void Scene::setPerspective(float verticalAngle, float aspectRatio, float nearPlane, float farPlane)
{
   mProjection.perspective(verticalAngle,aspectRatio,nearPlane,farPlane);
}

}
