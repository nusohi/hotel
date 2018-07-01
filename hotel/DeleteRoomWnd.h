#pragma once
#include <QWidget>
#include <qtimer.h>
#include "ui_DeleteRoomWnd.h"
#include "DataBase.h"
#include "Room.h"

extern DataBase<Room> roomDB;
extern int sumRoom[];


class DeleteRoomWnd : public QWidget
{
	Q_OBJECT

public:
	DeleteRoomWnd(QWidget *parent = Q_NULLPTR);
	~DeleteRoomWnd() {}
public:
	Ui::DeleteRoomWnd ui;
public slots:
	//删除房间
	void deleteRoom();
	//提示信息	
	void showNote(QString note, QString color = "black", int time = 3000);
	void hideNote();
private:
	void initial();
	QTimer* timer;
};
