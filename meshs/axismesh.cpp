#include "axismesh.h"

namespace cgl {

AxisMesh::AxisMesh(QObject *parent) :
    Mesh(parent)
{

    setMode(GL_LINES);
    mFactor = 10;


    addVertex(Vertex(0,0,0,Qt::red));
    addVertex(Vertex(0,0,1*mFactor,Qt::red));

    addVertex(Vertex(0,0,0,Qt::green));
    addVertex(Vertex(0,1*mFactor,0,Qt::green));

    addVertex(Vertex(0,0,0,Qt::blue));
    addVertex(Vertex(1*mFactor,0,0,Qt::blue));

}


}
