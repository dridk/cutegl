#include "modelmesh.h"

namespace cgl {

ModelMesh::ModelMesh(const QString &filename, QObject *parent)
    :Mesh(parent)
{

    setMode(GL_LINES);
    setTexture(QImage(":/textures/wood.jpg"));

    setModel(filename);

}

void ModelMesh::setModel(const QString &filename)
{

    mLoader.load(filename);
    setVertices(mLoader.vertices());

}


}
