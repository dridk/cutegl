#ifndef ANNULUS_H
#define ANNULUS_H

#include "mesh.h"
namespace cgl {
class AnnulusMesh : public Mesh
{
    Q_OBJECT

public:
    AnnulusMesh(QObject *parent = 0);
    AnnulusMesh(float rou, float rin, int nseg, QObject *parent = 0);

private:
    void makeMesh();

    float mRin;  // inner radius
    float mRou;  // outer radius
    int   mSeg;  // number of segments to aproximate circle
};
}
#endif // ANNULUS_H
