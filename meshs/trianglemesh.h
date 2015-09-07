#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H

#include "mesh.h"

namespace cgl {
class TriangleMesh : public Mesh
{
 public:
    enum TriangleType { ISOC, RECT, GEN };

    explicit TriangleMesh(QObject *parent = 0);
    TriangleMesh(double b, double h, TriangleType type, double xc = 0.0, QObject *parent = 0);
    ~TriangleMesh(){;}

    void    makeMesh();

private:
    void    Cdg();

    double mB;          // Base width
    double mH;          // Height
    TriangleType mType; // Type of tiangle
    double mXc;         // x coordinate of apex (in case of general triangle)
    double mXg, mYg;    // coordinates of center of gravity
};
}

#endif // TRIANGLEMESH_H
