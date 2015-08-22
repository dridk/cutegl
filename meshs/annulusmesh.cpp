#include "annulusmesh.h"
#include "polygonmesh.h"

namespace cgl {


AnnulusMesh::AnnulusMesh::AnnulusMesh(float rout, float rin, int nseg, QObject *parent) :
    Mesh(parent), mRIn(rout), mROu(rin), mSeg(nseg)
{
    setMode(GL_TRIANGLES);

    setTexture(QImage(":/textures/wood.jpg"));

    PolygonMesh *PolOu = new PolygonMesh(mROu, mSeg, this);
    PolygonMesh *PolIn = new PolygonMesh(mRIn, mSeg, this);
    // calculates vertices

    double angStep = qDegreesToRadians(360. / mSeg);
    double ang = 0.0;

    int index = 0;

    for (int count = 0; count < PolOu->count() / 3; count++) {
        addVertex(PolOu->getVertex(index));
        addVertex(PolOu->getVertex(index+1));
        PolIn->getVertex(index).setTexCoord(QVector2D(0.5 + mRIn/mROu * 0.5 * qCos(ang),
                                                    0.5 + mRIn/mROu * 0.5 * qSin(ang)));
        addVertex(PolIn->getVertex(index));

        addVertex(PolOu->getVertex(index+1));
        PolIn->getVertex(index+1).setTexCoord(QVector2D(0.5 + mRIn/mROu * 0.5 * qCos(ang + angStep),
                                                      0.5 + mRIn/mROu * 0.5 * qSin(ang + angStep)));
        addVertex(PolIn->getVertex(index+1));
        addVertex(PolIn->getVertex(index));
        index +=3;
        ang += angStep;
    }

}

}
