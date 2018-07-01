#pragma once
#include <QWidget>
#include <qscrollbar.h>
#include "ui_OuterTable.h"
#include "Global.h"
#include "DataBase.h"
#include "Bill.h"

extern int sumBill[];
extern DataBase<Bill> billDB;




class OuterTable : public QWidget
{
	Q_OBJECT

public:
	OuterTable(QWidget *parent = Q_NULLPTR);
	~OuterTable() {}
public:
	Ui::OuterTable ui;
public slots:
	void update();
private:
	void initial();
};
