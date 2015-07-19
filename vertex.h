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
    Vertex();
    Vertex(float x, float y, float z, const QColor& col = Qt::blue);
    Vertex(const QVector3D& coord, const QColor& col = Qt::blue);
    Vertex(const QVector3D& coord, const QVector3D& normal, const QVector2D& texCoord, const QColor& col = Qt::white);




    void setCoord(const QVector3D& coord);
    void setNormal(const QVector3D& normal);
    void setTexCoord(const QVector2D& texCoord);
    void setColor(const QColor& col);

    float x() const;
    float y() const;
    float z() const;
    float normalX() const;
    float normalY() const;
    float normalZ() const;
    QColor color() const;
    QVector2D texCoord() const;


private:
    // WARNING : DO NOT CHANGE ORDER OF PARAMETERS ..
    // THOSE ARE BE USED BY OPENGL BUFFER ALLOCATION
    float mX;
    float mY;
    float mZ;

    float mRed;
    float mGreen;
    float mBlue;

    float mTexCoordX;
    float mTexCoordY;

//    float mNormalX;
//    float mNormalY;
//    float mNormalZ;
};
}

#endif // VERTEX_H
