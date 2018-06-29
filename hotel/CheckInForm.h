#pragma once
#include <QWidget>
#include "ui_CheckInForm.h"
#include "Bill.h"
#include "Room.h"
#include "Client.h"
#include "DataBase.h"

extern DataBase<Bill> billDB;
extern DataBase<Room> roomDB;
extern int sumRoom[];
extern int sumBill[];



class CheckInForm : public QWidget
{
	Q_OBJECT

public:
	CheckInForm(QWidget *parent = Q_NULLPTR);
	~CheckInForm() { delete timer; }
public:
	Ui::CheckInForm ui;


public slots:
	//登记入住
	void checkIn();
	//预订
	void book();
	//预订后登记
	void bookIn();
	//单双按钮
	void onSingleClientBtn();
	void onDoubleClientBtn();
	//已预订按钮
	void onCheckBookBox(int state);
	//更新房间号 （和余量）
	void updateRoomIDBox(int index);

	//提示信息	
	void showNote(QString note, QString color = "black", int time = 3000);
	void hideNote();

public:
	void fillBill(Bill* bill);
	void fillRoom(RoomBase* room);

private:
	void initial();
	bool checkInputStatus();
	//清除 Form
	void clearForm();
	//计时器
	QTimer* timer;
};
