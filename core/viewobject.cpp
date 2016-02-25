#include "viewobject.h"

namespace cgl {
//===================================================================
ViewObject::ViewObject(QObject *parent) : QObject(parent)
{

}

//===================================================================
ViewObject::~ViewObject()
{
    //dtor
    qDeleteAll(mElements.begin(), mElements.end());
    mElements.clear();
}

//===================================================================
void ViewObject::setOpacity(float opa)
{
    // set the opacity of all the meshes

    for (int index = 0; index < mElements.size(); index++)
        mElements.at(index)->setOpacity(opa);
}

}
