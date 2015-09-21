#ifndef PLANEMESH_H
#define PLANEMESH_H
#include "mesh.h"

namespace cgl {

class PlaneMesh : public Mesh
{
public:
    PlaneMesh(QObject * parent = 0);
    PlaneMesh(float x, float y, float width, float height, QObject * parent = 0);
    PlaneMesh(const QRectF& rect, QObject * = 0);

 private:
    void makeMesh();
    void setRect(const QRectF& rect);

    QRectF mRect;
};

}
#endif // PLANEMESH_H
