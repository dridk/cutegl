QT += gui 
CONFIG += c++11
SOURCES = main.cpp \
    view.cpp \
    scene.cpp \
    mesh.cpp \
    rectmesh.cpp
TARGET  = cutegl 

RESOURCES += \
    shaders.qrc

HEADERS += \
    view.h \
    scene.h \
    mesh.h \
    rectmesh.h

