#include <QGuiApplication>
#include "view.h"
#include "modelmesh.h"
#include "cubemesh.h"
int main(int argc, char **argv)
{
	QGuiApplication app(argc, argv);

    cgl::View view;
    view.show();


    cgl::CubeMesh * mesh = new cgl::CubeMesh(1,1,1);

    cgl::CubeMesh * mesh2 = new cgl::CubeMesh(1,1,1);

    mesh2->translate(5,5,0);


    view.scene()->addMesh(mesh);
    view.scene()->addMesh(mesh2);


	app.exec();


	return 0;
}
