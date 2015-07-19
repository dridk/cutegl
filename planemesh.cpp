#include "planemesh.h"
namespace cgl {
PlaneMesh::PlaneMesh(QObject * parent)
    :Mesh(parent)
{

setMode(GL_TRIANGLES);


}

PlaneMesh::PlaneMesh(float top, float bottom, float left, float right, QObject *parent)
    :Mesh(parent)
{
    setRect(top,bottom,left, right);
}

void PlaneMesh::setRect(float top, float bottom, float left, float right, float z)
{

    QVector<Vertex> vertices;

    vertices.append(Vertex(QVector3D(0.5,0.5,0)));
    vertices.append(Vertex(QVector3D(0.5,-0.5,0)));
    vertices.append(Vertex(QVector3D(-0.5,-0.5,0)));
    vertices.append(Vertex(QVector3D(-0.5,0.5,0)));

    setVertices(vertices);


    QVector<GLuint> ids;
    ids<<0<<1<<3<<1<<2<<3;

    setIndexes(ids);
}



}
