#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include "mesh.h"
namespace cgl {
//===================================================================
Mesh::Mesh(QObject *parent) : QObject(parent), mMode(GL_TRIANGLES), mTexture(0), mTextureImage(0)
{
    // ctor

    mShaderProgram = new QOpenGLShaderProgram(this);

    mVertexBuffer = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    mIndexBuffer  = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    mTexture      = new QOpenGLTexture(QOpenGLTexture::Target2D);

    resetTransform();
}

//===================================================================
Mesh::~Mesh()
{
    // dtor
    mVertexBuffer.destroy();
    mIndexBuffer.destroy();
    mVao.destroy();
}

//===================================================================
void Mesh::bind()
{
    // binds vertex and sdhadder and texture

    if (mTexture->isCreated()) {
        mTexture->bind();
        mShaderProgram->setUniformValue("textureEnabled", true);
    }
    else {
        mShaderProgram->setUniformValue("textureEnabled", false);
    }

    mVao.bind();
}

//===================================================================
void Mesh::create()
{
    // create the mesh from the vertices

    if (mVertices.count() == 0) {
        qWarning() << Q_FUNC_INFO << "No vertices defined for" << objectName();
        return;
    }

    setDefaultShaders();

    //    qDebug()<<mTextureImage;
    if (!mTextureImage.isNull()) {   // ca crash si on test pas ...
        mTexture  = new QOpenGLTexture(mTextureImage);
        mTexture->create();
    }



    mVertexBuffer.create();
    mVertexBuffer.bind();
    mVertexBuffer.allocate(mVertices.data(), mVertices.count() * sizeof(Vertex));
    mVertexBuffer.release();

    if (mIndices.count()) {
        mIndexBuffer.create();
        mIndexBuffer.bind();
        mIndexBuffer.allocate(mIndices.data(), mIndices.count() * sizeof(GLuint));
        mIndexBuffer.release();
    }

    mVao.create();
    mVao.bind();


    mIndexBuffer.bind();
    mVertexBuffer.bind();


    mShaderProgram->bind();
    mShaderProgram->enableAttributeArray("posCoord");
    mShaderProgram->setAttributeBuffer("posCoord", GL_FLOAT, 0, 3, sizeof(Vertex));

    mShaderProgram->enableAttributeArray("color");
    mShaderProgram->setAttributeBuffer("color", GL_FLOAT, 3 * 4, 3, sizeof(Vertex));

    mShaderProgram->enableAttributeArray("texCoord");
    mShaderProgram->setAttributeBuffer("texCoord", GL_FLOAT, 6 * 4, 2, sizeof(Vertex));

    mShaderProgram->enableAttributeArray("normal");
    mShaderProgram->setAttributeBuffer("normal", GL_FLOAT, 8 * 4, 2, sizeof(Vertex));

    mShaderProgram->release();
    mIndexBuffer.release();
    mVertexBuffer.release();
    mVao.release();

    if (glGetError() != GL_NO_ERROR) {
        qFatal("Mesh::Create: OpenGL error");
        exit(QtFatalMsg);
    }

    qDebug() << Q_FUNC_INFO << "Mesh" << objectName() << "created";
}

//===================================================================
void Mesh::release()
{
    mVao.release();
    if (mTexture->isCreated())
        mTexture->release();

    mShaderProgram->release();
}

//===================================================================
void Mesh::setShaders(const QString &vertexFile, const QString &fragmentFile)
{
    mShaderProgram->removeAllShaders();
    mShaderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexFile);
    mShaderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentFile);
    mShaderProgram->link();
}

//===================================================================
void Mesh::setDefaultShaders()
{
    // set the vertex and fragment program names

    setShaders(":/shaders/default_vertex.vsh", ":/shaders/default_fragment.fsh");
}

void Mesh::setTextureImage(const QImage &image)
{
    if (image.isNull())
        qDebug()<<Q_FUNC_INFO<<"image is null";

        mTextureImage = image;


}

//===================================================================


}
