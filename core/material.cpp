#include "material.h"

Material::Material()
{
    mAmbient =   QVector3D (1,1,1);
    mDiffuse =   QVector3D (1,1,1);
    mSpecular=   QVector3D (1,1,1);

    mShininess = 1;
}

