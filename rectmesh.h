#ifndef PLANEMESH_H
#define PLANEMESH_H
#include "mesh.h"

namespace cgl {

class RectMesh : public Mesh
{
public:
    RectMesh(QObject * parent = 0);
    RectMesh(float top, float bottom, float left, float right, QObject * parent = 0);

    void setRect(float top, float bottom, float left, float right, float z=0);

private:
    float top;
    float bottom;
    float left;
    float right;

};

}
#endif // PLANEMESH_H
