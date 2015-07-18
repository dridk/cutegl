#include "mesh.h"
namespace cgl {
Mesh::Mesh(QObject * parent )
    :QObject(parent)
{
    mProgram = new QOpenGLShaderProgram(this);
    mTransform.setToIdentity();

    setMode(GL_TRIANGLE_FAN);

}

Mesh::~Mesh()
{
    mBuffer.destroy();
    mVao.destroy();
}



void cgl::Mesh::setVertices(const QVector<Vertex> &vertices)
{
    mVertices = vertices;
}

const QVector<Vertex> &Mesh::vertices() const
{
    return mVertices;
}

int Mesh::size() const
{
    return count() * sizeof(Vertex);
}

int Mesh::count() const
{
    return mVertices.count();
}

void Mesh::addVertex(const Vertex &v)
{
 mVertices.append(v);
}

QMatrix4x4 *Mesh::transform()
{
    return &mTransform;
}

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
    shaders()->bind();
    shaders()->enableAttributeArray("position");
    shaders()->setAttributeBuffer("position",GL_FLOAT,0,3, sizeof(Vertex));

    shaders()->enableAttributeArray("color");
    shaders()->setAttributeBuffer("color",GL_FLOAT,3*4 ,3, sizeof(Vertex));




    //---}
    mVao.release();

}

void Mesh::bind()
{
    mVao.bind();
}

void Mesh::release()
{
    mVao.release();
}

GLenum Mesh::mode()
{
    return mMode;
}

void Mesh::setMode(GLenum m)
{
   mMode = m;
}

QOpenGLShaderProgram *Mesh::shaders()
{
    return mProgram;
}

void Mesh::setShaders(const QString &vertexFile, const QString &fragmentFile)
{
    mProgram->removeAllShaders();
    mProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexFile);
    mProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentFile);
    mProgram->link();

}

void Mesh::setDefaultShaders()
{
    setShaders(":/shaders/default_vertex.vsh",":/shaders/default_fragment.fsh");
}

}
