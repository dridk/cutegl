#ifndef TORUSMESH_H
#define TORUSMESH_H

#include "mesh.h"
namespace cgl {
class TorusMesh : public Mesh
{
    Q_OBJECT

public:
    TorusMesh(QObject *parent = 0);
    TorusMesh(float sRadius, float radius, int seg, QObject *parent = 0);
private:
    void makeMesh();

    float mRadiusTorus;  // distance between center of torus nd center of tube
    float mRadiusTube;   // radius of the tube
    int   mSeg;          // number of segments to approximate circle
};
}

#endif // TORUSMESH_H
