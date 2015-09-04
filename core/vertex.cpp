#include <QVector2D>
#include <QVector3D>
#include "vertex.h"
namespace cgl {
//===================================================================
Vertex::Vertex() :
    mX(0.0), mY(0.0), mZ(0.0),
    mRed(1.0), mGreen(1.0), mBlue(1.0),
    mU(0.0), mV(0.0),
    mNormX(0.0), mNormY(0.0), mNormZ(0.0)
{
    // ctor
}

//===================================================================
Vertex::Vertex(float x, float y, float z, float u, float v, const QColor &col) :
    mX(x), mY(y), mZ(z),
    mU(u), mV(v),
    mNormX(0.0), mNormY(0.0), mNormZ(0.0)
{
    // ctor no texture no normal
    setColor(col);
}

//===================================================================
Vertex::Vertex(const QVector3D &pos, const QColor &col)
{
    // ctor no texture no normal
    setPos(pos);
    setColor(col);

}

//===================================================================
Vertex::Vertex(const QVector3D &pos, const QVector3D &norm, const QVector2D &tex, const QColor &col)
{
    // ctor position, normal and texture
    setPos(pos);
    setNorm(norm);
    setTex(tex);
}

//===================================================================
void Vertex::setColor(const QColor &col)
{
    // set color at this vertex
    mRed   = col.redF();
    mGreen = col.greenF();
    mBlue =  col.blueF();
}

//===================================================================
void Vertex::setNorm(const QVector3D &norm)
{
    // set normal coordinates at this vertex
    mNormX = norm.x();
    mNormY = norm.y();
    mNormZ = norm.z();
}

//===================================================================
void Vertex::setPos(const QVector3D &pos)
{
    // set position coordinate of this vertex
    mX = pos.x();
    mY = pos.y();
    mZ = pos.z();
}

//===================================================================
void Vertex::setTex(const QVector2D &tex)
{
    // set the texture coordinate at this vertex
    mU = tex.x();
    mV = tex.y();
}
}
