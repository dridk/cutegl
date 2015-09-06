#include "light.h"

Light::Light(const QVector3D &pos, const QColor &col)
{
    mPos = pos;

    mColVector.setX(col.redF());
    mColVector.setY(col.greenF());
    mColVector.setZ((col.blueF()));
}

Light::Light(float x, float y, float z, const QColor &col)
{
    mPos = QVector3D(x,y,z);
    mColVector.setX(col.redF());
    mColVector.setY(col.greenF());
    mColVector.setZ((col.blueF()));

}

const QVector3D &Light::position() const
{
    return mPos;
}

const QVector3D &Light::colorVector() const
{
    return mColVector;
}

 QColor Light::color() const
{
     return QColor::fromRgbF(mColVector.x(), mColVector.y(), mColVector.z());
 }

 void Light::setPosition(const QVector3D &pos)
 {
     mPos = pos;
 }
