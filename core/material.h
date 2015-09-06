#ifndef MATERIAL_H
#define MATERIAL_H
#include <QVector3D>

class Material
{
public:
    Material();

    QVector3D mAmbient;
    QVector3D mDiffuse;
    QVector3D mSpecular;
    float mShininess;

};

#endif // MATERIAL_H
