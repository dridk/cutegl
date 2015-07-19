#ifndef VERTEX_H
#define VERTEX_H

#include <QColor>
#include <QVector2D>
#include <QVector3D>
namespace cgl{
class Vertex
{
public:
    enum {
        VERTEX_OFFSET  = 0,
        COLOR_OFFSET   = 4*3,
        TEXTURE_OFFSET = 4*6,
        NORMAL_OFFSET  = 4*9
    };
    Vertex(float x, float y, float z);
    Vertex(const QVector3D& vertex);
    Vertex(const QVector3D &vertex, const QVector3D& normal, const QVector2D& texCoord, const QColor& col);
    Vertex(float x, float y, float z, const QColor& col);
    Vertex(float x, float y, float z, const QColor& col, const QVector2D& texCoord);

    Vertex();

    float x() const;
    float y() const;
    float z() const;

    float normalX() const;
    float normalY() const;
    float normalZ() const;

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

    float mNormalX;
    float mNormalY;
    float mNormalZ;
};
}

#endif // VERTEX_H
