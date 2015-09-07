#ifndef CUBEMESH_H
#define CUBEMESH_H

#include "mesh.h"

namespace cgl {
class CubeMesh : public Mesh
{
    Q_OBJECT
public:
    explicit CubeMesh(QObject *parent = 0);

private:
    void makeMesh();
};
}


#endif // CUBEMESH_H
