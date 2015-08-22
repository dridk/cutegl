#ifndef MESH_H
#define MESH_H
#include <QtGui>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QVector3D>
#include <QQuaternion>
#include <QOpenGLTexture>
#include "vertex.h"

namespace cgl {
/*! \class Mesh
 * \brief This class manage Vertex
 */
class Mesh : public QObject
{
    Q_OBJECT
public:
    Mesh(QObject * parent = 0);
    ~Mesh();
    void setVertices(const QVector<Vertex>& vertices);
    void setIndexes(const QVector<GLuint>& indexes);
    const QVector<Vertex>& vertices() const;
    const QVector<GLuint>& indexes() const;
    int size() const;
    int count() const;
    void addVertex(const Vertex& v);
    void addVertex(float x, float y, float z);
    void addVertex(float x, float y, float z, const QColor& col);
    GLenum mode() const;
    void setMode(GLenum m);
    void setTexture(const QImage&  image);
    QOpenGLTexture * texture();
    Vertex getVertex(int index) const { return mVertices.at(index); }

    // return the Model matrix transformation
    const QMatrix4x4& model() const;

    //Create a Buffer and a VBO
    void create();

    // Bind the VBO & texture
    void bind();

    // Release the VBO & texture
    void release();

    // return the shaders programs of the mesh
    QOpenGLShaderProgram * shaders();



    // define a specific shaders for the mesh
    void setShaders(const QString& vertexFile, const QString& fragmentFile);
    void setDefaultShaders();


    // reset the model by the identity matrix
    void resetTransform();
    void rotate(const QQuaternion & quaternion);
    void rotate(float angle, float x, float y, float z = 0.0f);
    void rotate(float angle, const QVector3D& vector);
    void scale(const QVector3D & vector);
    void scale(float factor);
    void translate(float x, float y, float z=0);
    void translate(const QVector3D& vector);



private:
    QVector<Vertex> mVertices;
    QVector<GLuint> mIndexes;
    QOpenGLBuffer mVertexBuffer;
    QOpenGLBuffer mIndexBuffer;
    QOpenGLVertexArrayObject mVao;
    QOpenGLShaderProgram * mProgram;
    QOpenGLTexture * mTexture;
    QMatrix4x4 mModel;
    GLenum mMode;



};



}
#endif // MESH_H
