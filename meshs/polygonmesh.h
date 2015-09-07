#ifndef POLYGON_H
#define POLYGON_H

#include "mesh.h"
namespace cgl {
class PolygonMesh : public Mesh
{
    Q_OBJECT

public:
    PolygonMesh(QObject *parent = 0);
    PolygonMesh(float radius, int nseg, QObject *parent = 0);

 private:
    void makeMesh();

    float mRadius ; // radius cercle circonscrit
    int   mSeg;     // number of segments
};
}
#endif // POLYGON_H
