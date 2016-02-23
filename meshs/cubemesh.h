#ifndef CUBEMESH_H
#define CUBEMESH_H

#include "mesh.h"

namespace cgl {
class CubeMesh : public Mesh
{
    Q_OBJECT
public:
    explicit CubeMesh(double width, double height, double depth, QObject *parent = 0);
    explicit CubeMesh(CubeMesh &cube);
private:
    void makeMesh();

    double mWidth;
    double mLength;
    double mDepth;
};
}


#endif // CUBEMESH_H
