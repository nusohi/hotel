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
	//初始化表格设置
	ui.billTable->setRowCount(billDB.calSum());
	ui.billTable->setSelectionBehavior(QAbstractItemView::SelectRows);	//选择整行
	ui.billTable->setEditTriggers(QAbstractItemView::NoEditTriggers);	//禁止编辑表格
	ui.billTable->verticalHeader()->setVisible(false);
	ui.billTable->horizontalHeader()->setVisible(true);
	ui.billTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);	//自适应

	//根据内容调节列宽
	ui.billTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);	//单号
	ui.billTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);	//状态
///	ui.billTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);	//姓名
	ui.billTable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);	//身份证
	ui.billTable->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);	//房间类型
	ui.billTable->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);	//房间号
	ui.billTable->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);	//入住天数
///	ui.billTable->horizontalHeader()->setSectionResizeMode(7, QHeaderView::ResizeToContents);	//入住时间
///	ui.billTable->horizontalHeader()->setSectionResizeMode(8, QHeaderView::ResizeToContents);	//退房时间
}


void BillTable::update(int index) {
	// index == -1 仅用来刷新
	index = (index == -1) ? ui.typeBox->currentIndex() : index;
	// index == 0 则是 "所有类型"
	int sum = index ? sumBill[index - 1] : billDB.calSum();
	//清除原内容	//再设置行数
	ui.billTable->clearContents();
	ui.billTable->setRowCount(sum);
	// billDB中查询类型
	Bill** bills = billDB.query(BillStatus(index - 1));
	for (int i = 0; i < sum; i++) {
		//添加一行
		BillStatus billStatus = bills[i]->getStatus();
		ui.billTable->setItem(i, 0, new QTableWidgetItem(QString::number(bills[i]->getID())));
		ui.billTable->setItem(i, 1, new QTableWidgetItem(BillStatusToQString(bills[i]->getStatus())));
		ui.billTable->setItem(i, 2, new QTableWidgetItem(bills[i]->clientA.getName()));
		ui.billTable->setItem(i, 3, new QTableWidgetItem(bills[i]->clientA.getIDC()));
		ui.billTable->setItem(i, 4, new QTableWidgetItem(RoomTypeToQString(bills[i]->room.getType())));
		ui.billTable->setItem(i, 5, new QTableWidgetItem(QString::number(bills[i]->room.getID())));
		ui.billTable->setItem(i, 6, new QTableWidgetItem(QString::number(bills[i]->getStayDays())));
		if (int(billStatus) > 0) {	//CHECKIN 或 DONE
			ui.billTable->setItem(i, 7, new QTableWidgetItem(bills[i]->checkInTime.Day_Time()));
			if (int(billStatus) > 1) {	//DONE
				ui.billTable->setItem(i, 8, new QTableWidgetItem(bills[i]->checkOutTime.Day_Time()));
			}
		}
		ui.billTable->setItem(i, 9, new QTableWidgetItem(QString::number(bills[i]->calMoney())));
		//居中
		for (int j = 0; j < 7 + int(billStatus); j++)
			ui.billTable->item(i, j)->setTextAlignment(Qt::AlignCenter);
	}
	ui.billTable->verticalScrollBar()->setValue(0);	//到顶部
}

