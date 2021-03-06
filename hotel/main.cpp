﻿#include <QtWidgets/QApplication>
#include "hotel.h"

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
	hotel BoLangKuan;
	BoLangKuan.setWindowTitle(u8"宾馆住宿管理系统");	//密码123123
	QIcon icon(".\\hi.ico");
	BoLangKuan.setWindowIcon(icon);
	BoLangKuan.show();
	return YiTiaoDaHe.exec();
}

