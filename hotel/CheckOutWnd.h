#pragma once
#include <qwidget.h>
#include <QVBoxLayout>
#include "CheckOutForm.h"
#include "OuterTable.h"
#include "Bill.h"
#include "DataBase.h"

extern DataBase<Bill> billDB;



class CheckOutWnd :public QWidget
{
	Q_OBJECT

public:
	CheckOutWnd(QWidget* parent = NULL);
	~CheckOutWnd() {}
public slots:
	void chooseBill(int row, int col);

public:
	CheckOutForm checkOutForm;
	OuterTable outerTable;
	QVBoxLayout* layout;
};

