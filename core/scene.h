#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <mesh.h>

class QOpenGLContext;
class QOpenGLTexture;

namespace cgl {
class Scene : public QObject
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = 0);

    void         addMesh(Mesh *mesh) { mMeshes.append(mesh); }
    void         createMeshes();
    void         draw();
    void         lookAt(const QVector3D &eye, const QVector3D &center, const QVector3D &up);
    QList<Mesh*> meshes() const { return mMeshes; }
    void         setContext(QOpenGLContext *context) { mContext = context; }
    void         setOrtho(float left, float right, float bottom, float top, float nearPlane, float farPlane);
    void         setPerspective(float verticalAngle, float aspectRatio, float nearPlane, float farPlane);
    
private:
    QOpenGLContext *mContext;   // the OpenGL context of the scene
    QList<Mesh*>   mMeshes;     // list of meshes
    QMatrix4x4     mProjection; // projection mtrix
    QMatrix4x4     mView;       // view matrix 
    
    QOpenGLTexture *testTExture;
};
}
#endif // SCENE_H
