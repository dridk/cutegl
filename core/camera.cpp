#include <QDebug>
#include "qmath.h"

#include "camera.h"
namespace cgl {
//===================================================================
Camera::Camera() : mEyePhi(0.0), mEyeR(50.0), mEyeTheta(0.0), mInc(10.0)
{
    // ctor

    setEyePosition();

    mEyeUp.setX(0.0);
    mEyeUp.setY(1.0);
    mEyeUp.setZ(0.0);
}

//===================================================================
void Camera::setEyePosition()
{
    // position the eye viewing the scene

   if (mEyePhi >= 89.9)
        mEyePhi = 89.9;
   if (mEyePhi <= -89.9)
        mEyePhi = -89.9;

    double rtheta = qDegreesToRadians(mEyeTheta);
    double rphi   = qDegreesToRadians(mEyePhi);

    double x = mEyeR * qSin(rtheta) * qCos(rphi);
    double z = mEyeR * qCos(rtheta) * qCos(rphi);
    double y = mEyeR * qSin(rphi);

    mEyePos.setX(x);
    mEyePos.setZ(z);
    mEyePos.setY(y);

    mViewCenter.setX(-x);
    mViewCenter.setY(-y);
    mViewCenter.setZ(-z);
    mViewCenter.normalize();
}
}
