#pragma once
#include <QWidget>
#include <qtimer.h>
#include "ui_CheckOutForm.h"
#include "DataBase.h"
#include "Bill.h"
#include "Room.h"

extern DataBase<Bill> billDB;
extern DataBase<Room> roomDB;
extern int sumBill[];




class CheckOutForm : public QWidget
{
	Q_OBJECT

public:
	CheckOutForm(QWidget *parent = Q_NULLPTR);
	~CheckOutForm() {}
private:
	Ui::CheckOutForm ui;
public slots:
	void checkOut();
	void fillBill(Bill* bill);
	//提示信息
	void showNote(QString note, QString color = "black", int time = 3000);
	void hideNote();

private:
	void initial();
	//计时器
	QTimer* timer;
};
