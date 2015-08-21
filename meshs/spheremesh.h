#ifndef SPHEREMESH_H
#define SPHEREMESH_H

#include "mesh.h"

namespace cgl {
class SphereMesh : public Mesh
{
    Q_OBJECT
public:
    SphereMesh(float radius, int segments, QObject *parent = 0);
};

}

#endif // SPHEREMESH_H
