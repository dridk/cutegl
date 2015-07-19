QT += gui 
CONFIG += c++11
SOURCES = main.cpp \
    view.cpp \
    scene.cpp \
    mesh.cpp \
    cubemesh.cpp \
    vertex.cpp \
    axismesh.cpp \
    modelmesh.cpp \
    modelloader.cpp \
    planemesh.cpp
TARGET  = cutegl 

RESOURCES += \
    shaders.qrc \
    textures.qrc \
    models.qrc

HEADERS += \
    view.h \
    scene.h \
    mesh.h \
    cubemesh.h \
    vertex.h \
    axismesh.h \
    modelmesh.h \
    modelloader.h \
    planemesh.h

