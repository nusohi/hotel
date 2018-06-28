#include <QtWidgets/QApplication>
#include "hotel.h"
#include "RoomInfoTable.h"
#include "CheckInForm.h"




int main(int argc, char *argv[])
{
	QApplication YiTiaoDaHe(argc, argv);
	hotel w;
	w.show();
	RoomInfoTable r; r.show();
	CheckInForm   c; c.show();
	return YiTiaoDaHe.exec();
}
