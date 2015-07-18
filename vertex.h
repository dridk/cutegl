#ifndef VERTEX_H
#define VERTEX_H

#include <QColor>
#include <QVector2D>
namespace cgl{
class Vertex
{
public:
    enum {
        VERTEX_OFFSET  = 0,
        COLOR_OFFSET   = 4*3,
        TEXTURE_OFFSET = 4*6
    };
    Vertex(float x, float y, float z);
    Vertex(float x, float y, float z, const QColor& col);
    Vertex(float x, float y, float z, const QColor& col, const QPointF& texCoord);
    Vertex();

    float x() const;
    float y() const;
    float z() const;

    QColor color() const;
    QPointF texCoord() const;




private:
    float mX;
    float mY;
    float mZ;

    float mRed;
    float mGreen;
    float mBlue;

    float mTexCoordX;
    float mTexCoordY;
};
}

#endif // VERTEX_H
