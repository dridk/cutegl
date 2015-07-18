#ifndef MESH_H
#define MESH_H
#include <QtGui>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

#include "vertex.h"

namespace cgl {
class Mesh : public QObject
{
    Q_OBJECT
public:
    Mesh(QObject * parent = 0);
    ~Mesh();
    void setVertices(const QVector<Vertex>& vertices);
    const QVector<Vertex>& vertices() const;
    int size() const;
    int count() const;


    void addVertex(const Vertex& v);


     QMatrix4x4 * transform();

    void create();
    void bind();
    void release();

    // draw mode
    GLenum mode();
    void setMode(GLenum m);




    QOpenGLShaderProgram * shaders();

    void setShaders(const QString& vertexFile, const QString& fragmentFile);
    void setDefaultShaders();



private:
QVector<Vertex> mVertices;


QOpenGLBuffer mBuffer;
QOpenGLVertexArrayObject mVao;
QOpenGLShaderProgram * mProgram;
QMatrix4x4 mTransform;

GLenum mMode;

};



}
#endif // MESH_H
