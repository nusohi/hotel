#include <QtWidgets/QApplication>
#include <QVBoxLayout>
#include "hotel.h"
#include "RoomInfoTable.h"
#include "CheckInForm.h"
#include "BookerInfoTable.h"
#include "CheckInWnd.h"




int main(int argc, char *argv[])
{
	QApplication YiTiaoDaHe(argc, argv);
	/*hotel w;
	w.show();


	BookerInfoTable abcd;
	abcd.show();

	RoomInfoTable a;
	a.show();

	CheckInForm as;
	as.show();*/
	CheckInWnd a;
	a.show();


	return YiTiaoDaHe.exec();
}
