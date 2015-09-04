#ifndef MESH_H
#define MESH_H

#include <QImage>
#include <QMatrix4x4>
#include <QObject>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

#include <mesh.h>
#include <vertex.h>

class QOpenGLShaderProgram;
class QOpenGLTexture;
namespace cgl {
class Mesh : public QObject
{
    Q_OBJECT

public:
    Mesh(QObject *parent = 0);
    ~Mesh();

    void                   addVertex(const Vertex &ver) { mVertices.append(ver); }
    void                   bind();
    void                   create();
    int                    indicesCount() const { return mIndices.count(); }
    int                    verticesCount() const { return mVertices.count(); }
    virtual void           makeMesh() = 0;
    GLenum                 mode() const { return mMode; }
    QMatrix4x4             modelMatrix() const { return mModelMatrix; }
    bool                   hasIndices() const { return mIndices.isEmpty(); }
    void                   release();
    void                   resetTransform() { mModelMatrix.setToIdentity(); }
    void                   rotate(float angle, float x, float y, float z) { mModelMatrix.rotate(angle, x, y, z); }
    void                   setShaders(const QString &vertexFile, const QString &fragmentFile);
    void                   setDefaultShaders();
    void                   setTexture(const QImage &image);
    void                   setTextureImage(const QString filename) {mTextureImage.load(filename); }
    void                   setMode(GLenum mode) { mMode = mode;}
    QImage                 textureImage() const { return mTextureImage; }
    QOpenGLShaderProgram   *shaderProgram() const { return mShaderProgram; }
    void                   translate(float x, float y, float z) { mModelMatrix.translate(x, y, z); }
    QVector<Vertex>        vertices() const { return mVertices; }
    Vertex&                vertex(int index){ return mVertices[index];}


protected:
    QVector<Vertex>          mVertices;         // list of vertexes for this mesh

private:
    QOpenGLBuffer            mIndexBuffer;      // the indexes to the verices in graphic card
    QVector<GLuint>          mIndices;          // the indices list
    GLenum                   mMode;             // drawing mode to connect vertices
    QMatrix4x4               mModelMatrix;      // the model matrix
    QOpenGLShaderProgram     *mShaderProgram;   // the shadder program
    QOpenGLTexture           *mTexture;         // texture od the mesh
    QImage                   mTextureImage;    // image of the texture
    QOpenGLVertexArrayObject mVao;              // the array ....
    QOpenGLBuffer            mVertexBuffer;     // the buffer that holds the lis of vertices in graphic card
};
}
#endif // MESH_H
