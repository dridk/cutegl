#ifndef VIEWOBJECT_H
#define VIEWOBJECT_H

#include <QObject>

#include "mesh.h"

namespace cgl {
class ViewObject : public QObject
{
    Q_OBJECT
public:
    explicit ViewObject(QObject *parent = 0);
    ~ViewObject();

    void setOpacity(float opa);

protected:
    virtual void create() = 0;

    QList<cgl::Mesh*> mElements;           // list of meshes needed to build ALICE
    QVector<QString>  mElementsName;       // name of the various elements

public slots:
};
}
#endif // VIEWOBJECT_H
