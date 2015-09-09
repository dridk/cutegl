#ifndef CAMERA_H
#define CAMERA_H

#include <QVector3D>

namespace cgl {
class Camera
{
public:
    Camera();

    const QVector3D& eye() const                      { return mEyePos; }
    void             incEyePhi(short int sign = +1)   { mEyePhi = mEyePhi + sign * mInc; setEyePosition(); }
    void             incEyeTheta(short int sign = +1) { mEyeTheta = mEyeTheta + sign * mInc; setEyePosition(); }
    void             incX(short int sign = +1)        { mEyePos.setX(mEyePos.x() + sign * mInc); }
    void             incY(short int sign = +1)        { mEyePos.setY(mEyePos.y() + sign * mInc); }
    void             setEyePhi(double val)            { mEyePhi   += val; setEyePosition(); }
    void             setEyeTheta(double val)          { mEyeTheta += val; setEyePosition(); }
    const QVector3D& up() const                       { return mEyeUp; }
    const QVector3D& view() const                     { return mViewCenter; }
    void             zoom(short int sign = +1)        { mEyeR = mEyeR + sign * mInc; setEyePosition();}

private:
    void      setEyePosition();

    QVector3D          mEyePos;        // eye position
    double             mEyePhi;        // azimuth angle of eye
    double             mEyeR;          // distance of eye from view center
    double             mEyeTheta;      // polar angle of eye
    QVector3D          mEyeUp;         // up direction with respect to eye
    double             mInc;           // incremental step of camera position
    QVector3D          mViewCenter;    // center of the scene that the eye is looking at

};
}
#endif // CAMERA_H
