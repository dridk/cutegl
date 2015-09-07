#include "cylindermesh.h"
#include "tubemesh.h"
namespace cgl {
//===================================================================
TubeMesh::TubeMesh(QObject *parent) : Mesh(parent),
    mLength(0.0), mRin(0.0), mRou(0.0), mSeg(0)
{

}

//===================================================================
TubeMesh::TubeMesh(float rou, float rin, int nseg, float length, QObject *parent) : Mesh(parent),
    mLength(length), mRin(rin), mRou(rou), mSeg(nseg)
{
    // ctor

    setObjectName("Tube");
    if (rou < rin) {
        qWarning("Tube::Tube: outer radius must be larger than inner radius");
        exit(QtWarningMsg);
    }

    makeMesh();
}

//===================================================================
void TubeMesh::makeMesh()
{
    // calculates the vertices of the mesh

    cgl::CylinderMesh cyIn(mRin, mSeg, mLength, this);
    cgl::CylinderMesh cyOu(mRou, mSeg, mLength, this);

    for(int index = 0; index < cyIn.verticesCount(); index++) {
        addVertex(cyIn.vertices().at(index));
    }
    for(int index = 0; index < cyOu.verticesCount(); index++) {
        addVertex(cyOu.vertices().at(index));
    }
}
}
