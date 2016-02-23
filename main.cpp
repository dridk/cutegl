#include <QGuiApplication>
#include "view.h"
#include "modelmesh.h"
#include "cubemesh.h"
int main(int argc, char **argv)
{
	QGuiApplication app(argc, argv);

    cgl::View view;


    cgl::ModelMesh * mesh = new cgl::ModelMesh("/Users/schutz/desktop/test.obj");


//    cgl::CubeMesh * mesh2 = new cgl::CubeMesh(1,1,1);

//    mesh2->translate(5,5,0);

//    mesh->setOpacity(0.5);
    view.scene()->addMesh(mesh);
//    view.scene()->addMesh(mesh2);


    view.show();
    app.exec();


	return 0;
}
