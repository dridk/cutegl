#include "cubemesh.h"

namespace cgl {
CubeMesh::CubeMesh(QObject *parent) : Mesh(parent)
{

    setMode(GL_TRIANGLES);

    setTexture(QImage(":/textures/wood.jpg"));



    addVertex(Vertex( 1.0f, 1.0f,-1.0f,Qt::red,    QPointF(0,0)));
    addVertex(Vertex(-1.0f,1.0f,-1.0f,Qt::red,     QPointF(0,1)));
    addVertex(Vertex( -1.0f, -1.0f,-1.0f,Qt::red,  QPointF(1,1)));
    addVertex(Vertex( 1.0f, 1.0f,-1.0f,Qt::red,    QPointF(1,1)));
    addVertex(Vertex(1.0f,-1.0f,-1.0f,Qt::red,     QPointF(1,0)));
    addVertex(Vertex( -1.0f, -1.0f,-1.0f,Qt::red,  QPointF(0,0)));

    addVertex(Vertex( 1.0f, 1.0f,1.0f,Qt::blue,    QPointF(1,1)));
    addVertex(Vertex(-1.0f,1.0f,1.0f,Qt::blue,     QPointF(0,1)));
    addVertex(Vertex( -1.0f, -1.0f,1.0f,Qt::blue,  QPointF(0,0)));
    addVertex(Vertex( 1.0f, 1.0f,1.0f,Qt::blue,    QPointF(1,1)));
    addVertex(Vertex(1.0f,-1.0f,1.0f,Qt::blue,     QPointF(1,0)));
    addVertex(Vertex( -1.0f, -1.0f,1.0f,Qt::blue,  QPointF(0,0)));

    addVertex(Vertex( 1.0f, 1.0f,1.0f,Qt::yellow,  QPointF(1,1)));
    addVertex(Vertex(-1.0f,1.0f,1.0f,Qt::yellow,   QPointF(0,1)));
    addVertex(Vertex( -1.0f,1.0f,-1.0f,Qt::yellow, QPointF(0,0)));
    addVertex(Vertex( 1.0f, 1.0f,1.0f,Qt::yellow,  QPointF(1,1)));
    addVertex(Vertex(1.0f,1.0f,-1.0f,Qt::yellow,   QPointF(1,0)));
    addVertex(Vertex( -1.0f,1.0f,-1.0f,Qt::yellow, QPointF(0,0)));

    addVertex(Vertex( 1.0f, -1.0f,1.0f,Qt::cyan,   QPointF(1,1)));
    addVertex(Vertex(-1.0f,-1.0f,1.0f,Qt::cyan,    QPointF(0,1)));
    addVertex(Vertex( -1.0f,-1.0f,-1.0f,Qt::cyan,  QPointF(0,0)));
    addVertex(Vertex( 1.0f, -1.0f,1.0f,Qt::cyan,   QPointF(1,0)));
    addVertex(Vertex(1.0f,-1.0f,-1.0f,Qt::cyan,    QPointF(1,0)));
    addVertex(Vertex( -1.0f,-1.0f,-1.0f,Qt::cyan,  QPointF(0,1)));

    addVertex(Vertex(1.0f, 1.0f,1.0f,Qt::green,    QPointF(1,1)));
    addVertex(Vertex(1.0f,-1.0f,1.0f,Qt::green,    QPointF(0,1)));
    addVertex(Vertex(1.0f,-1.0f,-1.0f,Qt::green,   QPointF(0,0)));
    addVertex(Vertex(1.0f, 1.0f,1.0f,Qt::green,    QPointF(1,1)));
    addVertex(Vertex(1.0f,1.0f,-1.0f,Qt::green,    QPointF(1,0)));
    addVertex(Vertex(1.0f,-1.0f,-1.0f,Qt::green,   QPointF(0,0)));

    addVertex(Vertex(-1.0f, 1.0f,1.0f,Qt::magenta, QPointF(1,1)));
    addVertex(Vertex(-1.0f,-1.0f,1.0f,Qt::magenta, QPointF(0,1)));
    addVertex(Vertex(-1.0f,-1.0f,-1.0f,Qt::magenta,QPointF(0,0)));
    addVertex(Vertex(-1.0f, 1.0f,1.0f,Qt::magenta, QPointF(1,0)));
    addVertex(Vertex(-1.0f,1.0f,-1.0f,Qt::magenta, QPointF(1,0)));
    addVertex(Vertex(-1.0f,-1.0f,-1.0f,Qt::magenta,QPointF(0,1)));










//    addVertex(Vertex( 1.0f, 1.0f,1.0f,Qt::blue));
//    addVertex(Vertex(-1.0f,1.0f,1.0f,Qt::blue));
//    addVertex(Vertex( -1.0f, -1.0f,1.0f,Qt::blue));
//    addVertex(Vertex( 1.0f, 1.0f,1.0f,Qt::blue));
//    addVertex(Vertex(1.0f,-1.0f,1.0f,Qt::blue));
//    addVertex(Vertex( -1.0f, -1.0f,1.0f,Qt::blue));

//    addVertex(Vertex( 1.0f, 1.0f,1.0f,Qt::yellow));
//    addVertex(Vertex(-1.0f,1.0f,1.0f,Qt::yellow));
//    addVertex(Vertex( -1.0f,1.0f,-1.0f,Qt::yellow));
//    addVertex(Vertex( 1.0f, 1.0f,1.0f,Qt::yellow));
//    addVertex(Vertex(1.0f,1.0f,-1.0f,Qt::yellow));
//    addVertex(Vertex( -1.0f,1.0f,-1.0f,Qt::yellow));

//    addVertex(Vertex( 1.0f, -1.0f,1.0f,Qt::cyan));
//    addVertex(Vertex(-1.0f,-1.0f,1.0f,Qt::cyan));
//    addVertex(Vertex( -1.0f,-1.0f,-1.0f,Qt::cyan));
//    addVertex(Vertex( 1.0f, -1.0f,1.0f,Qt::cyan));
//    addVertex(Vertex(1.0f,-1.0f,-1.0f,Qt::cyan));
//    addVertex(Vertex( -1.0f,-1.0f,-1.0f,Qt::cyan));

//    addVertex(Vertex(1.0f, 1.0f,1.0f,Qt::green));
//    addVertex(Vertex(1.0f,-1.0f,1.0f,Qt::green));
//    addVertex(Vertex(1.0f,-1.0f,-1.0f,Qt::green));
//    addVertex(Vertex(1.0f, 1.0f,1.0f,Qt::green));
//    addVertex(Vertex(1.0f,1.0f,-1.0f,Qt::green));
//    addVertex(Vertex(1.0f,-1.0f,-1.0f,Qt::green));

//    addVertex(Vertex(-1.0f, 1.0f,1.0f,Qt::magenta));
//    addVertex(Vertex(-1.0f,-1.0f,1.0f,Qt::magenta));
//    addVertex(Vertex(-1.0f,-1.0f,-1.0f,Qt::magenta));
//    addVertex(Vertex(-1.0f, 1.0f,1.0f,Qt::magenta));
//    addVertex(Vertex(-1.0f,1.0f,-1.0f,Qt::magenta));
//    addVertex(Vertex(-1.0f,-1.0f,-1.0f,Qt::magenta));


}



}


