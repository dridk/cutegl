#include <qmath.h>
#include "parallelogrammesh.h"
#include "trianglemesh.h"
namespace cgl {
//=====================================================================================
ParallelogramMesh::ParallelogramMesh(QObject *parent) : Mesh(parent),
    mHeight(0.0), mSlant(0.0), mWidth(0.0)
{
    // ctor
}

//=====================================================================================
ParallelogramMesh::ParallelogramMesh(double width, double height, double angle, QObject *parent) :
    Mesh(parent), mAngle(angle), mHeight(height),  mWidth(width)
{
    // ctor
    mSlant =  qTan(qDegreesToRadians(90.0 -mAngle));
    makeMesh();
}

//=====================================================================================
void ParallelogramMesh::makeMesh()
{
    // calculates vertices

    TriangleMesh rect(mWidth, mHeight, TriangleMesh::GEN, -1 + mSlant);
    Vertex vt1 = rect.vertex(0);
    Vertex vt2 = rect.vertex(1);
    Vertex vt3 = rect.vertex(2);

    Vertex vr1(vt1.x(), vt1.y(), vt1.z(), 0, 0);
    Vertex vr2(vt2.x(), vt2.y(), vt2.z(), 1, 0);
    Vertex vr3(vt3.x(), vt3.y(), vt3.z(), 0, 1);
    addVertex(vr1);
    addVertex(vr2);
    addVertex(vr3);
    Vertex vr4(vr2.x(),          vr2.y(), vr2.z(), 1, 0);
    Vertex vr5(vr2.x() + mSlant, vr3.y(), vr1.z(), 1, 1);
    Vertex vr6(vr3.x(),          vr3.y(), vr1.z(), 0, 1);
    addVertex(vr4);
    addVertex(vr5);
    addVertex(vr6);
}
}
