#include "vertex.h"
namespace cgl {

Vertex::Vertex()
:mX(0), mY(0), mZ(0),mRed(1),mGreen(1),mBlue(1),mTexCoordX(0),mTexCoordY(0)
{

}

Vertex::Vertex(float x, float y, float z, const QColor& col)
    :mX(x), mY(y),mTexCoordX(0),mTexCoordY(0)
{
    setColor(col);
}

Vertex::Vertex(const QVector3D &coord,const QColor& col)
    :mTexCoordX(0),mTexCoordY(0)
{
   setCoord(coord);
   setColor(col);
}

Vertex::Vertex(const QVector3D &coord, const QVector3D &normal, const QVector2D &texCoord, const QColor &col)
{
    setCoord(coord);
    setNormal(normal);
    setTexCoord(texCoord);
    setColor(col);
}

void Vertex::setCoord(const QVector3D &coord)
{
    mX = coord.x();
    mY = coord.y();
    mZ = coord.z();
}

void Vertex::setNormal(const QVector3D &normal)
{
    mNormalX = normal.x();
    mNormalY = normal.y();
    mNormalZ = normal.z();
}

void Vertex::setTexCoord(const QVector2D &texCoord)
{
    mTexCoordX = texCoord.x();
    mTexCoordY = texCoord.y();
}

void Vertex::setColor(const QColor &col)
{
    mRed    = col.redF();
    mGreen  = col.greenF();
    mBlue   = col.blueF();
}

float Vertex::x() const
{
    return mX;
}

float Vertex::y() const
{
    return mY;
}

float Vertex::z() const
{
    return mZ;
}

float Vertex::normalX() const
{
    return mNormalX;
}

float Vertex::normalY() const
{
    return mNormalY;
}

float Vertex::normalZ() const
{
    return mNormalZ;
}

QColor Vertex::color() const
{
    return QColor::fromRgbF(mRed, mGreen,mBlue);
}

QVector2D Vertex::texCoord() const
{
    return QVector2D(mTexCoordX, mTexCoordY);
}



}
