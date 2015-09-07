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

    void                   load(const QString& filename);
    const QVector<Vertex>& vertices() const               { return mVertices; }

private:
    int                    coordVertexCount() const       { return mVData.count(); }
    int                    normalVertexCount() const      { return mVnData.count(); }
    int                    texCoordVertexCount() const    { return mVtData.count(); }

    QFile            mFile;     // file where cerices are stored
    QVector<Vertex>  mVertices; // vertices list
    QList<QVector3D> mVData;    // vertex Data
    QList<QVector2D> mVtData;   // texture Data
    QList<QVector3D> mVnData;   // Normal Data

};

}

#endif // MODELLOADER_H
