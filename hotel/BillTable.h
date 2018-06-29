#pragma once
#include <QWidget>
#include <qscrollbar.h>
#include "ui_BillTable.h"
#include "Global.h"
#include "Bill.h"
#include "DataBase.h"

extern DataBase<Bill> billDB;
extern int sumBill[];



class BillTable : public QWidget
{
	Q_OBJECT

public:
	BillTable(QWidget *parent = Q_NULLPTR);
	~BillTable() {}
public:
	Ui::BillTable ui;

public slots:
	void update(int index);

private:
	void initial();
};
