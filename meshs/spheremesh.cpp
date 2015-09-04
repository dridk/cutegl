#include <qmath.h>
#include <QVector2D>
#include <QImage>

#include "spheremesh.h"
namespace cgl {
//===================================================================
SphereMesh::SphereMesh(QObject *parent) : Mesh(parent),
    mRadius(0.0), mSeg(0.0)
{
    // default ctor
}

//===================================================================
SphereMesh::SphereMesh(float radius, int nseg, QObject *parent) : Mesh(parent),
    mRadius(radius), mSeg(nseg)
{
    // ctor

    setObjectName("Sphere");
    makeMesh();
}

//===================================================================
void SphereMesh::makeMesh()
{
    // calculates the vertices of the mesh

    double kStep = M_PI / double(mSeg);

    for (double phi = 0.0; phi < M_PI; phi += kStep) {
        for (double theta = 0.0; theta < 2 * M_PI; theta += kStep) {
            double x = mRadius * qCos(theta) * qSin(phi); //1
            double y = mRadius * qSin(theta) * qSin(phi);
            double z = mRadius * qCos(phi);
            double v = phi / M_PI;
            double u = theta / ( 2 * M_PI);
            addVertex(Vertex(x, y, z, u, v));
            x = mRadius * qCos(theta + kStep) * qSin(phi); //2
            y = mRadius * qSin(theta + kStep) * qSin(phi);
            z = mRadius * qCos(phi);
            v = phi / M_PI;
            u = (theta + kStep) / ( 2 * M_PI);
            addVertex(Vertex(x, y, z, u, v));
            x = mRadius*qCos(theta)*qSin(phi + kStep); //3
            y = mRadius*qSin(theta)*qSin(phi + kStep);
            z = mRadius               * qCos(phi + kStep);
            v = (phi + kStep) / M_PI;
            u = theta / ( 2 * M_PI);
            addVertex(Vertex(x, y, z, u, v));
            x = mRadius  *qCos(theta + kStep)  *qSin(phi); //2
            y = mRadius  *qSin(theta + kStep)  *qSin(phi);
            z = mRadius               * qCos(phi);
            v = phi / M_PI;
            u = (theta + kStep) / ( 2 * M_PI);
            addVertex(Vertex(x, y, z, u, v));
            x = mRadius  *qCos(theta + kStep)  *qSin(phi + kStep); //4
            y = mRadius  *qSin(theta + kStep) * qSin(phi + kStep);
            z = mRadius               * qCos(phi + kStep);
            v = (phi + kStep) / M_PI;
            u = (theta + kStep) / ( 2 * M_PI);
            addVertex(Vertex(x, y, z, u, v));
            x = mRadius  *qCos(theta) * qSin(phi + kStep); //3
            y = mRadius  *qSin(theta)  *qSin(phi + kStep);
            z = mRadius               * qCos(phi + kStep);
            v = (phi + kStep) / M_PI;
            u = theta / ( 2 * M_PI);
            addVertex(Vertex(x, y, z, u, v));
        }
    }
}

}
