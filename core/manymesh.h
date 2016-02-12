#ifndef MANYMESH_H
#define MANYMESH_H

#include <QObject>

#include "mesh.h"
namespace cgl {

class ManyMesh : public QObject
{
    Q_OBJECT

public:
    ManyMesh(Mesh *mesh, QObject * parent = 0);
    ~ManyMesh();

    void add(Mesh * mesh) { mMeshes.append(mesh); }

private:
    QVector<Mesh *>   mMeshes; //list of mesh objects
};
}
#endif // MANYMESH_H
