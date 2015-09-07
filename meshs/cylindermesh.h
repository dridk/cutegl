#ifndef CYLINDER_H
#define CYLINDER_H

#include "mesh.h"
namespace cgl {
class CylinderMesh : public Mesh
{
    Q_OBJECT

public:
    CylinderMesh(QObject *parent = 0);
    CylinderMesh(float radius, int nseg, float length, QObject *parent = 0);

private:
    void makeMesh();

    float mLength;  // length of cylinder
    float mRadius;  // radius of cylinder
    int   mSeg;     // number of segments to approximate circle
};
}
#endif // CYLINDER_H
