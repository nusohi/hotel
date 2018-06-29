#include <QtWidgets/QApplication>
#include <QVBoxLayout>
#include "hotel.h"
#include "RoomInfoTable.h"
#include "CheckInForm.h"
#include "BookerInfoTable.h"
#include "CheckInWnd.h"
#include "BillTable.h"

//全局变量
extern DataBase<Room> roomDB(".\\roomDB.dat");
extern DataBase<Bill> billDB(".\\billDB.dat");
extern int sumRoom[] = {
	roomDB.querySum(A),
	roomDB.querySum(B),
	roomDB.querySum(C)
};
extern int sumBill[] = {
	billDB.querySum(BOOKING),
	billDB.querySum(CHECKIN),
	billDB.querySum(DONE)
};




int main(int argc, char *argv[])
{
	QApplication YiTiaoDaHe(argc, argv);

	/*hotel w;
	w.show();*/

	/*CheckInWnd a;
	a.show();*/

	BillTable bill;
	bill.show();


	return YiTiaoDaHe.exec();
}
