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
	//初始化表格设置
	ui.roomInfoTable->setRowCount(roomDB.calSum());
	ui.roomInfoTable->setSelectionBehavior(QAbstractItemView::SelectRows);	//选择整行
	ui.roomInfoTable->setEditTriggers(QAbstractItemView::NoEditTriggers);	//禁止编辑表格
	ui.roomInfoTable->verticalHeader()->setVisible(false);
	ui.roomInfoTable->horizontalHeader()->setVisible(true);
	ui.roomInfoTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void RoomInfoTable::update(int index) {
	if (index == -1)	//用来 仅刷新
		index = ui.roomTypeBox->currentIndex();
	// index == 0 则是 "所有类型"
	int sum = index ? sumRoom[index - 1] : roomDB.calSum();

	//清除原内容	再设置行数
	ui.roomInfoTable->clearContents();
	ui.roomInfoTable->setRowCount(sum);

	//roomDB中查询类型
	Room** rooms = roomDB.query(RoomType(index - 1));
	for (int i = 0; rooms[i] != NULL && i < sum; i++) {
		//加一行到表格
		ui.roomInfoTable->setItem(i, 0, new QTableWidgetItem(QString::number(rooms[i]->getID())));
		ui.roomInfoTable->setItem(i, 1, new QTableWidgetItem(RoomTypeToQString(rooms[i]->getType())));
		ui.roomInfoTable->setItem(i, 2, new QTableWidgetItem(RoomStatusToQString(rooms[i]->getStatus())));
		//居中
		for (int j = 0; j < 3; j++)
			ui.roomInfoTable->item(i, j)->setTextAlignment(Qt::AlignCenter);
	}
	//设置滚轮置顶
	ui.roomInfoTable->verticalScrollBar()->setValue(0);
	delete[] rooms;
}

