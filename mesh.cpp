#include "mesh.h"
namespace cgl {
Mesh::Mesh(QObject * parent )
    :QObject(parent)
{
    mProgram = new QOpenGLShaderProgram(this);
}

Mesh::~Mesh()
{
    mBuffer.destroy();
    mVao.destroy();
}



void cgl::Mesh::setVertices(const QVector<QVector3D> &vertices)
{
    mVertices = vertices;
    qDebug()<<vertices;
}

const QVector<QVector3D> &Mesh::vertices() const
{
    return mVertices;
}

int Mesh::size() const
{
    return count() * sizeof(QVector3D);
}

int Mesh::count() const
{
    return mVertices.count();
}

void cgl::Mesh::create()
{
    // Create buffer and send it to graphics card
    mBuffer.create();
    mBuffer.bind();
    mBuffer.allocate(mVertices.data(), mVertices.count() * sizeof(QVector3D));
    mBuffer.release();

    // Create VAO and send it to graphics cards
    mVao.create();
    mVao.bind();
    //---{
    mBuffer.bind();
    shaders()->bind();
    shaders()->enableAttributeArray("position");
    shaders()->setAttributeBuffer("position",GL_FLOAT,0,3);

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
