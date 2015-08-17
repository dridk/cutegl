#include "spheremesh.h"
#include <QtMath>
namespace cgl {
SphereMesh::SphereMesh(float radius, int segments, QObject *parent)
    :Mesh()
{

      double kStep = M_PI / double(segments);

    for (double phi = 0.0; phi < M_PI; phi += kStep) {
        for (double theta = 0.0; theta < 2 * M_PI; theta += kStep) {
            double x = radius * qCos(theta) * qSin(phi); //1
            double y = radius * qSin(theta) * qSin(phi);
            double z = radius * qCos(phi);
            double v = phi / M_PI;
            double u = theta / ( 2 * M_PI);

            addVertex(Vertex(x,y,z,u,v));


            x = radius * qCos(theta + kStep) * qSin(phi); //2
            y = radius * qSin(theta + kStep) * qSin(phi);
            z = radius * qCos(phi);
            v = phi / M_PI;
            u = (theta + kStep) / ( 2 * M_PI);
            addVertex(Vertex(x,y,z,u,v));
            x = radius*qCos(theta)*qSin(phi + kStep); //3
            y = radius*qSin(theta)*qSin(phi + kStep);
            z = radius               * qCos(phi + kStep);
            v = (phi + kStep) / M_PI;
            u = theta / ( 2 * M_PI);
            addVertex(Vertex(x,y,z,u,v));
            x = radius  *qCos(theta + kStep)  *qSin(phi); //2
            y = radius  *qSin(theta + kStep)  *qSin(phi);
            z = radius               * qCos(phi);
            v = phi / M_PI;
            u = (theta + kStep) / ( 2 * M_PI);
            addVertex(Vertex(x,y,z,u,v));
            x = radius  *qCos(theta + kStep)  *qSin(phi + kStep); //4
            y = radius  *qSin(theta + kStep) * qSin(phi + kStep);
            z = radius               * qCos(phi + kStep);
            v = (phi + kStep) / M_PI;
            u = (theta + kStep) / ( 2 * M_PI);
            addVertex(Vertex(x,y,z,u,v));
            x = radius  *qCos(theta) * qSin(phi + kStep); //3
            y = radius  *qSin(theta)  *qSin(phi + kStep);
            z = radius               * qCos(phi + kStep);
            v = (phi + kStep) / M_PI;
            u = theta / ( 2 * M_PI);


            addVertex(Vertex(x,y,z,u,v));
        }
    }






}



}
