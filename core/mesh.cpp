#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLContext>
#include "mesh.h"
namespace cgl {
//===================================================================
Mesh::Mesh(QObject *parent) : QObject(parent), mMode(GL_TRIANGLES), mTexture(0), mTextureImage(0),mDebugView(false)
{
    // ctor

    mShaderProgram = new QOpenGLShaderProgram(this);

    mVertexBuffer = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    mIndexBuffer  = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    mTexture      = new QOpenGLTexture(QOpenGLTexture::Target2D);

    resetTransform();


    addMaterial(Material());
}

//===================================================================
Mesh::~Mesh()
{
    // dtor
    mVertexBuffer.destroy();
    mIndexBuffer.destroy();
    mVao.destroy();
    delete mTexture;
    delete mShaderProgram;
}

//===================================================================
void Mesh::bind()
{
    // binds vertex and sdhadder and texture
    // From this place, shaders program is active by the scene
    if (mTexture->isCreated()){

        mTexture->bind();
        mShaderProgram->setUniformValue("has_texture",true);

    }

    if (!mMaterials.isEmpty()) {
        Material material = mMaterials.first();
        mShaderProgram->setUniformValue("material.ambient", material.mAmbient );
        mShaderProgram->setUniformValue("material.diffuse", material.mDiffuse );
        mShaderProgram->setUniformValue("material.specular",material.mSpecular );
        mShaderProgram->setUniformValue("material.shininess",material.mShininess );
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

    if (mDebugView)
        setShaders(":/shaders/light_vertex.vsh", ":/shaders/debug_fragment.fsh",":/shaders/debug_geometry.gsh" );

    else
        setDefaultShaders();



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
    mShaderProgram->enableAttributeArray("position");
    mShaderProgram->setAttributeBuffer("position", GL_FLOAT, 0, 3, sizeof(Vertex));

    mShaderProgram->enableAttributeArray("color");
    mShaderProgram->setAttributeBuffer("color", GL_FLOAT, 3 * 4, 3, sizeof(Vertex));

    mShaderProgram->enableAttributeArray("uv");
    mShaderProgram->setAttributeBuffer("uv", GL_FLOAT, 6 * 4, 2, sizeof(Vertex));

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
void Mesh::setShaders(const QString &vertexFile, const QString &fragmentFile, const QString &geometryFile)
{
    if (QOpenGLContext::currentContext()){
        mShaderProgram->removeAllShaders();
        mShaderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexFile);
        mShaderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentFile);

        if (!geometryFile.isEmpty())
            mShaderProgram->addShaderFromSourceFile(QOpenGLShader::Geometry, geometryFile);


        mShaderProgram->link();
    }
    else
        qDebug()<<Q_FUNC_INFO<<"cannot set shaders. No context avaible";
}

//===================================================================
void Mesh::setDefaultShaders()
{
    // set the vertex and fragment program names

    setShaders(":/shaders/light_vertex.vsh", ":/shaders/light_fragment.fsh" );
}

//===================================================================
void Mesh::setTextureImage(const QImage &image)
{
    // defines the image to texture the object

    if (image.isNull()) {
        qFatal("Mesh::setTexture --> image not defined");
        exit(QtFatalMsg);
    }
    mTextureImage = image;
}

//===================================================================
void Mesh::setDebug(bool enable)
{
    // set the debug mode allowing to vizualizes normals
    mDebugView = enable;

    if (QOpenGLContext::currentContext())
        create();
    else {
        qFatal("Mesh::setDebug --> no current context defined");
        exit(QtFatalMsg);
    }
}

//===================================================================
void Mesh::computeNormal()
{
    // calculates the vector components normal to the plane containing the vertices

    for (int index = 0; index <verticesCount(); index++)
    {
        if ( index + 2 < verticesCount())
        {
            // 2 vectors of the triangle that define this vertex plan
            QVector3D v1 = vertex(index + 1).pos() - vertex(index).pos();
            QVector3D v2 = vertex(index + 2).pos() - vertex(index).pos();

            // Caclulates the normal vector
            vertex(index).setNx((v1.y() * v2.z()) - (v1.z() * v2.y()));
            vertex(index).setNy((v1.z() * v2.x()) - (v1.x() * v2.z()));
            vertex(index).setNz((v1.x() * v2.y()) - (v1.y() * v2.x()));
        }
    }
}
}
