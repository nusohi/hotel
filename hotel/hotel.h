#pragma once
#include <QtWidgets/QWidget>
#include "ui_hotel.h"
#include "RoomInfoTable.h"
#include "Room.h"
#include "Bill.h"
#include "DataBase.h"


//全局变量
extern DataBase<Room> roomDB;
extern DataBase<Bill> billDB;
extern int sumRoom[];


class hotel : public QWidget
{
	Q_OBJECT

public:
	hotel(QWidget *parent = Q_NULLPTR);

private:
	Ui::hotelClass ui;
///	RoomInfoTable roomInfoTable;
};
