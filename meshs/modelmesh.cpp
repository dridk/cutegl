#include "modelmesh.h"

namespace cgl {

ModelMesh::ModelMesh(const QString &filename, QObject *parent)
    :Mesh(parent)
{
    setModel(filename);
}

void ModelMesh::setModel(const QString &filename)
{

    mLoader.load(filename);
    makeMesh();

}

void ModelMesh::makeMesh()
{
    addVertex(mLoader.vertices());

}


}
