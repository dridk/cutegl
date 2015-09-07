#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include "scene.h"
namespace cgl {
//===================================================================
Scene::Scene(QObject *parent) : QObject(parent), mContext(0), mDebug(false)
{
        // Add default light... Otherwise black screen !
       addLight(new Light(5,5,5));
}

//===================================================================
void Scene::createMeshes()
{
    // creates the drawing for all meshes in the graphic card
    if(!mContext) {
        qFatal("Scene::createMeshes ---> no QOpenGLContext defined");
        exit(QtFatalMsg);
    }
    foreach (Mesh *mesh, mMeshes) {
        mesh->setDefaultShaders();
        mesh->create();
        //        mesh->setTexture(mesh->textureImage());
    }
}

//===================================================================
void Scene::draw()
{
    // draw all the objects in the scene
    if(!mContext) {
        qFatal("Scene::createMeshes ---> no QOpenGLContext defined");
        exit(QtFatalMsg);
    }

    mContext->functions()->glEnable(GL_DEPTH_TEST);
    mContext->functions()->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    foreach (Mesh * mesh, mMeshes) {
        mesh->shaderProgram()->bind();
        mesh->bind();
        QMatrix4x4 all = mProjection * mView * mesh->modelMatrix();

        // Apply light uniform value
        if (!mLights.isEmpty())
        {

//           QVector3D np =   mProjection* mView * mLights.first()->position();
//           QVector3D np =   all* mLights.first()->position();
             QVector3D np =   mLights.first()->position();
            mesh->shaderProgram()->setUniformValue("light.position",np);
            mesh->shaderProgram()->setUniformValue("light.ambient",  mLights.first()->colorVector());
        }

        mesh->shaderProgram()->setUniformValueArray("all", &all, 1);

        if (mesh->hasIndices())
            mContext->functions()->glDrawArrays(mesh->mode(), 0, mesh->verticesCount());
        else
            mContext->functions()->glDrawElements(mesh->mode(), mesh->indicesCount(), GL_UNSIGNED_INT, 0);
        mesh->release();
    }
}

//===================================================================
void Scene::lookAt(const QVector3D &eye, const QVector3D &center, const QVector3D &up)
{
    mView.setToIdentity();
    mView.lookAt(eye, center, up);
}

//===================================================================
void Scene::setOrtho(float left, float right, float bottom, float top, float nearPlane, float farPlane)
{
    mProjection.setToIdentity();
    mProjection.ortho(left, right, bottom, top, nearPlane, farPlane);
}

//===================================================================
void Scene::setPerspective(float verticalAngle, float aspectRatio, float nearPlane, float farPlane)
{
    mProjection.setToIdentity();
    mProjection.perspective(verticalAngle, aspectRatio, nearPlane, farPlane);
}
//===================================================================

void Scene::setDebug(bool enable)
{
    mDebug = enable;
   foreach (Mesh * mesh, meshes())
   {
       mesh->setDebug(mDebug);
   }
}

}
