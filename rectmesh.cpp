#include "rectmesh.h"
namespace cgl {
RectMesh::RectMesh(QObject * parent)
    :Mesh(parent)
{




}

RectMesh::RectMesh(float top, float bottom, float left, float right, QObject *parent)
    :Mesh(parent)
{
    setRect(top,bottom,left, right);
}

void RectMesh::setRect(float top, float bottom, float left, float right, float z)
{

//    QVector<Vert> list;

//    list.append(QVector3D(left,top,z));
//    list.append(QVector3D(left,bottom,z));
//    list.append(QVector3D(right,top,z));
//    list.append(QVector3D(right,bottom,z));

//    setVertices(list);

}



}
