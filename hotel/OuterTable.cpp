#include "OuterTable.h"



OuterTable::OuterTable(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initial();
	update();
}



void OuterTable::initial() {
	//��ʼ���������
	ui.table->setSelectionBehavior(QAbstractItemView::SelectRows);	//ѡ������
	ui.table->setEditTriggers(QAbstractItemView::NoEditTriggers);	//��ֹ�༭���
	ui.table->verticalHeader()->setVisible(false);
	ui.table->horizontalHeader()->setVisible(true);
	ui.table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void OuterTable::update() {
	int sum = sumBill[CHECKIN];
	//���ԭ����	//����������
	ui.table->clearContents();
	ui.table->setRowCount(sum);
	// billDB�в�ѯ
	Bill** bills = billDB.query(CHECKIN);
	for (int i = 0; i < sum; i++) {
		//���һ��
		ui.table->setItem(i, 0, new QTableWidgetItem(QString::number(bills[i]->getID())));
		ui.table->setItem(i, 1, new QTableWidgetItem(BillStatusToQString(bills[i]->getStatus())));
		ui.table->setItem(i, 2, new QTableWidgetItem(bills[i]->clientA.getName()));
		ui.table->setItem(i, 3, new QTableWidgetItem(QString::number(bills[i]->getRoomID())));
		ui.table->setItem(i, 4, new QTableWidgetItem(RoomTypeToQString(bills[i]->room.getType())));
		ui.table->setItem(i, 5, new QTableWidgetItem(bills[i]->checkInTime.Day_Time()));
		//����
		for (int j = 0; j < 6; j++)
			ui.table->item(i, j)->setTextAlignment(Qt::AlignCenter);
	}
	ui.table->verticalScrollBar()->setValue(0);	//������
}