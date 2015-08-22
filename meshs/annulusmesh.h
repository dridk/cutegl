#ifndef ANNULUSMESH_H
#define ANNULUSMESH_H

#include <QObject>
#include "mesh.h"

class PolygonMesh;

namespace cgl {

class AnnulusMesh : public Mesh
{
    Q_OBJECT
public:
    explicit AnnulusMesh(float rout, float rin, int nseg, QObject *parent = 0);

private:
    float       mRIn;
    float       mROu;
    int         mSeg;
};

}
#endif // ANNULUSMESH_H
