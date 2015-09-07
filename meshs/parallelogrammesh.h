#ifndef PARALLELOGRAMMESH_H
#define PARALLELOGRAMMESH_H

#include "mesh.h"
namespace cgl {
class ParallelogramMesh : public Mesh
{
public:
    ParallelogramMesh(QObject *parent = 0);
    ParallelogramMesh(double width, double height, double angle = 90.0, QObject *parent = 0);

private:
    void makeMesh();

    double mAngle;  // angle for a parallelepiped
    double mHeight; // length along y
    double mSlant;  // slant
    double mWidth;  // length along x
};
}
#endif // PARALLELOGRAMMESH_H
