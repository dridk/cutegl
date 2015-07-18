#ifndef SCENE_H
#define SCENE_H
#include <QtGui>
#include <QVector>
#include <QMatrix4x4>
#include <QOpenGLContext>
#include "mesh.h"
#include "view.h"
#include "axismesh.h"
namespace cgl {
/*! \class Scene
 * \brief This class manage a collection of mesh
 */
class Scene : public QObject
{
    Q_OBJECT
public:
    Scene(QObject * parent = 0);
    void addMesh(Mesh * mesh);
    void removeMesh(Mesh * mesh);
    QList<Mesh *> meshs() const;
    int count() const;

    void setContext(QOpenGLContext * context);
    QOpenGLContext * context();

    //set perspective projection
    void setPerspective(float verticalAngle, float aspectRatio, float nearPlane, float farPlane);

    // set ortho projection
    void setOrtho(float left, float right, float bottom, float top, float nearPlane, float farPlane);

    // set Camera
    void lookAt(const QVector3D & eye, const QVector3D & center, const QVector3D & up);


    // Call mesh->create() for all mesh
    void createMeshs();

    // Draw all meshs
    void draw();




private:
    QList <Mesh*> mMeshs;
    QOpenGLContext * mContext;

    QMatrix4x4 mProjection;
    QMatrix4x4 mView;
    QMatrix4x4 mModel;


};
}

#endif // SCENE_H
