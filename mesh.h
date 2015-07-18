#ifndef MESH_H
#define MESH_H
#include <QtGui>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

namespace cgl {
class Mesh : public QObject
{
    Q_OBJECT
public:
    Mesh(QObject * parent = 0);
    ~Mesh();
    void setVertices(const QVector<QVector3D>& vertices);
    const QVector<QVector3D>& vertices() const;
    int size() const;
    int count() const;

    void create();
    void bind();
    void release();




    QOpenGLShaderProgram * shaders();

    void setShaders(const QString& vertexFile, const QString& fragmentFile);
    void setDefaultShaders();



private:
QVector<QVector3D> mVertices;
QOpenGLBuffer mBuffer;
QOpenGLVertexArrayObject mVao;
QOpenGLShaderProgram * mProgram;

};



}
#endif // MESH_H
