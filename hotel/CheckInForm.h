#pragma once
#include <QWidget>
#include "ui_CheckInForm.h"
#include "Bill.h"
#include "Room.h"
#include "Client.h"
#include "DataBase.h"



class CheckInForm : public QWidget
{
	Q_OBJECT

public:
	CheckInForm(QWidget *parent = Q_NULLPTR);
	~CheckInForm() {}
private:
	Ui::CheckInForm ui;


public slots:
	//登记入住
	void checkIn();
	//预订
	void book();
	//单双按钮
	void onSingleClientBtn();
	void onDoubleClientBtn();
	//已预订按钮
	void onCheckBookBox(int state);
	//更新房间号 （和余量）
	void updateRoomIDBox(int index);

	void hideNote();

private:
	void initial();
	bool checkInputStatus();
	//清除 Form
	void clearForm();
	//提示信息	
	void showNote(QString note, QString color = "black", int time = 3000);
	//计时器
	QTimer* timer;
};
