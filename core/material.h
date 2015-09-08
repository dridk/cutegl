#ifndef MATERIAL_H
#define MATERIAL_H
#include <QVector3D>

class Material
{
public:
    Material();

    QVector3D mAmbient;    // raw color of the material
    QVector3D mDiffuse;    // diffused color by the material
    float     mShininess;  // what is that ?
    QVector3D mSpecular;   // what is that ?

};

#endif // MATERIAL_H
