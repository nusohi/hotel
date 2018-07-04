/***********************************************************

		ZFY

***********************************************************/
#pragma once
#include <QWidget>
#include <qscrollbar.h>
#include "ui_RoomInfoTable.h"
#include "Room.h"
#include "DataBase.h"

extern DataBase<Room> roomDB;
extern int sumRoom[];



class RoomInfoTable : public QWidget
{
	Q_OBJECT

public:
	RoomInfoTable(QWidget *parent = Q_NULLPTR);
	~RoomInfoTable() {}
public:
	Ui::RoomInfoTable ui;

public slots:
	void update(int index);
	void refresh();

private:
	void initial();
};

