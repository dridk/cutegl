#ifndef TUBEMESH_H
#define TUBEMESH_H

#include "mesh.h"
namespace cgl {
class TubeMesh : public Mesh
{
    Q_OBJECT

public:
    TubeMesh(QObject * parent = 0);
    TubeMesh(float rou, float rin, int nseg, float length, QObject *parent = 0);

    float length() const { return mLength; }

private:
    void makeMesh();

    float mLength; // length of the tube
    float mRin;    // inner radius
    float mRou;    // outer radius
    int   mSeg;    // number of segments to approximate sphere
};
}

#endif // TUBEMESH_H
