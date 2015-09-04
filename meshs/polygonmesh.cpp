#include <qmath.h>

#include "polygonmesh.h"
#include "vertex.h"
namespace cgl {
//===================================================================
PolygonMesh::PolygonMesh(QObject *parent) : Mesh(parent),
    mRadius(0.0), mSeg(0)
{

}

//===================================================================
PolygonMesh::PolygonMesh(float radius, int nseg, QObject *parent) : Mesh(parent),
    mRadius(radius), mSeg(nseg)

{
    // ctor

    setObjectName("Polygon");

    makeMesh();

    float angStep = qDegreesToRadians(360. / nseg);
    float ang = 0.0;
    Vertex center(0.0, 0.0, 0.0,  0.5, 0.5);
    for( int count = 0; count < nseg; count++) {
        addVertex(Vertex(radius * qCos(ang),           radius * qSin(ang),           0.0,  0.5 + 0.5 * qCos(ang),           0.5 + 0.5 * qSin(ang)));
        addVertex(Vertex(radius * qCos(ang + angStep), radius * qSin(ang + angStep), 0.0,  0.5 + 0.5 * qCos(ang + angStep), 0.5 + 0.5 * qSin(ang + angStep)));
        addVertex(center);
        ang += angStep;
    }
}

void PolygonMesh::makeMesh()
{
    // calculates the vertices of the mesh

    float angStep = qDegreesToRadians(360. / mSeg);
    float ang = 0.0;
    Vertex center(0.0, 0.0, 0.0,  0.5, 0.5);
    for( int count = 0; count < mSeg; count++) {
        addVertex(Vertex(mRadius * qCos(ang),           mRadius * qSin(ang),           0.0,  0.5 + 0.5 * qCos(ang),           0.5 + 0.5 * qSin(ang)));
        addVertex(Vertex(mRadius * qCos(ang + angStep), mRadius * qSin(ang + angStep), 0.0,  0.5 + 0.5 * qCos(ang + angStep), 0.5 + 0.5 * qSin(ang + angStep)));
        addVertex(center);
        ang += angStep;
    }
}

}
