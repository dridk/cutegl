INCLUDEPATH+=$$PWD/core
INCLUDEPATH+=$$PWD/meshs

HEADERS += \
    $$PWD/core/view.h \
    $$PWD/core/vertex.h \
    $$PWD/core/scene.h \
    $$PWD/core/mesh.h \
#    $$PWD/meshs/trianglemesh.h \
#    $$PWD/meshs/spheremesh.h \
#    $$PWD/meshs/polygonmesh.h \
#    $$PWD/meshs/planemesh.h \
#    $$PWD/meshs/modelmesh.h \
#    $$PWD/meshs/modelloader.h \
#    $$PWD/meshs/cubemesh.h \
#    $$PWD/meshs/axismesh.h \
#    $$PWD/meshs/annulusmesh.h
    $$PWD/meshs/spheremesh.h \
    $$PWD/meshs/cylindermesh.h \
    $$PWD/meshs/annulusmesh.h \
    $$PWD/meshs/polygonmesh.h \
    $$PWD/meshs/cubemesh.h \
    $$PWD/meshs/modelloader.h \
    $$PWD/meshs/modelmesh.h \
    $$PWD/meshs/planemesh.h \
    $$PWD/meshs/tubemesh.h \
    $$PWD/meshs/parallelogrammesh.h \
    $$PWD/meshs/trianglemesh.h \
    $$PWD/core/material.h \
    $$PWD/core/light.h \
    $$PWD/core/camera.h \
    $$PWD/meshs/torusmesh.h \
    $$PWD/core/manymesh.h \
    $$PWD/core/viewobject.h


SOURCES += \
    $$PWD/core/view.cpp \
    $$PWD/core/vertex.cpp \
    $$PWD/core/scene.cpp \
    $$PWD/core/mesh.cpp \
#    $$PWD/meshs/trianglemesh.cpp \
#    $$PWD/meshs/spheremesh.cpp \
#    $$PWD/meshs/polygonmesh.cpp \
#    $$PWD/meshs/planemesh.cpp \
#    $$PWD/meshs/modelmesh.cpp \
#    $$PWD/meshs/modelloader.cpp \
#    $$PWD/meshs/cubemesh.cpp \
#    $$PWD/meshs/axismesh.cpp \
#    $$PWD/meshs/annulusmesh.cpp
    $$PWD/meshs/spheremesh.cpp \
    $$PWD/meshs/cylindermesh.cpp \
    $$PWD/meshs/annulusmesh.cpp \
    $$PWD/meshs/polygonmesh.cpp \
    $$PWD/meshs/cubemesh.cpp \
    $$PWD/meshs/modelloader.cpp \
    $$PWD/meshs/modelmesh.cpp \
    $$PWD/meshs/planemesh.cpp \
    $$PWD/meshs/tubemesh.cpp \
    $$PWD/meshs/parallelogrammesh.cpp \
    $$PWD/meshs/trianglemesh.cpp\
    $$PWD/core/material.cpp \
    $$PWD/core/light.cpp \
    $$PWD/core/camera.cpp \
    $$PWD/meshs/torusmesh.cpp \
    $$PWD/core/manymesh.cpp \
    $$PWD/core/viewobject.cpp

RESOURCES += \
    $$PWD/shaders/shaders.qrc \
    $$PWD/models/models.qrc \
    $$PWD/textures/tex.qrc

DISTFILES +=

