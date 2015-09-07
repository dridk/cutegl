#ifndef SPHERE_H
#define SPHERE_H

#include "mesh.h"
namespace cgl {
class SphereMesh : public Mesh
{
    Q_OBJECT

public:
    SphereMesh(QObject *parent = 0);
    SphereMesh(float radius, int nseg, QObject *parent = 0);

protected:
    void setSeg(int val)      { mSeg = val; }
    void setRadius(float val) { mRadius = val; }

protected:
    void makeMesh() ;

    float mRadius; // sphere radius
    int   mSeg;    // number of segments to approximate sphere
};
}
#endif // SPHERE_H
