#ifndef MATERIAL_H
#define MATERIAL_H
#include <QVector3D>

class Material
{
public:
    Material();

    QVector3D mAmbient;    // what is that ?
    QVector3D mDiffuse;    // what is that ?
    float     mShininess;  // what is that ?
    QVector3D mSpecular;   // what is that ?

};

#endif // MATERIAL_H
