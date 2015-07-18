#ifndef PLANEMESH_H
#define PLANEMESH_H
#include "mesh.h"

namespace cgl {

class RectMesh : public Mesh
{
public:
    RectMesh(QObject * parent = 0);
    RectMesh(float x, float y, float width, float height, QObject * parent = 0);

    void setRect(float x, float y, float width, float height);

private:
    float mX;
    float mY;
    float mWidth;
    float mHeight;

};

}
#endif // PLANEMESH_H
