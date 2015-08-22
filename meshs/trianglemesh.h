#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H

#include <QObject>
#include <QPolygonF>
#include "mesh.h"

namespace cgl {
class TriangleMesh : public Mesh
{
    Q_OBJECT
public:
    enum TriangleType { ISOC, RECT, GEN };

    explicit TriangleMesh(double b, double h, TriangleType type, double xc = 0.0, QObject *parent = 0);

    const QPolygonF& toPolygon() const;

protected:
    void    computeGravityCenter();

    double mB;          // Base width
    double mH;          // Height
    TriangleType mType; // Type of tiangle
    double mXc;         // x coordinate of apex (in case of general triangle)
    QPointF mGravityCenter;
    QPolygonF mPolygon;
};

}
#endif // TRIANGLEMESH_H
