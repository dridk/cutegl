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
    Vertex(float x, float y, float z, float u, float v, const QColor &col = Qt::white);
    Vertex(const QVector3D &pos, const QColor &col = Qt::white);
    Vertex(const QVector3D &pos, const QVector3D &norm, const QVector2D &tex, const QColor &col);

    void setColor(const QColor &col);
    void setNorm(const QVector3D &norm);
    void setPos(const QVector3D &pos);
    void setU(float val) { mU = val; }
    void setV(float val) { mV = val; }
    void setTex(const QVector2D &tex);


private:
    float mX;      // x coordinate of the vertex
    float mY;      // y coordinate of the vertex
    float mZ;      // z coordinate of the vertex

    float mRed;    // red color weight of the vertex
    float mGreen;  // green color weight of the vertex
    float mBlue;   // blue color weight of the vertex

    float mU;      // x coordinate of the texture at this vertex
    float mV;      // y coordinate of the texture at this vertex

    float mNormX;  // normal x direction at this vertex
    float mNormY;  // normal y direction at this vertex
    float mNormZ;  // normal z direction at this vertex
};
}
#endif // VERTEX_H
