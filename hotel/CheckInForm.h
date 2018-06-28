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
	//�Ǽ���ס
	void checkIn();
	//Ԥ��
	void book();
	//��˫��ť
	void onSingleClientBtn();
	void onDoubleClientBtn();
	//��Ԥ����ť
	void onCheckBookBox(int state);
	//���·���� ����������
	void updateRoomIDBox(int index);

	void hideNote();

private:
	void initial();
	bool checkInputStatus();
	//��� Form
	void clearForm();
	//��ʾ��Ϣ	
	void showNote(QString note, QString color = "black", int time = 3000);
	//��ʱ��
	QTimer* timer;
};
