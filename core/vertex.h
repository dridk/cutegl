#ifndef VERTEX_H
#define VERTEX_H

#include <QColor>
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

    void setColor(const QColor &col);
    void setNormal(const QVector3D &normal);
    void setPos(const QVector3D &pos);
    void setTex(const QVector2D &tex);

    void setU(float val) { mU = val; }
    void setV(float val) { mV = val; }
    void setX(float val) { mX = val; }
    void setY(float val) { mY = val; }
    void setNx(float val) { mNx = val; }
    void setNy(float val) { mNy = val; }
    void setNz(float val) { mNz = val; }

    float x() const {return mX;}
    float y() const {return mX;}
    float z() const {return mX;}

    float red() const   {return mRed;}
    float green() const {return mGreen;}
    float blue() const  {return mBlue;}

    float u() const {return mU;}
    float v() const {return mV;}

    float nx() const {return mNx;}
    float ny() const {return mNy;}
    float nz() const {return mNz;}

    QVector3D pos() const;
    QVector2D text() const;
    QVector3D normal() const;





private:
    float mX;      // x coordinate of the vertex
    float mY;      // y coordinate of the vertex
    float mZ;      // z coordinate of the vertex

    float mRed;    // red color weight of the vertex
    float mGreen;  // green color weight of the vertex
    float mBlue;   // blue color weight of the vertex

    float mU;      // x coordinate of the texture at this vertex
    float mV;      // y coordinate of the texture at this vertex

    float mNx;  // normal x direction at this vertex
    float mNy;  // normal y direction at this vertex
    float mNz;  // normal z direction at this vertex
};
}
#endif // VERTEX_H
