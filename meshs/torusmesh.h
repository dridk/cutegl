#ifndef TORUSMESH_H
#define TORUSMESH_H

#include "mesh.h"
namespace cgl {
class TorusMesh : public Mesh
{
    Q_OBJECT

public:
    TorusMesh(QObject *parent = 0);
    TorusMesh(float sRadius, float radius, int seg, int sector = 1,  QObject *parent = 0);

    float radius() const { return mRadiusTorus; }

private:
    void makeMesh();

    float mRadiusTorus;  // distance between center of torus nd center of tube
    float mRadiusTube;   // radius of the tube
    int   mSector;       // fraction of torus to be drawn 1/mSector
    int   mSeg;          // number of segments to approximate circle
};
}

#endif // TORUSMESH_H
