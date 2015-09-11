#include <QDebug>
#include "qmath.h"

#include "camera.h"
namespace cgl {
//===================================================================
Camera::Camera() : mPhi(0.0), mR(50.0), mTheta(0.0), mInc(10.0)
{
    // ctor

    updatePosition();

    mUp.setX(0.0);
    mUp.setY(1.0);
    mUp.setZ(0.0);
}

//===================================================================
void Camera::updatePosition()
{
    // position the  viewing the scene

   if (mPhi >= 89.9)
        mPhi = 89.9;
   if (mPhi <= -89.9)
        mPhi = -89.9;

    double rtheta = qDegreesToRadians(mTheta);
    double rphi   = qDegreesToRadians(mPhi);

    double x = mR * qSin(rtheta) * qCos(rphi);
    double z = mR * qCos(rtheta) * qCos(rphi);
    double y = mR * qSin(rphi);

    mPos.setX(x);
    mPos.setZ(z);
    mPos.setY(y);

    mViewCenter.setX(-x);
    mViewCenter.setY(-y);
    mViewCenter.setZ(-z);
    mViewCenter.normalize();
}
}
