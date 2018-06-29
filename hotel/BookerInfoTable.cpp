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
	//��ʼ���������
	ui.bookerTable->setRowCount(sumBill[BOOKING]);
	ui.bookerTable->setSelectionBehavior(QAbstractItemView::SelectRows);	//ѡ������
	ui.bookerTable->setEditTriggers(QAbstractItemView::NoEditTriggers);		//��ֹ�༭���
	ui.bookerTable->verticalHeader()->setVisible(false);
	ui.bookerTable->horizontalHeader()->setVisible(true);
	ui.bookerTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void BookerInfoTable::update() {
	int sum = sumBill[BOOKING];
	//���ԭ����	����������
	ui.bookerTable->clearContents();
	ui.bookerTable->setRowCount(sum);
	//billDB�в�ѯ����
	Bill** bills = billDB.query(BOOKING);
	for (int i = 0; bills[i] != NULL && i < sum; i++) {
		//��һ�е����
		ui.bookerTable->setItem(i, 0, new QTableWidgetItem(QString::number(bills[i]->getID())));
		ui.bookerTable->setItem(i, 1, new QTableWidgetItem(bills[i]->clientA.getName()));
		ui.bookerTable->setItem(i, 3, new QTableWidgetItem(QString::number(bills[i]->getRoomID())));
		ui.bookerTable->setItem(i, 4, new QTableWidgetItem(RoomTypeToQString(bills[i]->room.getType())));
		//�ж���û��ClientB
		if (bills[i]->isTwo())
			ui.bookerTable->setItem(i, 2, new QTableWidgetItem(bills[i]->clientB.getName()));
		else
			ui.bookerTable->setItem(i, 2, new QTableWidgetItem());
		//����
		for (int j = 0; j < 5; j++)
			ui.bookerTable->item(i, j)->setTextAlignment(Qt::AlignCenter);
	}
}
