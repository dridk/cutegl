#ifndef AXISMESH_H
#define AXISMESH_H

#include <QObject>
#include "mesh.h"

namespace cgl {

class AxisMesh : public Mesh
{
    Q_OBJECT
public:
    explicit AxisMesh(QObject *parent = 0);

signals:

public slots:
private:
    float mFactor;
};

} // namespace cgl

#endif // AXISMESH_H
