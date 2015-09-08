#include "material.h"

//===================================================================
Material::Material() :
    mAmbient(QVector3D (0.5,0.5,0.5)), mDiffuse(QVector3D (1,1,1)), mShininess(1.0), mSpecular(QVector3D (1,1,1))
{
    // ctor
}

