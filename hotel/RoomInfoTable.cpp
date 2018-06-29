#include "RoomInfoTable.h"




RoomInfoTable::RoomInfoTable(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initial();
	update(0);
	QObject::connect(ui.roomTypeBox, SIGNAL(currentIndexChanged(int)), this, SLOT(update(int)));
}


void RoomInfoTable::initial() {
	//��ʼ���������
	ui.roomInfoTable->setRowCount(roomDB.calSum());
	ui.roomInfoTable->setSelectionBehavior(QAbstractItemView::SelectRows);	//ѡ������
	ui.roomInfoTable->setEditTriggers(QAbstractItemView::NoEditTriggers);	//��ֹ�༭���
	ui.roomInfoTable->verticalHeader()->setVisible(false);
	ui.roomInfoTable->horizontalHeader()->setVisible(true);
	ui.roomInfoTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void RoomInfoTable::update(int index) {
	if (index == -1)	//���� ��ˢ��
		index = ui.roomTypeBox->currentIndex();
	// index == 0 ���� "��������"
	int sum = index ? sumRoom[index - 1] : roomDB.calSum();

	//���ԭ����	����������
	ui.roomInfoTable->clearContents();
	ui.roomInfoTable->setRowCount(sum);

	//roomDB�в�ѯ����
	Room** rooms = roomDB.query(RoomType(index - 1));
	for (int i = 0; rooms[i] != NULL && i < sum; i++) {
		//��һ�е����
		ui.roomInfoTable->setItem(i, 0, new QTableWidgetItem(QString::number(rooms[i]->getID())));
		ui.roomInfoTable->setItem(i, 1, new QTableWidgetItem(RoomTypeToQString(rooms[i]->getType())));
		ui.roomInfoTable->setItem(i, 2, new QTableWidgetItem(RoomStatusToQString(rooms[i]->getStatus())));
		//����
		for (int j = 0; j < 3; j++)
			ui.roomInfoTable->item(i, j)->setTextAlignment(Qt::AlignCenter);
	}
	//���ù����ö�
	ui.roomInfoTable->verticalScrollBar()->setValue(0);
	delete[] rooms;
}

