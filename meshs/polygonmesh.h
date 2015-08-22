#ifndef POLYGONMESH_H
#define POLYGONMESH_H

#include <QObject>
#include "mesh.h"

namespace cgl {
class PolygonMesh : public Mesh
{
    Q_OBJECT
public:
    explicit PolygonMesh(float radius, int nseg, QObject *parent = 0);


private: 
    float mRadius; 
    int   mSeg; 
};

}

#endif // POLYGONMESH_H
