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
    $$PWD/core/material.h \
    $$PWD/core/light.h

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
    $$PWD/core/material.cpp \
    $$PWD/core/light.cpp

RESOURCES += \
    $$PWD/shaders/shaders.qrc \
    $$PWD/models/models.qrc \
    $$PWD/textures/textures.qrc

DISTFILES +=

