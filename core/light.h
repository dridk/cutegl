#ifndef LIGHT_H
#define LIGHT_H
#include <QVector3D>
#include <QColor>
class Light
{
public:
    Light(const QVector3D& pos, const QColor& col = Qt::white);
    Light(float x, float y, float z, const QColor& col = Qt::white);
    const QVector3D& position() const;
    const QVector3D& colorVector() const;
    QColor color() const;

    void setPosition(const QVector3D& pos);


private:

    QVector3D mPos;
    QVector3D mColVector;


};

#endif // LIGHT_H
