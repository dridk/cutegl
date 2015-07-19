#include "planemesh.h"
namespace cgl {
PlaneMesh::PlaneMesh(QObject * parent)
    :Mesh(parent)
{




}

PlaneMesh::PlaneMesh(float top, float bottom, float left, float right, QObject *parent)
    :Mesh(parent)
{
    setRect(top,bottom,left, right);
}

void PlaneMesh::setRect(float top, float bottom, float left, float right, float z)
{

    QVector<Vertex> list;

    list.append(Vertex(QVector3D(left,top,z)));
    list.append(Vertex(QVector3D(left,bottom,z)));
    list.append(Vertex(QVector3D(right,top,z)));
    list.append(Vertex(QVector3D(right,bottom,z)));

    setVertices(list);

}



}
