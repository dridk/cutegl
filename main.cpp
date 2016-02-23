#include <QGuiApplication>
#include "view.h"
#include "modelmesh.h"
#include "cubemesh.h"
int main(int argc, char **argv)
{
	QGuiApplication app(argc, argv);

    cgl::View view;
    view.show();

    cgl::CubeMesh * mesh = new cgl::CubeMesh(10,10,10);

    view.scene()->addMesh(mesh);


	app.exec();


	return 0;
}
