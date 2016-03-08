#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QOpenGLWindow>
#include <QOpenGLDebugLogger>
#include <QVector>
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
    virtual void scale(float updown);

private:
    void         keyPressEvent(QKeyEvent *event);
    void         mouseMoveEvent(QMouseEvent *event);
    void         mousePressEvent(QMouseEvent *event);
    void         wheelEvent(QWheelEvent *event);
    void         setContext(QOpenGLContext *context) { mContext = context; }
    void         toggleFullScreen();

    float                 mAspect;        // aspect ratio
    QOpenGLContext        *mContext;      // the context of the scene
    QOpenGLDebugLogger    *mDebugLogger;  // engine to log debug messages from QOpenGL
    bool                  mFullScreen;    // full screen mode yes or no
    QPointF               mMousePosition; // current position of the mouse
    bool                  mMouseClicked;  // mose clicked yes or no
    bool                  mOpacity;       // opacity set or not
    QTimer                *mTimer;        // timer to control the screen refresment
    Scene                 *mScene;        // the container of the objects to be drawn
};
}
#endif // VIEW_H
