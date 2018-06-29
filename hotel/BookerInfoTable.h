#pragma once
#include <QWidget>
#include "ui_BookerInfoTable.h"
#include "Global.h"
#include "Bill.h"
#include "DataBase.h"

extern DataBase<Bill> billDB;
extern int sumBill[];



class BookerInfoTable : public QWidget
{
	Q_OBJECT

public:
	BookerInfoTable(QWidget *parent = Q_NULLPTR);
	~BookerInfoTable();
private:
	Ui::BookerInfoTable ui;
private:
	void initial();
public slots:
	void update();

};

