#pragma once
#include <qwidget.h>
#include <qboxlayout.h>
#include "BossCtrl.h"
#include "LogInForm.h"
#include "BillTable.h"
#include "AddRoomWnd.h"
#include "DeleteRoomWnd.h"
#include "RoomInfoTable.h"

extern DataBase<Room> roomDB;



class BossWnd :public QWidget
{
	Q_OBJECT

public:
	BossWnd(QWidget* parent = NULL);
	~BossWnd() {}
public slots:
	//��¼
	void signIn();
	void signOut();
	//��䷿���
	void chooseRoom(int row, int col);
	//�л�ģʽ
	void billModelOn();
	void billModelOff();
	void roomModelOn();
	void roomModelOff();

private:
	void initial();
	//��ʾ������
	void showBillTable();
	void hideBillTable();
	void showRoomCtrl();
	void hideRoomCtrl();

private:
	LogInForm logInForm;
	BossCtrl bossCtrl;
	BillTable billTable;
	RoomInfoTable roomInfoTable;
	AddRoomWnd addRoomWnd;
	DeleteRoomWnd deleteRoomWnd;

	QVBoxLayout* layout;
	QVBoxLayout* roomLayout;
	QHBoxLayout* headLayout;
	QHBoxLayout* footLayout;

	QSpacerItem* headSpacerL;
	QSpacerItem* headSpacerR;
};
