#include "cubemesh.h"

namespace cgl {
CubeMesh::CubeMesh(QObject *parent) : Mesh(parent)
{

    setMode(GL_TRIANGLES);

    setTexture(QImage(":/textures/wood.jpg"));



    addVertex(Vertex( 1.0f, 1.0f,-1.0f,Qt::red,    QVector2D(0,0)));
    addVertex(Vertex(-1.0f,1.0f,-1.0f,Qt::red,     QVector2D(0,1)));
    addVertex(Vertex( -1.0f, -1.0f,-1.0f,Qt::red,  QVector2D(1,1)));
    addVertex(Vertex( 1.0f, 1.0f,-1.0f,Qt::red,    QVector2D(1,1)));
    addVertex(Vertex(1.0f,-1.0f,-1.0f,Qt::red,     QVector2D(1,0)));
    addVertex(Vertex( -1.0f, -1.0f,-1.0f,Qt::red,  QVector2D(0,0)));

    addVertex(Vertex( 1.0f, 1.0f,1.0f,Qt::blue,    QVector2D(1,1)));
    addVertex(Vertex(-1.0f,1.0f,1.0f,Qt::blue,     QVector2D(0,1)));
    addVertex(Vertex( -1.0f, -1.0f,1.0f,Qt::blue,  QVector2D(0,0)));
    addVertex(Vertex( 1.0f, 1.0f,1.0f,Qt::blue,    QVector2D(1,1)));
    addVertex(Vertex(1.0f,-1.0f,1.0f,Qt::blue,     QVector2D(1,0)));
    addVertex(Vertex( -1.0f, -1.0f,1.0f,Qt::blue,  QVector2D(0,0)));

    addVertex(Vertex( 1.0f, 1.0f,1.0f,Qt::yellow,  QVector2D(1,1)));
    addVertex(Vertex(-1.0f,1.0f,1.0f,Qt::yellow,   QVector2D(0,1)));
    addVertex(Vertex( -1.0f,1.0f,-1.0f,Qt::yellow, QVector2D(0,0)));
    addVertex(Vertex( 1.0f, 1.0f,1.0f,Qt::yellow,  QVector2D(1,1)));
    addVertex(Vertex(1.0f,1.0f,-1.0f,Qt::yellow,   QVector2D(1,0)));
    addVertex(Vertex( -1.0f,1.0f,-1.0f,Qt::yellow, QVector2D(0,0)));

    addVertex(Vertex( 1.0f, -1.0f,1.0f,Qt::cyan,   QVector2D(1,1)));
    addVertex(Vertex(-1.0f,-1.0f,1.0f,Qt::cyan,    QVector2D(0,1)));
    addVertex(Vertex( -1.0f,-1.0f,-1.0f,Qt::cyan,  QVector2D(0,0)));
    addVertex(Vertex( 1.0f, -1.0f,1.0f,Qt::cyan,   QVector2D(1,0)));
    addVertex(Vertex(1.0f,-1.0f,-1.0f,Qt::cyan,    QVector2D(1,0)));
    addVertex(Vertex( -1.0f,-1.0f,-1.0f,Qt::cyan,  QVector2D(0,1)));

    addVertex(Vertex(1.0f, 1.0f,1.0f,Qt::green,    QVector2D(1,1)));
    addVertex(Vertex(1.0f,-1.0f,1.0f,Qt::green,    QVector2D(0,1)));
    addVertex(Vertex(1.0f,-1.0f,-1.0f,Qt::green,   QVector2D(0,0)));
    addVertex(Vertex(1.0f, 1.0f,1.0f,Qt::green,    QVector2D(1,1)));
    addVertex(Vertex(1.0f,1.0f,-1.0f,Qt::green,    QVector2D(1,0)));
    addVertex(Vertex(1.0f,-1.0f,-1.0f,Qt::green,   QVector2D(0,0)));

    addVertex(Vertex(-1.0f, 1.0f,1.0f,Qt::magenta, QVector2D(1,1)));
    addVertex(Vertex(-1.0f,-1.0f,1.0f,Qt::magenta, QVector2D(0,1)));
    addVertex(Vertex(-1.0f,-1.0f,-1.0f,Qt::magenta,QVector2D(0,0)));
    addVertex(Vertex(-1.0f, 1.0f,1.0f,Qt::magenta, QVector2D(1,0)));
    addVertex(Vertex(-1.0f,1.0f,-1.0f,Qt::magenta, QVector2D(1,0)));
    addVertex(Vertex(-1.0f,-1.0f,-1.0f,Qt::magenta,QVector2D(0,1)));










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


