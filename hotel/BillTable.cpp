#include "BillTable.h"



BillTable::BillTable(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initial();
	update(0);

	QObject::connect(ui.typeBox, SIGNAL(currentIndexChanged(int)), this, SLOT(update(int)));
}


void BillTable::initial() {
	this->setMinimumWidth(1000);
	//��ʼ���������
	ui.billTable->setRowCount(billDB.calSum());
	ui.billTable->setSelectionBehavior(QAbstractItemView::SelectRows);	//ѡ������
	ui.billTable->setEditTriggers(QAbstractItemView::NoEditTriggers);	//��ֹ�༭���
	ui.billTable->verticalHeader()->setVisible(false);
	ui.billTable->horizontalHeader()->setVisible(true);
	ui.billTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);	//����Ӧ

	//�������ݵ����п�
	ui.billTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);	//����
	ui.billTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);	//״̬
///	ui.billTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);	//����
	ui.billTable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);	//���֤
	ui.billTable->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);	//��������
	ui.billTable->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);	//�����
	ui.billTable->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);	//��ס����
///	ui.billTable->horizontalHeader()->setSectionResizeMode(7, QHeaderView::ResizeToContents);	//��סʱ��
///	ui.billTable->horizontalHeader()->setSectionResizeMode(8, QHeaderView::ResizeToContents);	//�˷�ʱ��
}


void BillTable::update(int index) {
	// index == -1 ������ˢ��
	index = (index == -1) ? ui.typeBox->currentIndex() : index;
	// index == 0 ���� "��������"
	int sum = index ? sumBill[index - 1] : billDB.calSum();
	//���ԭ����	//����������
	ui.billTable->clearContents();
	ui.billTable->setRowCount(sum);
	// billDB�в�ѯ����
	Bill** bills = billDB.query(BillStatus(index - 1));
	for (int i = 0; i < sum; i++) {
		//���һ��
		BillStatus billStatus = bills[i]->getStatus();
		ui.billTable->setItem(i, 0, new QTableWidgetItem(QString::number(bills[i]->getID())));
		ui.billTable->setItem(i, 1, new QTableWidgetItem(BillStatusToQString(bills[i]->getStatus())));
		ui.billTable->setItem(i, 2, new QTableWidgetItem(bills[i]->clientA.getName()));
		ui.billTable->setItem(i, 3, new QTableWidgetItem(bills[i]->clientA.getIDC()));
		ui.billTable->setItem(i, 4, new QTableWidgetItem(RoomTypeToQString(bills[i]->room.getType())));
		ui.billTable->setItem(i, 5, new QTableWidgetItem(QString::number(bills[i]->room.getID())));
		ui.billTable->setItem(i, 6, new QTableWidgetItem(QString::number(bills[i]->getStayDays())));
		if (int(billStatus) > 0) {	//CHECKIN �� DONE
			ui.billTable->setItem(i, 7, new QTableWidgetItem(bills[i]->checkInTime.Day_Time()));
			if (int(billStatus) > 1) {	//DONE
				ui.billTable->setItem(i, 8, new QTableWidgetItem(bills[i]->checkOutTime.Day_Time()));
			}
		}
		ui.billTable->setItem(i, 9, new QTableWidgetItem(QString::number(bills[i]->calMoney())));
		//����
		for (int j = 0; j < 7 + int(billStatus); j++)
			ui.billTable->item(i, j)->setTextAlignment(Qt::AlignCenter);
	}
	ui.billTable->verticalScrollBar()->setValue(0);	//������
}

