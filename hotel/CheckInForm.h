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
	//�Ǽ���ס
	void checkIn();
	//Ԥ��
	void book();
	//Ԥ����Ǽ�
	void bookIn();
	//��˫��ť
	void onSingleClientBtn();
	void onDoubleClientBtn();
	//��Ԥ����ť
	void onCheckBookBox(int state);
	//���·���� ����������
	void updateRoomIDBox(int index);

	//��ʾ��Ϣ	
	void showNote(QString note, QString color = "black", int time = 3000);
	void hideNote();

public:
	void fillBill(Bill* bill);
	void fillRoom(RoomBase* room);

private:
	void initial();
	bool checkInputStatus();
	//��� Form
	void clearForm();
	//��ʱ��
	QTimer* timer;
};
