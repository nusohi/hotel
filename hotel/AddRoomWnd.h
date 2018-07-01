#pragma once
#include <QWidget>
#include <qtimer.h>
#include "ui_AddRoomWnd.h"
#include "Global.h"
#include "DataBase.h"
#include "Room.h"

extern DataBase<Room> roomDB;
extern int sumRoom[];



class AddRoomWnd : public QWidget
{
	Q_OBJECT

public:
	AddRoomWnd(QWidget *parent = Q_NULLPTR);
	~AddRoomWnd() {}
private:
	Ui::AddRoomWnd ui;
public slots:
	void addRoom();
	//提示信息	
	void showNote(QString note, QString color = "black", int time = 3000);
	void hideNote();
private:
	void initial();
	QTimer* timer;
};
