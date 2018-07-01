#include <QtWidgets/QApplication>
#include "hotel.h"
#include "RoomInfoTable.h"
#include "CheckInForm.h"
#include "BookerInfoTable.h"
#include "CheckInWnd.h"
#include "BillTable.h"
#include "BossCtrl.h"
#include "LogInForm.h"
#include "AddRoomWnd.h"
#include "OuterTable.h"
#include "CheckOutForm.h"
#include "CheckOutWnd.h"
#include "DeleteRoomWnd.h"
#include "BossWnd.h"

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

	//CheckInForm f1; f1.show();
	//RoomInfoTable r1; r1.show();
	//BookerInfoTable b1; b1.show();
	///CheckInWnd c1; c1.show();
//
//	BillTable b2; b2.show();
////
//	AddRoomWnd add; add.show();
//	BossCtrl GOD; GOD.show();
//	LogInForm yi; yi.show();

	//OuterTable out; out.show();
	//CheckOutForm kk; kk.show();
	///CheckOutWnd oo; oo.show();

//	DeleteRoomWnd del; del.show();

	BossWnd bos; bos.show();

	return YiTiaoDaHe.exec();
}
