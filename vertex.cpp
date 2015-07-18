#include "vertex.h"
namespace cgl {

Vertex::Vertex(float x, float y, float z)
    :mX(x), mY(y), mZ(z),mRed(1),mGreen(1),mBlue(1)
{

}

Vertex::Vertex(float x, float y, float z, const QColor &col)
    :mX(x), mY(y), mZ(z)
{

    mRed    = col.redF();
    mGreen  = col.greenF();
    mBlue   = col.blueF();


}

Vertex::Vertex()
    :mX(0), mY(0), mZ(0), mRed(1),mGreen(1),mBlue(1)
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



}
