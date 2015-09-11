#ifndef CAMERA_H
#define CAMERA_H

#include <QVector3D>

namespace cgl {
class Camera
{
public:
    Camera();

    const QVector3D& position() const              { return mPos; }
    void             incPhi(short int sign = +1)   { mPhi = mPhi + sign * mInc; updatePosition(); }
    void             incTheta(short int sign = +1) { mTheta = mTheta + sign * mInc; updatePosition(); }
    void             incX(short int sign = +1)     { mPos.setX(mPos.x() + sign * mInc); }
    void             incY(short int sign = +1)     { mPos.setY(mPos.y() + sign * mInc); }
    void             setPhi(double val)            { mPhi   += val; updatePosition(); }
    void             setTheta(double val)          { mTheta += val; updatePosition(); }
    const QVector3D& up() const                    { return mUp; }
    const QVector3D& target() const                  { return mTarget; }
    void             zoom(short int sign = +1)     { mR = mR + sign * mInc; updatePosition();}

protected:
    void      updatePosition();

private:
    QVector3D          mPos;        //  position
    double             mPhi;        // azimuth angle of
    double             mR;          // distance of  from view center
    double             mTheta;      // polar angle of
    QVector3D          mUp;         // up direction with respect to
    double             mInc;        // incremental step of camera position
    QVector3D          mTarget; // center of the scene that the  is looking at

};
}
#endif // CAMERA_H
