#include "modelmesh.h"

namespace cgl {

//===================================================================
ModelMesh::ModelMesh(const QString &filename, QObject *parent)
    :Mesh(parent)
{
    // ctor
    setModel(filename);
}

//===================================================================
void ModelMesh::setModel(const QString &filename)
{
    // set the model file name and make the mesh
    mLoader.load(filename);
    makeMesh();
}

//===================================================================
void ModelMesh::makeMesh()
{
    // make the mesh from the vertices
    addVertex(mLoader.vertices());
}
}
