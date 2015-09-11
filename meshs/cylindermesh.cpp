#include <qmath.h>
#include "cylindermesh.h"
namespace cgl {
//===================================================================
CylinderMesh::CylinderMesh(QObject *parent) : Mesh(parent),
    mLength(0.0), mRadius(0.0), mSeg(0)
{

}

//===================================================================
CylinderMesh::CylinderMesh(float radius, int nseg, float length, QObject *parent) : Mesh(parent),
    mLength(length), mRadius(radius), mSeg(nseg)
{
    // ctor

    setObjectName("Cylinder");

    makeMesh();

}

//===================================================================
void CylinderMesh::makeMesh()
{
    // calculates the vertices of the mesh

    float angStep = qDegreesToRadians(360. / mSeg);
    float ang = 0.0;

    for(int count = 0; count < mSeg; count++) {
        addVertex(Vertex(mRadius * qCos(ang          ), mRadius * qSin(ang          ),  mLength / 2.0, 0.0, (ang           ) / M_PI / 2)); //0
        addVertex(Vertex(mRadius * qCos(ang          ), mRadius * qSin(ang          ), -mLength / 2.0, 1.0, (ang           ) / M_PI / 2)); //1
        addVertex(Vertex(mRadius * qCos(ang + angStep), mRadius * qSin(ang + angStep),  mLength / 2.0, 0.0, (ang + angStep ) / M_PI / 2)); //2

        addVertex(Vertex(mRadius * qCos(ang          ), mRadius * qSin(ang          ), -mLength / 2.0, 1.0, (ang           ) / M_PI / 2)); //3
        addVertex(Vertex(mRadius * qCos(ang + angStep), mRadius * qSin(ang + angStep), -mLength / 2.0, 1.0, (ang + angStep ) / M_PI / 2)); //4
        addVertex(Vertex(mRadius * qCos(ang + angStep), mRadius * qSin(ang + angStep),  mLength / 2.0, 0.0, (ang + angStep ) / M_PI / 2)); //5
        ang += angStep;
    }

    computeNormal();
}
}
