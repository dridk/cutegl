#ifndef SCENE_H
#define SCENE_H
#include <QtGui>
#include <QVector>
#include <QMatrix4x4>
#include <QOpenGLContext>
#include "mesh.h"
#include "view.h"

namespace cgl {
class Scene : public QObject
{
    Q_OBJECT
public:
    Scene(QObject * parent = 0);
    void addMesh(Mesh * mesh);
    void removeMesh(Mesh * mesh);
    QList<Mesh *> meshs() const;

    void setContext(QOpenGLContext * context);
    QOpenGLContext * context();

    void createMeshs();
    void draw();
    void setPerspective(float verticalAngle, float aspectRatio, float nearPlane, float farPlane);


private:
    QList <Mesh*> mMeshs;
    QOpenGLContext * mContext;

    QMatrix4x4 mProjection;
    QMatrix4x4 mCamera;
};
}

#endif // SCENE_H
