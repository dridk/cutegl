#include "rectmesh.h"
namespace cgl {
RectMesh::RectMesh(QObject * parent)
    :Mesh(parent)
{




}

RectMesh::RectMesh(float x, float y, float width, float height, QObject *parent)
    :Mesh(parent)
{
    setRect(x,y,width, height);
}

void RectMesh::setRect(float x, float y, float width, float height)
{

    QVector<QVector3D> list;

    list.append(QVector3D(x,y,0));
    list.append(QVector3D(x+width,y,0));
    list.append(QVector3D(x+width,y+height,0));
    list.append(QVector3D(x,y+height,0));

    setVertices(list);

}



}
