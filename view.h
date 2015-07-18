#ifndef VIEW_H
#define VIEW_H
#include <QOpenGLWindow>
#include <QOpenGLDebugLogger>
#include <QMatrix4x4>
#include "scene.h"
#include "rectmesh.h"
#include "cubemesh.h"
#include <QKeyEvent>

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

protected slots:
  void printLog(const QOpenGLDebugMessage& msg);

    void anim(const QVariant& value);


private:
Scene * mScene;
CubeMesh * mesh;
QOpenGLDebugLogger * mLogger;
QVariantAnimation * mAnim;
QVector3D mCamera;

bool mClick;
QPoint oldPos;
float angle;

};

}

#endif // VIEW_H
