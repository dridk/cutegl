#ifndef MODELMESH_H
#define MODELMESH_H
#include <QObject>

#include "mesh.h"
#include "modelloader.h"

namespace cgl{
class ModelMesh : public Mesh
{
    Q_OBJECT
public:
    explicit ModelMesh(const QString& filename,  QObject *parent = 0);

    void setModel(const QString& filename);
    void makeMesh();

private:
    ModelLoader mLoader;
};
} // end namespace
#endif // MODELMESH_H
