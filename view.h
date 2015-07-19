#ifndef VIEW_H
#define VIEW_H
#include <QOpenGLWindow>
#include <QOpenGLDebugLogger>
#include <QMatrix4x4>
#include "scene.h"
#include "rectmesh.h"
#include "cubemesh.h"
#include <QKeyEvent>
#include <QWheelEvent>

#include <QVariantAnimation>

namespace cgl{

class Scene;
class View;

class View : public QOpenGLWindow
{
    Q_OBJECT
public:
    View();

  void initializeGL();
  void paintGL();
  void resizeGL();

public slots:
  void setDebugger(bool active);

protected:
  void keyPressEvent(QKeyEvent * event);
  void mousePressEvent(QMouseEvent *);
  void mouseMoveEvent(QMouseEvent *);
  void mouseReleaseEvent(QMouseEvent*);
  void wheelEvent(QWheelEvent *);

protected slots:
  void printLog(const QOpenGLDebugMessage& msg);
   void anim(const QVariant& value);


private:
Scene * mScene;
CubeMesh * mesh;
QOpenGLDebugLogger * mLogger;
QVariantAnimation * mAnim;

QVector3D mCameraPos;
QVector3D mCameraFront;
QVector3D mCameraUp;

bool mClick;
QPointF mLastPos;
float mYaw;
float mPitch;
float mAspect;

};

}

#endif // VIEW_H
