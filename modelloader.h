#ifndef MODELLOADER_H
#define MODELLOADER_H
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QVector3D>
#include <QVector2D>
#include "vertex.h"

namespace cgl {
class ModelLoader
{
public:
    ModelLoader();
    ModelLoader(const QString& filename);
    void load(const QString& filename);
    const QVector<Vertex>& vertices() const;



private:
    QFile mFile;
    QVector<Vertex> mVertices;





};

} // end namespace

#endif // MODELLOADER_H
