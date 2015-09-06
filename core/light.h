#ifndef LIGHT_H
#define LIGHT_H
#include <QVector3D>
#include <QColor>
class Light
{
public:
    Light();

    QVector3D mPos;
    QColor mCol;

};

#endif // LIGHT_H
