#include "trianglemesh.h"

namespace cgl {

TriangleMesh::TriangleMesh(double b, double h, TriangleMesh::TriangleType type, double xc, QObject *parent) :
    Mesh(parent), mB(b), mH(h), mType(type), mXc(xc)
{
   // Calculate the vertices for the triangle: centered at (0,0)

//    setMode(GL_TRIANGLES);

//    setTexture(QImage(":/textures/wood.jpg"));
//    Vertex v1, v2, v3;
//    v1.setCoord(QVector3D(-1.0, -1.0, 0.0));
//    v1.setNormal(QVector3D(0.0 ,0.0 ,0.0));
//    v1.setTexCoord(QVector2D(0.0, 0.0));
//    v1.setColor(Qt::red);
//    v2.setCoord(QVector3D( 1.0, -1.0, 0.0));
//    v2.setNormal(QVector3D(0.0 ,0.0 ,0.0));
//    v2.setTexCoord(QVector2D(1.0, 0.0));
//    v2.setColor(Qt::red);
//    switch (mType) {
//    case ISOC:
//        v3.setCoord(QVector3D(0.0, 1.0, 0.0));
//        v3.setNormal(QVector3D(0.0 ,0.0 ,0.0));
//        v3.setTexCoord(QVector2D(0.5, 1.0));
//        v3.setColor(Qt::red);
//        break;
//    case RECT:
//        v3.setCoord(QVector3D(-1.0, 1.0, 0.0));
//        v3.setNormal(QVector3D(0.0 ,0.0 ,0.0));
//        v3.setTexCoord(QVector2D(0.5, 1.0));
//        v3.setColor(Qt::red);
//        break;
//    case GEN:
//        v3.setCoord(QVector3D(mXc, 1.0, 0.0));
//        v3.setNormal(QVector3D(0.0 ,0.0 ,0.0));
//        v3.setTexCoord(QVector2D(0.5, 1.0));
//        v3.setColor(Qt::red);
//        break;
//    default:
//        break;
//    }
//    addVertex(v1);
//    addVertex(v2);
//    addVertex(v3);

//    mPolygon.append(QPointF(v1.x(), v1.y()));
//    mPolygon.append(QPointF(v2.x(), v2.y()));
//    mPolygon.append(QPointF(v3.x(), v3.y()));

}

const QPolygonF &TriangleMesh::toPolygon() const
{
 return mPolygon;
}

void TriangleMesh::computeGravityCenter()
{
    // calculates center of gravity
    double num =  2 * mH / mB / (mXc - mB / 2.0) - mB * mH / (mXc - 2.0 * mB);
    double den = mH / (mXc - mB / 2.0) - mH / (mXc - 2.0 * mB);
    mGravityCenter.setX(num / den);
    mGravityCenter.setY(mH * mGravityCenter.y() / (mXc - 2.0 * mB) - mB * mH / (mXc - 2.0 * mB));
}

}
