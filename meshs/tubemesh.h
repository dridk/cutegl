#ifndef TUBE_H
#define TUBE_H

#include "mesh.h"
namespace cgl {
class TubeMesh : public Mesh
{
    Q_OBJECT

public:
    TubeMesh(QObject *parent);
    TubeMesh(float rou, float rin, int nseg, float length, QObject *parent = 0);

    void makeMesh();

private:
    float mLength; // length of the tube
    float mRin;    // inner radius
    float mRou;    // outer radius
    int   mSeg;    // number of segments to approximate sphere
};
}
#endif // TUBE_H
