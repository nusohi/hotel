#include "hotel.h"

//ȫ�ֱ���
DataBase<Room> roomDB(".\\roomDB.dat");
DataBase<Bill> billDB(".\\billDB.dat");
int sumRoom[] = {
	roomDB.querySum(A),
	roomDB.querySum(B),
	roomDB.querySum(C)
};
int sumBill[] = {
	billDB.querySum(BOOKING),
	billDB.querySum(CHECKIN),
	billDB.querySum(DONE)
};



hotel::hotel(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}
