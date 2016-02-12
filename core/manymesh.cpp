#include "manymesh.h"
namespace cgl {

//===================================================================
ManyMesh::ManyMesh(Mesh *mesh, QObject *parent)
{
    // ctor, adds the first mesh object to the list

    mMeshes.append(mesh);
}

//===================================================================
ManyMesh::~ManyMesh()
{
    qDeleteAll(mMeshes);
}
}
