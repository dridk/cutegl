#include <qmath.h>
#include "annulusmesh.h"
#include "polygonmesh.h"
namespace cgl {
//===================================================================
AnnulusMesh::AnnulusMesh(QObject *parent) : Mesh(parent),
    mRin(0.0), mRou(0.0), mSeg(0.0)
{

}

//===================================================================
AnnulusMesh::AnnulusMesh(float rou, float rin, int nseg, QObject *parent) : Mesh(parent),
    mRin(rin), mRou(rou), mSeg(nseg)
{
    // ctor

    setObjectName("Annulus");

    if (rou < rin) {
        qWarning("Annulus::Annulus: outer radius must be larger than inner radius");
        exit(QtWarningMsg);
    }

    makeMesh();
}

//===================================================================
void AnnulusMesh::makeMesh()
{
    // calculates the vertices of the mesh

    PolygonMesh polOu(mRou, mSeg, this);
    PolygonMesh polIn(mRin, mSeg, this);

    float angStep = qDegreesToRadians(360. / mSeg);
    float ang = 0.0;

    int index = 0;

    for (int count = 0; count < polOu.verticesCount() / 3; count++) {
        addVertex(polOu.vertices().at(index));
        addVertex(polOu.vertices().at(index+1));
        polIn.vertex(index).setU(0.5 + mRin/mRou * 0.5 * qCos(ang));
        polIn.vertex(index).setV(0.5 + mRin/mRou * 0.5 * qSin(ang));
        addVertex(polIn.vertices().at(index));

        addVertex(polOu.vertices().at(index+1));
        polIn.vertex(index+1).setU(0.5 + mRin/mRou * 0.5 * qCos(ang + angStep));
        polIn.vertex(index+1).setV(0.5 + mRin/mRou * 0.5 * qSin(ang + angStep));
        addVertex(polIn.vertices().at(index+1));
        addVertex(polIn.vertices().at(index));
        index +=3;
        ang += angStep;
    }

  computeNormal();


}



}
