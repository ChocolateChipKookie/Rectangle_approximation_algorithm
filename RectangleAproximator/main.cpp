#include "RectangleAproximator.h"
#include <QtWidgets/QApplication>
#include "image.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RectangleAproximator w;
	w.show();
	return a.exec();
}
