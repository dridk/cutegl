#include <QVector2D>
#include <QVector3D>
#include "vertex.h"
namespace cgl {
//===================================================================
Vertex::Vertex() :
    mX(0.0), mY(0.0), mZ(0.0),
    mRed(1.0), mGreen(1.0), mBlue(1.0),
    mU(0.0), mV(0.0),
    mNx(0.0), mNy(0.0), mNz(0.0)
{
    // ctor
}

//===================================================================
Vertex::Vertex(float x, float y, float z, float u, float v, float nx, float ny, float nz):
    mX(x), mY(y), mZ(z),
    mRed(1.0), mGreen(1.0), mBlue(1.0),
    mU(u), mV(v),
    mNx(nx), mNy(ny), mNz(nz)
{
    // ctor
}

//===================================================================
Vertex::Vertex(const QVector3D &pos):
    mRed(1.0), mGreen(1.0), mBlue(1.0),
    mU(0.0), mV(0.0),
    mNx(0.0), mNy(0.0), mNz(0.0)
{
    //ctor
    setPos(pos);

}

//===================================================================
Vertex::Vertex(const QVector3D &pos, const QVector2D &tex):
    mRed(1.0), mGreen(1.0), mBlue(1.0),
    mNx(0.0), mNy(0.0), mNz(0.0)
{
    // ctor
    setPos(pos);
    setTex(tex);
}

//===================================================================
Vertex::Vertex(const QVector3D &pos, const QVector2D &tex, const QVector3D &normal):
    mRed(1.0), mGreen(1.0), mBlue(1.0)
{
    //ctor
    setPos(pos);
    setNormal(normal);
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
void Vertex::setNormal(const QVector3D &normal)
{
    // set normal coordinates at this vertex
    mNx = normal.x();
    mNy = normal.y();
    mNz = normal.z();
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

//===================================================================
 Vertex &Vertex::operator = (const Vertex &vertex)
{
    // copy assignement

    mX = vertex.mX;
    mY = vertex.mY;
    mZ = vertex.mZ;
    mRed = vertex.mRed;
    mGreen = vertex.mGreen;
    mBlue = vertex.mBlue;
    mU = vertex.mU;
    mV = vertex.mV;
    mNx = vertex.mNx;
    mNy = vertex.mNy;
    mNz = vertex.mNz;

    return *this;
}
}
