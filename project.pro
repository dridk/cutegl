QT += gui 
CONFIG += c++11
SOURCES = main.cpp \
    view.cpp \
    scene.cpp \
    mesh.cpp \
    rectmesh.cpp \
    cubemesh.cpp \
    vertex.cpp \
    axismesh.cpp
TARGET  = cutegl 

RESOURCES += \
    shaders.qrc \
    textures.qrc

HEADERS += \
    view.h \
    scene.h \
    mesh.h \
    rectmesh.h \
    cubemesh.h \
    vertex.h \
    axismesh.h

