#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QOpenGLWindow>
#include <QOpenGLDebugLogger>
#include <QVector3D>

class QOpenGLContext;
class QPointF;
class QTimer;

#include "scene.h"
namespace cgl {
class View : public QOpenGLWindow
{

    Q_OBJECT

public:
    View(int refreshRate = 1000);

    Scene *scene() const         { return mScene; }
    void setScene(Scene *scene)  { mScene = scene; }


private slots:
    void setDebugger(bool active);
    void timeOutSlot();

protected slots:
    void printLog(const QOpenGLDebugMessage &msg);

protected:
    void         initializeGL();
    void         paintGL();
    void         resizeGL(int w, int h);

private:
    void         keyPressEvent(QKeyEvent *event);
    void         mouseMoveEvent(QMouseEvent *event);
    void         mousePressEvent(QMouseEvent *);
    void         setContext(QOpenGLContext *context) { mContext = context; }
    void         setEyePosition();
    void         toggleFullScreen();

    float              mAspect;        // aspect ratio
    QVector3D          mViewCenter;    // center of view tha the eye is looking at
    QVector3D          mEyePos;        // eye position
    double             mEyePhi;        // azimuth angle of eye
    double             mEyeR;          // distance of eye from view center
    double             mEyeTheta;      // polar angle of eye
    QVector3D          mEyeUp;         // up direction with respect to eye
    QOpenGLContext     *mContext;      // the context of the scene
    QOpenGLDebugLogger *mDebugLogger;  // engine to log debug messages from QOpenGL
    bool               mFullScreen;    // full screen mode yes or no
    QPointF            mMousePosition; // current position of the mouse
    bool               mMouseClicked;  // mose clicked yes or no
    QTimer             *mTimer;        // timer to control the screen refresment
    Scene              *mScene;        // the container of the objects to be drawn

};
}
#endif // VIEW_H
