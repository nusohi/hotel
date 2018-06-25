#include "hotel.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	hotel w;
	w.show();
	return a.exec();
}
