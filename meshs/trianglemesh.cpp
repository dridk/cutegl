#include <QDebug>

#include "trianglemesh.h"
#include "vertex.h"
namespace cgl {
//=====================================================================================
TriangleMesh::TriangleMesh(QObject *parent) : Mesh(parent),  mB(0.0), mH(0.0), mXc(0.0)
{
    //ctor
}

//=====================================================================================
TriangleMesh::TriangleMesh(double b, double h, TriangleType type, double xc, QObject *parent) :
    Mesh(parent), mB(b), mH(h), mType(type), mXc(xc)
{
 // define a triangle with base width = b and height =h

    Cdg();
    makeMesh();
}

//=====================================================================================
void TriangleMesh::makeMesh()
{
    // Calculate the vertices for the triangle: centered at (0,0)
    Vertex v3;
    Vertex v1(-1, -1, 0.0, 0.0, 0.0);
    Vertex v2( 1, -1, 0.0, 1.0, 0.0);
    switch (mType) {
    case ISOC:
        v3.setX(0.0);
        v3.setY(1);
        v3.setZ(0.0);
        v3.setU(0.5);
        v3.setV(1.0);
        break;
    case RECT:
        v3.setX(-1);
        v3.setY(1);
        v3.setZ(0.0);
        v3.setU(0.5);
        v3.setV(1.0);
        break;
    case GEN:
        v3.setX(mXc);
        v3.setY(1);
        v3.setZ(0.0);
        v3.setU(0.5);
        v3.setV(1.0);
        break;
    default:
        break;
    }
    addVertex(v1);
    addVertex(v2);
    addVertex(v3);

}

//=====================================================================================
void TriangleMesh::Cdg()
{
    // calculates center of gravity
    double num =  2 * mH / mB / (mXc - mB / 2.0) - mB * mH / (mXc - 2.0 * mB);
    double den = mH / (mXc - mB / 2.0) - mH / (mXc - 2.0 * mB);
    mXg = num / den;
    mYg = mH * mXg / (mXc - 2.0 * mB) - mB * mH / (mXc - 2.0 * mB);
}
}
