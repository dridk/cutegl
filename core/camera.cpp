#include <QDebug>
#include "qmath.h"

#include "camera.h"
namespace cgl {
//===================================================================
Camera::Camera()
{
    // ctor

    reset();
}

//===================================================================
void Camera::reset()
{
    // sets the camera at (0, 0, z) pointing to (0, 0, -z) and up being y direction

    mDeltaX =  0.0;
    mDeltaY =  0.0;
    mInc    = 10.0;
    mPhi    =  0.0;
    mR      = 50.0;
    mTheta  =  0.0;

    mUp.setX(0.0);
    mUp.setY(1.0);
    mUp.setZ(0.0);

    updatePosition();
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

    mTarget.setX(-x + mDeltaX);
    mTarget.setY(-y + mDeltaY);
    mTarget.setZ(-z);
    mTarget.normalize();
}
}
