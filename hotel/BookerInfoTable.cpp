#include "BookerInfoTable.h"



BookerInfoTable::BookerInfoTable(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initial();
	update();
}

BookerInfoTable::~BookerInfoTable()
{
}

void BookerInfoTable::initial() {
	//初始化表格设置
	ui.bookerTable->setRowCount(sumBill[BOOKING]);
	ui.bookerTable->setSelectionBehavior(QAbstractItemView::SelectRows);	//选择整行
	ui.bookerTable->setEditTriggers(QAbstractItemView::NoEditTriggers);		//禁止编辑表格
	ui.bookerTable->verticalHeader()->setVisible(false);
	ui.bookerTable->horizontalHeader()->setVisible(true);
	ui.bookerTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void BookerInfoTable::update() {
	int sum = sumBill[BOOKING];
	//清除原内容	再设置行数
	ui.bookerTable->clearContents();
	ui.bookerTable->setRowCount(sum);
	//billDB中查询类型
	Bill** bills = billDB.query(BOOKING);
	for (int i = 0; bills[i] != NULL && i < sum; i++) {
		//加一行到表格
		ui.bookerTable->setItem(i, 0, new QTableWidgetItem(QString::number(bills[i]->getID())));
		ui.bookerTable->setItem(i, 1, new QTableWidgetItem(bills[i]->clientA.getName()));
		ui.bookerTable->setItem(i, 3, new QTableWidgetItem(QString::number(bills[i]->getRoomID())));
		ui.bookerTable->setItem(i, 4, new QTableWidgetItem(RoomTypeToQString(bills[i]->room.getType())));
		//判断有没有ClientB
		if (bills[i]->isTwo())
			ui.bookerTable->setItem(i, 2, new QTableWidgetItem(bills[i]->clientB.getName()));
		else
			ui.bookerTable->setItem(i, 2, new QTableWidgetItem());
		//居中
		for (int j = 0; j < 5; j++)
			ui.bookerTable->item(i, j)->setTextAlignment(Qt::AlignCenter);
	}
}
