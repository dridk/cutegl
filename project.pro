QT += gui 
CONFIG += c++11
SOURCES = main.cpp \
    view.cpp \
    scene.cpp \
    vertex.cpp \


TARGET  = cutegl 

RESOURCES += \
    shaders.qrc \
    textures.qrc \
    models.qrc

HEADERS += \
    view.h \
    scene.h \
    vertex.h \



include (meshs/meshs.pri)
INCLUDEPATH += meshs

