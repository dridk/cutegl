#include "cubemesh.h"

namespace cgl {
CubeMesh::CubeMesh(QObject *parent) : Mesh(parent)
{

    setMode(GL_TRIANGLES);

    setTexture(QImage(":/textures/wood.jpg"));

    addVertex(Vertex(QVector3D( 1.0f, 1.0f,-1.0f),QVector3D(0,0,0),    QVector2D(0,0),Qt::red));
    addVertex(Vertex(QVector3D(-1.0f,1.0f,-1.0f),QVector3D(0,0,0),     QVector2D(0,1),Qt::red));
    addVertex(Vertex(QVector3D( -1.0f, -1.0f,-1.0f),QVector3D(0,0,0),  QVector2D(1,1),Qt::red));
    addVertex(Vertex(QVector3D( 1.0f, 1.0f,-1.0f),QVector3D(0,0,0),    QVector2D(1,1),Qt::red));
    addVertex(Vertex(QVector3D(1.0f,-1.0f,-1.0f),QVector3D(0,0,0),     QVector2D(1,0),Qt::red));
    addVertex(Vertex(QVector3D( -1.0f, -1.0f,-1.0f),QVector3D(0,0,0),  QVector2D(0,0),Qt::red));

    addVertex(Vertex(QVector3D( 1.0f, 1.0f,1.0f),QVector3D(0,0,0),    QVector2D(1,1),Qt::green));
    addVertex(Vertex(QVector3D(-1.0f,1.0f,1.0f),QVector3D(0,0,0),     QVector2D(0,1),Qt::green));
    addVertex(Vertex(QVector3D( -1.0f, -1.0f,1.0f),QVector3D(0,0,0),  QVector2D(0,0),Qt::green));
    addVertex(Vertex(QVector3D( 1.0f, 1.0f,1.0f),QVector3D(0,0,0),    QVector2D(1,1),Qt::green));
    addVertex(Vertex(QVector3D(1.0f,-1.0f,1.0f),QVector3D(0,0,0),     QVector2D(1,0),Qt::green));
    addVertex(Vertex(QVector3D( -1.0f, -1.0f,1.0f),QVector3D(0,0,0),  QVector2D(0,0),Qt::green));

    addVertex(Vertex(QVector3D( 1.0f, 1.0f,1.0f),QVector3D(0,0,0),  QVector2D(1,1),Qt::blue));
    addVertex(Vertex(QVector3D(-1.0f,1.0f,1.0f),QVector3D(0,0,0),   QVector2D(0,1),Qt::blue));
    addVertex(Vertex(QVector3D( -1.0f,1.0f,-1.0f),QVector3D(0,0,0), QVector2D(0,0),Qt::blue));
    addVertex(Vertex(QVector3D( 1.0f, 1.0f,1.0f),QVector3D(0,0,0),  QVector2D(1,1),Qt::blue));
    addVertex(Vertex(QVector3D(1.0f,1.0f,-1.0f),QVector3D(0,0,0),   QVector2D(1,0),Qt::blue));
    addVertex(Vertex(QVector3D( -1.0f,1.0f,-1.0f),QVector3D(0,0,0), QVector2D(0,0),Qt::blue));

    addVertex(Vertex(QVector3D( 1.0f, -1.0f,1.0f),QVector3D(0,0,0),   QVector2D(1,1),Qt::yellow));
    addVertex(Vertex(QVector3D(-1.0f,-1.0f,1.0f),QVector3D(0,0,0),    QVector2D(0,1),Qt::yellow));
    addVertex(Vertex(QVector3D( -1.0f,-1.0f,-1.0f),QVector3D(0,0,0),  QVector2D(0,0),Qt::yellow));
    addVertex(Vertex(QVector3D( 1.0f, -1.0f,1.0f),QVector3D(0,0,0),   QVector2D(1,0),Qt::yellow));
    addVertex(Vertex(QVector3D(1.0f,-1.0f,-1.0f),QVector3D(0,0,0),    QVector2D(1,0),Qt::yellow));
    addVertex(Vertex(QVector3D( -1.0f,-1.0f,-1.0f),QVector3D(0,0,0),  QVector2D(0,1),Qt::yellow));

    addVertex(Vertex(QVector3D(1.0f, 1.0f,1.0f),QVector3D(0,0,0),    QVector2D(1,1),Qt::cyan));
    addVertex(Vertex(QVector3D(1.0f,-1.0f,1.0f),QVector3D(0,0,0),    QVector2D(0,1),Qt::cyan));
    addVertex(Vertex(QVector3D(1.0f,-1.0f,-1.0f),QVector3D(0,0,0),   QVector2D(0,0),Qt::cyan));
    addVertex(Vertex(QVector3D(1.0f, 1.0f,1.0f),QVector3D(0,0,0),    QVector2D(1,1),Qt::cyan));
    addVertex(Vertex(QVector3D(1.0f,1.0f,-1.0f),QVector3D(0,0,0),    QVector2D(1,0),Qt::cyan));
    addVertex(Vertex(QVector3D(1.0f,-1.0f,-1.0f),QVector3D(0,0,0),   QVector2D(0,0),Qt::cyan));

    addVertex(Vertex(QVector3D(-1.0f, 1.0f,1.0f),QVector3D(0,0,0), QVector2D(1,1),Qt::magenta));
    addVertex(Vertex(QVector3D(-1.0f,-1.0f,1.0f),QVector3D(0,0,0), QVector2D(0,1),Qt::magenta));
    addVertex(Vertex(QVector3D(-1.0f,-1.0f,-1.0f),QVector3D(0,0,0),QVector2D(0,0),Qt::magenta));
    addVertex(Vertex(QVector3D(-1.0f, 1.0f,1.0f),QVector3D(0,0,0), QVector2D(1,0),Qt::magenta));
    addVertex(Vertex(QVector3D(-1.0f,1.0f,-1.0f),QVector3D(0,0,0), QVector2D(1,0),Qt::magenta));
    addVertex(Vertex(QVector3D(-1.0f,-1.0f,-1.0f),QVector3D(0,0,0),QVector2D(0,1),Qt::magenta));







}



}


