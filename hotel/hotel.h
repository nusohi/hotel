#pragma once
#include <QtWidgets/QWidget>
#include <qboxlayout.h>
#include "ui_hotel.h"
#include "HeadMenu.h"
#include "CheckInWnd.h"
#include "CheckOutWnd.h"
#include "BossWnd.h"



class hotel : public QWidget
{
	Q_OBJECT

public:
	hotel(QWidget *parent = Q_NULLPTR);
private:
	Ui::hotelClass ui;

public slots:
	void change();
private:
	void initial();
	void inPartModel();
	void outPartModel();
	void bossPartModel();
private:
	HeadMenu headMenu;
	CheckInWnd checkInWnd;
	CheckOutWnd checkOutWnd;
	BossWnd bossWnd;

	QVBoxLayout* layout;
};

