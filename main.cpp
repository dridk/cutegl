#include <QGuiApplication>
#include "view.h"
#include "modelmesh.h"
int main(int argc, char **argv)
{
	QGuiApplication app(argc, argv);

    cgl::View view;
    view.show();



	app.exec();


	return 0;
}
