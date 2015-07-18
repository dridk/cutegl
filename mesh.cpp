#include "mesh.h"
namespace cgl {

Mesh::Mesh(QObject * parent )
    :QObject(parent)
{
    mProgram = new QOpenGLShaderProgram(this);
    mTexture = NULL;
    setMode(GL_TRIANGLE_FAN);
    resetTransform();
}
//----------------------------------------------------------

Mesh::~Mesh()
{
    mBuffer.destroy();
    mVao.destroy();
}
//----------------------------------------------------------

void cgl::Mesh::setVertices(const QVector<Vertex> &vertices)
{
    mVertices = vertices;
}
//----------------------------------------------------------

const QVector<Vertex> &Mesh::vertices() const
{
    return mVertices;
}
//----------------------------------------------------------

int Mesh::size() const
{
    return count() * sizeof(Vertex);
}
//----------------------------------------------------------

int Mesh::count() const
{
    return mVertices.count();
}
//----------------------------------------------------------

void Mesh::addVertex(const Vertex &v)
{
    mVertices.append(v);
}
//----------------------------------------------------------

void Mesh::addVertex(float x, float y, float z)
{
    addVertex(Vertex(x,y,z));
}
//----------------------------------------------------------

void Mesh::addVertex(float x, float y, float z, const QColor &col)
{
    addVertex(Vertex(x,y,z,col));
}


//----------------------------------------------------------

const QMatrix4x4& Mesh::model() const
{
    return mModel;
}
//----------------------------------------------------------

void cgl::Mesh::create()
{
    // Create buffer and send it to graphics card
    mBuffer.create();
    mBuffer.bind();
    mBuffer.allocate(mVertices.data(), mVertices.count() * sizeof(Vertex));
    mBuffer.release();

    // Create VAO and send it to graphics cards
    mVao.create();
    mVao.bind();
    //---{
    mBuffer.bind();

    qDebug()<<sizeof(Vertex);

    shaders()->bind();
    shaders()->enableAttributeArray("position");
    shaders()->setAttributeBuffer("position",GL_FLOAT,0,3, sizeof(Vertex));

    shaders()->enableAttributeArray("color");
    shaders()->setAttributeBuffer("color",GL_FLOAT,3*4 ,3, sizeof(Vertex));

    shaders()->enableAttributeArray("texCoord");
    shaders()->setAttributeBuffer("texCoord",GL_FLOAT,6*4 ,2, sizeof(Vertex));

    //---}
    mVao.release();


}
//----------------------------------------------------------

void Mesh::bind()
{
    if (mTexture) {
        mTexture->bind();
        shaders()->setUniformValue("textureEnabled",true);
    }
    else
        shaders()->setUniformValue("textureEnabled",false);



    mVao.bind();
}
//----------------------------------------------------------

void Mesh::release()
{
    mVao.release();
    if (mTexture)
        mTexture->release();
}
//----------------------------------------------------------

GLenum Mesh::mode() const
{
    return mMode;
}
//----------------------------------------------------------

void Mesh::setMode(GLenum m)
{
    mMode = m;
}

void Mesh::setTexture(const QImage &image)
{
    if (mTexture != NULL)
        delete mTexture;

    mTexture = new QOpenGLTexture(image);
    mTexture->create();

}

QOpenGLTexture *Mesh::texture()
{
    return mTexture;
}
//----------------------------------------------------------

QOpenGLShaderProgram *Mesh::shaders()
{
    return mProgram;
}



//----------------------------------------------------------

void Mesh::setShaders(const QString &vertexFile, const QString &fragmentFile)
{
    mProgram->removeAllShaders();
    mProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexFile);
    mProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentFile);
    mProgram->link();

}
//----------------------------------------------------------

void Mesh::setDefaultShaders()
{
    setShaders(":/shaders/default_vertex.vsh",":/shaders/default_fragment.fsh");
}
//----------------------------------------------------------
//--------------TRANSFORM METHODS---------------------------

void Mesh::resetTransform()
{
    mModel.setToIdentity();
}
//----------------------------------------------------------

void Mesh::rotate(const QQuaternion &quaternion)
{
    mModel.rotate(quaternion);
}
//----------------------------------------------------------
void Mesh::rotate(float angle, float x, float y, float z)
{
    mModel.rotate(angle,x,y,z);
}

void Mesh::rotate(float angle, const QVector3D &vector)
{
    mModel.rotate(angle,vector);
}
//----------------------------------------------------------
void Mesh::scale(const QVector3D &vector)
{
    mModel.scale(vector);
}
//----------------------------------------------------------
void Mesh::scale(float factor)
{
    mModel.scale(factor);
}
//----------------------------------------------------------
void Mesh::translate(float x, float y, float z)
{
    mModel.translate(x,y,z);
}

void Mesh::translate(const QVector3D &vector)
{
    mModel.translate(vector);
}
//----------------------------------------------------------
} // end namespace
