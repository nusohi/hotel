#pragma once
#include <QWidget>
#include <qscrollbar.h>
#include "ui_RoomInfoTable.h"
#include "Room.h"
#include "DataBase.h"



class RoomInfoTable : public QWidget
{
	Q_OBJECT

public:
	RoomInfoTable(QWidget *parent = Q_NULLPTR);
	~RoomInfoTable() {}
private:
	Ui::RoomInfoTable ui;
public:
	void initial();
public slots:
	void update(int index);
};

