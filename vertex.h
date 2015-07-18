#ifndef VERTEX_H
#define VERTEX_H

#include <QColor>
namespace cgl{
class Vertex
{
public:
    Vertex(float x, float y, float z);
    Vertex(float x, float y, float z, const QColor& col);
    Vertex();

    float x() const;
    float y() const;
    float z() const;


private:
    float mX;
    float mY;
    float mZ;

    float mRed;
    float mGreen;
    float mBlue;
};
}

#endif // VERTEX_H
