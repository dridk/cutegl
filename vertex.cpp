#include "vertex.h"
namespace cgl {

Vertex::Vertex(float x, float y, float z)
    :mX(x), mY(y), mZ(z),mRed(1),mGreen(1),mBlue(1),mTexCoordX(0),mTexCoordY(0)
{

}

Vertex::Vertex(const QVector3D &vertex)
    :mRed(1),mGreen(1),mBlue(1),mTexCoordX(0),mTexCoordY(0)
{
    mX = vertex.x();
    mY = vertex.y();
    mZ = vertex.z();
}

Vertex::Vertex(const QVector3D &vertex, const QVector3D &normal,const QVector2D &texCoord, const QColor &col)
{
    mX = vertex.x();
    mY = vertex.y();
    mZ = vertex.z();

    mNormalX = normal.x();
    mNormalY = normal.y();
    mNormalZ = normal.z();

    mRed    = col.redF();
    mGreen  = col.greenF();
    mBlue   = col.blueF();

    mTexCoordX = texCoord.x();
    mTexCoordY = texCoord.y();

}

Vertex::Vertex(float x, float y, float z, const QColor &col)
    :mX(x), mY(y), mZ(z),mTexCoordX(0),mTexCoordY(0)
{



    mRed    = col.redF();
    mGreen  = col.greenF();
    mBlue   = col.blueF();


}

Vertex::Vertex(float x, float y, float z, const QColor &col, const QVector2D &texCoord)
    :mX(x), mY(y), mZ(z)
{

    mRed    = col.redF();
    mGreen  = col.greenF();
    mBlue   = col.blueF();

    mTexCoordX = texCoord.x();
    mTexCoordY = texCoord.y();
}

Vertex::Vertex()
    :mX(0), mY(0), mZ(0), mRed(1),mGreen(1),mBlue(1),mTexCoordX(0),mTexCoordY(0)
{

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

QPointF Vertex::texCoord() const
{
    return QPointF(mTexCoordX, mTexCoordY);
}



}
