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

    int coordVertexCount();
    int normalVertexCount();
    int texCoordVertexCount();



private:
    QFile mFile;
    QVector<Vertex> mVertices;


    QList<QVector3D> mVData;  // vertex Data
    QList<QVector2D> mVtData; // texture Data
    QList<QVector3D> mVnData; // Normal Data


};

} // end namespace

#endif // MODELLOADER_H
