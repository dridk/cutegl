#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include "mesh.h"
#include "light.h"

class QOpenGLContext;
class QOpenGLTexture;

namespace cgl {
class Scene : public QObject
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = 0);

    void         addMesh(Mesh *mesh) { mMeshes.append(mesh); }
    void         addLight(Light* light) { mLights.append(light);}
    void         createMeshes();
    void         draw();
    void         lookAt(const QVector3D &eye, const QVector3D &center, const QVector3D &up);
    QList<Mesh*> meshes() const { return mMeshes; }
    void         setContext(QOpenGLContext *context) { mContext = context; } // replace by currentContext static ?
    void         setOrtho(float left, float right, float bottom, float top, float nearPlane, float farPlane);
    void         setPerspective(float verticalAngle, float aspectRatio, float nearPlane, float farPlane);
    void         setDebugView(bool enable = true);


    QOpenGLContext *mContext;   // the OpenGL context of the scene
    QList<Mesh*>   mMeshes;     // list of meshes
    QList<Light*>  mLights;     // List of light.. Currently works only with one
    QMatrix4x4     mProjection; // projection mtrix
    QMatrix4x4     mView;       // view matrix 

    
    QOpenGLTexture *testTExture;
};
}
#endif // SCENE_H
