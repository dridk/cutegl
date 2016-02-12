#include <qmath.h>
#include "torusmesh.h"
namespace cgl {
TorusMesh::TorusMesh(QObject *parent) : Mesh(parent),
    mRadiusTorus(0.0), mRadiusTube(0.0), mSector(0), mSeg(0)
{
    // default ctor
}

TorusMesh::TorusMesh(float sRadius, float radius, int seg, int sector, QObject *parent) : Mesh(parent),
    mRadiusTorus(radius), mRadiusTube(sRadius), mSector(sector), mSeg(seg)
{
    // ctor

    setObjectName("Torus");

    makeMesh();

}

void TorusMesh::makeMesh()
{
    // calculates the vertices of the mesh

    float angStep  = qDegreesToRadians(360. / mSeg / mSector);
    float angTorus = 0.0;

    for (int countTorus = 0; countTorus < mSeg; countTorus++) {
        float angTube  = 0.0;
        for (int countTube = 0; countTube < mSeg + 1; countTube++) {
            addVertex(Vertex( (mRadiusTorus + mRadiusTube * qCos(angTorus)) * qCos(angTube),
                              (mRadiusTorus + mRadiusTube * qCos(angTorus)) * qSin(angTube),
                              mRadiusTube * qSin(angTorus), (angTube) / M_PI / 2, (angTorus) / M_PI / 2) );

            addVertex(Vertex( (mRadiusTorus + mRadiusTube * qCos(angTorus + angStep)) * qCos(angTube),
                              (mRadiusTorus + mRadiusTube * qCos(angTorus + angStep)) * qSin(angTube),
                              mRadiusTube * qSin(angTorus + angStep), (angTube) / M_PI / 2, (angTorus+ angStep) / M_PI / 2) );

            addVertex(Vertex( (mRadiusTorus + mRadiusTube * qCos(angTorus)) * qCos(angTube + angStep),
                              (mRadiusTorus + mRadiusTube * qCos(angTorus)) * qSin(angTube + angStep),
                              mRadiusTube * qSin(angTorus), (angTube + angStep) / M_PI / 2, (angTorus) / M_PI / 2) );

            addVertex(Vertex( (mRadiusTorus + mRadiusTube * qCos(angTorus + angStep)) * qCos(angTube),
                              (mRadiusTorus + mRadiusTube * qCos(angTorus + angStep)) * qSin(angTube),
                              mRadiusTube * qSin(angTorus + angStep), (angTube) / M_PI / 2, (angTorus + angStep) / M_PI / 2) );

            addVertex(Vertex( (mRadiusTorus + mRadiusTube * qCos(angTorus + angStep)) * qCos(angTube + angStep),
                              (mRadiusTorus + mRadiusTube * qCos(angTorus + angStep)) * qSin(angTube + angStep),
                              mRadiusTube * qSin(angTorus + angStep), (angTube + angStep) / M_PI / 2, (angTorus + angStep) / M_PI / 2) );

            addVertex(Vertex( (mRadiusTorus + mRadiusTube * qCos(angTorus)) * qCos(angTube + angStep),
                              (mRadiusTorus + mRadiusTube * qCos(angTorus)) * qSin(angTube + angStep),
                              mRadiusTube * qSin(angTorus), (angTube + angStep) / M_PI / 2, (angTorus) / M_PI / 2) );

            angTube += angStep;
        }
        angTorus += angStep;
    }

    computeNormal();
}
}

