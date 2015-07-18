#include "cubemesh.h"

namespace cgl {
CubeMesh::CubeMesh(QObject *parent) : Mesh(parent)
{

    addVertex(Vertex(1,1,0,Qt::red));
    addVertex(Vertex(1,-1,0,Qt::green));
    addVertex(Vertex(-1,-1,0,Qt::blue));
    addVertex(Vertex(-1,1,0,Qt::yellow));

}

}

