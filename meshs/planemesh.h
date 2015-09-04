#ifndef PLANEMESH_H
#define PLANEMESH_H
#include "mesh.h"

namespace cgl {

class PlaneMesh : public Mesh
{
public:
    PlaneMesh(QObject * parent = 0);
    PlaneMesh(float x, float y, float width, float height, QObject * parent = 0);
    PlaneMesh(const QRectF& rect, QObject * parent = 0);

    void setRect(const QRectF& rect);

    void makeMesh();
private:
  QRectF mRect;

};

}
#endif // PLANEMESH_H
