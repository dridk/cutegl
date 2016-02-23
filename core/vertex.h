#ifndef VERTEX_H
#define VERTEX_H

#include <QColor>
#include <QVector2D>

class QVector3D;
class QVector2D;

namespace cgl {

class Vertex
{
public:
    enum {
        VERTEX_OFFSET  = 0,
        COLOR_OFFSET   = sizeof(float) * 3,
        TEXTURE_OFFSET = sizeof(float) * 6,
        NORMAL_OFFSET  = sizeof(float) * 9
    };

    Vertex();
    Vertex(float x, float y,  float z, float u=0, float v=0, float nx=0, float ny=0, float nz=0);
    Vertex(const QVector3D &pos);
    Vertex(const QVector3D &pos, const QVector2D &tex);
    Vertex(const QVector3D &pos, const QVector2D &tex, const QVector3D &normal);

    void       setColor(const QColor &col);
    void       setNormal(const QVector3D &normal);
    void       setPos(const QVector3D &pos);
    void       setU(float val)  { mU = val; }
    void       setV(float val)  { mV = val; }
    void       setX(float val)  { mX = val; }
    void       setY(float val)  { mY = val; }
    void       setZ(float val)  { mZ = val; }
    float      x() const        { return mX; }
    float      y() const        { return mX; }
    float      z() const        { return mX; }

    float      green() const     { return mGreen; }
    float      blue()  const     { return mBlue; }
    QVector3D  normal()const     { return QVector3D(mNx, mNy, mNz); }
    float      nx() const        { return mNx; }
    float      ny() const        { return mNy; }
    float      nz() const        { return mNz; }
    QVector3D  pos() const       { return QVector3D(mX, mY, mZ); }
    float      red() const       {return mRed;}
    void       setNx(float val)  { mNx = val; }
    void       setNy(float val)  { mNy = val; }
    void       setNz(float val)  { mNz = val; }
    void       setTex(const QVector2D &tex);
    QVector2D  text()const       { return QVector2D(mU, mV); }
    float      u() const         { return mU; }
    float      v() const         { return mV; }

    Vertex& operator = (const Vertex &vertex);

private:
    float mX;      // x coordinate of the vertex
    float mY;      // y coordinate of the vertex
    float mZ;      // z coordinate of the vertex

    float mRed;    // red color weight of the vertex
    float mGreen;  // green color weight of the vertex
    float mBlue;   // blue color weight of the vertex

    float mU;      // x coordinate of the texture at this vertex
    float mV;      // y coordinate of the texture at this vertex

    float mNx;    // normal x direction at this vertex
    float mNy;    // normal y direction at this vertex
    float mNz;    // normal z direction at this vertex
};
}
#endif // VERTEX_H
