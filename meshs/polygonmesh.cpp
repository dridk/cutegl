#include "polygonmesh.h"

namespace cgl {
PolygonMesh::PolygonMesh(float radius, int nseg, QObject *parent) :  Mesh(parent),
    mRadius(radius), mSeg(nseg)
{
    setMode(GL_TRIANGLES);
    setTexture(QImage(":/textures/wood.jpg"));

    // calculate vertices

    double angStep = qDegreesToRadians(360. / mSeg);
    double ang = 0.0;
    Vertex center;
    center.setCoord(QVector3D(0.0, 0.0, 0.0));
    center.setNormal(QVector3D(0.0, 0.0, 0.0));
    center.setTexCoord(QVector2D(0.5, 0.5));
    center.setColor(Qt::blue);

    for( int count = 0; count < mSeg; count++) {
        qDebug() << Q_FUNC_INFO << mSeg << count;
        addVertex(Vertex(QVector3D(mRadius * qCos(ang), mRadius * qSin(ang),0.0),
                         QVector3D(0.0, 0.0, 0.0),
                         QVector2D(0.5 + 0.5 * qCos(ang), 0.5 + 0.5 * qSin(ang)),
                         Qt::blue));
        addVertex(Vertex(QVector3D(mRadius * qCos(ang + angStep), mRadius * qSin(ang + angStep), 0.0),
                         QVector3D(0.0, 0.0, 0.0),
                         QVector2D(0.5 + 0.5 * qCos(ang + angStep), 0.5 + 0.5 * qSin(ang + angStep)),
                         Qt::blue));
        addVertex(center);
        ang += angStep;
    }

}

}
