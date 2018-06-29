#pragma once
#include <QtWidgets/QWidget>
#include "ui_hotel.h"
#include "RoomInfoTable.h"
#include "Room.h"
#include "Bill.h"
#include "DataBase.h"



class hotel : public QWidget
{
	Q_OBJECT

public:
	hotel(QWidget *parent = Q_NULLPTR);

private:
	Ui::hotelClass ui;
};
