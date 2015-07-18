#ifndef VIEW_H
#define VIEW_H
#include <QOpenGLWindow>
#include <QOpenGLDebugLogger>
#include <QMatrix4x4>
#include "scene.h"
#include "rectmesh.h"
#include "cubemesh.h"
#include <QKeyEvent>
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

protected slots:
  void printLog(const QOpenGLDebugMessage& msg);




private:
Scene * mScene;
CubeMesh * mesh;
QOpenGLDebugLogger * mLogger;



};

}

#endif // VIEW_H
