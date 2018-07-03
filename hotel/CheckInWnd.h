#pragma once
#include <qwidget.h>
#include <QVBoxLayout>
#include "CheckInForm.h"
#include "RoomInfoTable.h"
#include "BookerInfoTable.h"

extern DataBase<Bill> billDB;
extern DataBase<Room> roomDB;



class CheckInWnd :public QWidget
{
	Q_OBJECT

public:
	CheckInWnd(QWidget* parent = NULL);
	~CheckInWnd() {}
public slots:
	void refresh();
	void onChangeModel(int state);
	void chooseRoom(int row, int col);
	void chooseBill(int row, int col);

public:
	CheckInForm checkInForm;
	RoomInfoTable roomInfoTable;
	BookerInfoTable bookerInfoTable;
	QVBoxLayout* layout;
};

