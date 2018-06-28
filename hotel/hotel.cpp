#include "hotel.h"

//全局变量
DataBase<Room> roomDB(".\\roomDB.dat");
DataBase<Bill> billDB(".\\billDB.dat");
int sumRoom[] = {
	roomDB.querySum(RoomType(0)),
	roomDB.querySum(RoomType(1)),
	roomDB.querySum(RoomType(2))
};



hotel::hotel(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}
