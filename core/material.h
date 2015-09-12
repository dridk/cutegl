#ifndef MATERIAL_H
#define MATERIAL_H
#include <QVector3D>

class Material
{
public:
    Material();

    void setAmbient(const QVector3D& vec)  {mAmbient = vec;}
    void setDiffuse(const QVector3D& vec)  {mDiffuse = vec;}
    void setSpecular(const QVector3D& vec) { mSpecular = vec;}
    void setShininess(float val)           {mShininess = val;}


    const QVector3D& ambient() const       {return mAmbient;}
    const QVector3D& diffuse() const       {return mDiffuse;}
    const QVector3D& specular() const      {return mSpecular;}
    float shininess() const                {return mShininess;}


private:
    QVector3D mAmbient;    // raw color of the material
    QVector3D mDiffuse;    // diffused color by the material
    float     mShininess;  // what is that ?
    QVector3D mSpecular;   // what is that ?

};

#endif // MATERIAL_H
