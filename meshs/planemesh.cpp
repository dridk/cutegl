#include "planemesh.h"
namespace cgl {
PlaneMesh::PlaneMesh(QObject * parent)
    :Mesh(parent)
{
}

PlaneMesh::PlaneMesh(float x, float y, float width, float height, QObject * parent)
    :Mesh(parent)
{
    setRect(QRect(x,y, width, height));
}

PlaneMesh::PlaneMesh(const QRectF &rect, QObject *parent)
{
    setRect(rect);
}

void PlaneMesh::setRect(const QRectF &rect)
{
    mRect  = rect ;
    makeMesh();

}



void PlaneMesh::makeMesh()
{

    clearVertices();
    addVertex(Vertex(mRect.left() , mRect.top(),0,     0,0, 1,1,1));
    addVertex(Vertex(mRect.right(), mRect.top(),0,     1,0, 1,1,1));
    addVertex(Vertex(mRect.left() , mRect.bottom(),0,  0,1, 1,1,1));
    addVertex(Vertex(mRect.right() , mRect.bottom(),0,  1,1, 1,1,1));


}



}
