#include <QtWidgets/QApplication>
#include <QVBoxLayout>
#include "hotel.h"
#include "RoomInfoTable.h"
#include "CheckInForm.h"
#include "BookerInfoTable.h"
#include "CheckInWnd.h"
#include "BillTable.h"
#include "BossCtrl.h"
#include "LogInForm.h"
#include "AddRoomWnd.h"

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

	RoomInfoTable r1; r1.show();
	CheckInForm f1; f1.show();
	BookerInfoTable b1; b1.show();
	CheckInWnd c1; c1.show();
	BillTable b2; b2.show();

	BossCtrl GOD;
	GOD.show();

	LogInForm yi;
	yi.show();

	AddRoomWnd add;
	add.show();


	return YiTiaoDaHe.exec();
}
