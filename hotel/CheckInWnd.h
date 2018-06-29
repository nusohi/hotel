#pragma once
#include <qwidget.h>
#include <QVBoxLayout>
#include "CheckInForm.h"
#include "RoomInfoTable.h"
#include "BookerInfoTable.h"


class CheckInWnd :public QWidget
{
	Q_OBJECT

public:
	CheckInWnd(QWidget* parent = NULL);
	~CheckInWnd() {}

public:
	CheckInForm checkInForm;
	RoomInfoTable roomInfoTable;
	BookerInfoTable bookerInfoTable;
	QVBoxLayout* layout;
};

