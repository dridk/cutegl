# CuteGL 
CuteGL is a high level OpenGL 3.3 library based on Qt5.5. It allows user to develop openGL application quickly and faster by using a 
Scene / View models similar than QGraphicsView and QGraphicsScene. 

# Architecture 
There are 3 class to render a basic 3d view. 

* cgl::View 
This class based on QWidget, is the openGL window. It manages view transformation from keyboard or mouse event, and the frame loop. 
You should be able to have many view for one scene. 

* cgl::Scene 
This class contains all meshs and lights to render to the view. It deals with Meshs creation and contains differents methods called from the view. 

* cgl::Mesh 
This class is a 3d object composed by vertex, normal, textures and material. They are different kind of mesh like BoxMesh or PlaneMesh.
You can design your own mesh by sub-classing it. 

# Exemple 
    #include <QGuiApplication>
    #include "view.h"
    #include "cubemesh.h"
    
    int main(int argc, char **argv)
    {
        QGuiApplication app(argc, argv);
        cgl::View view;
        cgl::CubeMesh * mesh2 = new cgl::CubeMesh(1,1,1);
        view.scene()->addMesh(mesh);
        view.show();
        return app.exec();
    }

# Installation and Use 
Actually cutegl is not a dynamics library. You can just copy the project and add from your *.pro file the following command : 

    include(cutegl/cutegl.pri)


