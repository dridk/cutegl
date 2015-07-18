#include "cubemesh.h"

namespace cgl {
CubeMesh::CubeMesh(QObject *parent) : Mesh(parent)
{

    setMode(GL_TRIANGLES);

    addVertex(Vertex( 1.0f, 1.0f,-1.0f,Qt::red));
    addVertex(Vertex(-1.0f,1.0f,-1.0f,Qt::red));
    addVertex(Vertex( -1.0f, -1.0f,-1.0f,Qt::red));
    addVertex(Vertex( 1.0f, 1.0f,-1.0f,Qt::red));
    addVertex(Vertex(1.0f,-1.0f,-1.0f,Qt::red));
    addVertex(Vertex( -1.0f, -1.0f,-1.0f,Qt::red));

    addVertex(Vertex( 1.0f, 1.0f,1.0f,Qt::blue));
    addVertex(Vertex(-1.0f,1.0f,1.0f,Qt::blue));
    addVertex(Vertex( -1.0f, -1.0f,1.0f,Qt::blue));
    addVertex(Vertex( 1.0f, 1.0f,1.0f,Qt::blue));
    addVertex(Vertex(1.0f,-1.0f,1.0f,Qt::blue));
    addVertex(Vertex( -1.0f, -1.0f,1.0f,Qt::blue));

    addVertex(Vertex( 1.0f, 1.0f,1.0f,Qt::yellow));
    addVertex(Vertex(-1.0f,1.0f,1.0f,Qt::yellow));
    addVertex(Vertex( -1.0f,1.0f,-1.0f,Qt::yellow));
    addVertex(Vertex( 1.0f, 1.0f,1.0f,Qt::yellow));
    addVertex(Vertex(1.0f,1.0f,-1.0f,Qt::yellow));
    addVertex(Vertex( -1.0f,1.0f,-1.0f,Qt::yellow));

    addVertex(Vertex( 1.0f, -1.0f,1.0f,Qt::cyan));
    addVertex(Vertex(-1.0f,-1.0f,1.0f,Qt::cyan));
    addVertex(Vertex( -1.0f,-1.0f,-1.0f,Qt::cyan));
    addVertex(Vertex( 1.0f, -1.0f,1.0f,Qt::cyan));
    addVertex(Vertex(1.0f,-1.0f,-1.0f,Qt::cyan));
    addVertex(Vertex( -1.0f,-1.0f,-1.0f,Qt::cyan));

    addVertex(Vertex(1.0f, 1.0f,1.0f,Qt::green));
    addVertex(Vertex(1.0f,-1.0f,1.0f,Qt::green));
    addVertex(Vertex(1.0f,-1.0f,-1.0f,Qt::green));
    addVertex(Vertex(1.0f, 1.0f,1.0f,Qt::green));
    addVertex(Vertex(1.0f,1.0f,-1.0f,Qt::green));
    addVertex(Vertex(1.0f,-1.0f,-1.0f,Qt::green));

    addVertex(Vertex(-1.0f, 1.0f,1.0f,Qt::magenta));
    addVertex(Vertex(-1.0f,-1.0f,1.0f,Qt::magenta));
    addVertex(Vertex(-1.0f,-1.0f,-1.0f,Qt::magenta));
    addVertex(Vertex(-1.0f, 1.0f,1.0f,Qt::magenta));
    addVertex(Vertex(-1.0f,1.0f,-1.0f,Qt::magenta));
    addVertex(Vertex(-1.0f,-1.0f,-1.0f,Qt::magenta));


}



}



