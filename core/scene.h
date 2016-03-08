#ifndef SCENE_H
#define SCENE_H

#include <QObject>

#include "camera.h"
#include "light.h"
#include "mesh.h"

class QOpenGLContext;
class QOpenGLTexture;

namespace cgl {
class Scene : public QObject
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = 0);
    ~Scene() { delete mCamera; }
    void         addMesh(Mesh *mesh) { mMeshes.append(mesh); }
    void         addLight(Light* light) { mLights.append(light);}
    Camera       *camera() const { return mCamera; }
    void         createMeshes();
    void         draw();
    bool         isDebug(){ return mDebug; }
    void         lookAt(const QVector3D &eye, const QVector3D &center, const QVector3D &up);
    QList<Mesh*> meshes() const { return mMeshes; }
    QMatrix4x4   projectionMatrix() const {return mProjection; }
    void         scale(float updown);
    void         setContext(QOpenGLContext *context) { mContext = context; } // replace by currentContext static ?
    void         setDebug(bool enable = true);
    void         setOrtho(float left, float right, float bottom, float top, float nearPlane, float farPlane);
    void         setPerspective(float verticalAngle, float aspectRatio, float nearPlane, float farPlane);
    QMatrix4x4   viewMatrix() const { return mView; }
    QString      whereIs(QVector3D pointer) const;

    Camera         *mCamera;      // the camera looking at the scene
    QOpenGLContext *mContext;    // the OpenGL context of the scene
    bool           mDebug;       // debug mode allowing to view normals to mesh
    QList<Mesh*>   mMeshes;      // list of meshes
    QList<Light*>  mLights;      // List of light.. Currently works only with one
    QMatrix4x4     mProjection;  // projection mtrix
    QMatrix4x4     mView;        // view matrix
};
}
#endif // SCENE_H
