#include "CheckInWnd.h"



CheckInWnd::CheckInWnd(QWidget* parent) 
	: QWidget(parent)
	, checkInForm(this)
	, roomInfoTable(this)
	, bookerInfoTable(this)
{
	//初始化	布局
	layout = new QVBoxLayout(this);
	layout->addWidget(&checkInForm);
	layout->addWidget(&roomInfoTable);
	layout->addWidget(&bookerInfoTable);
	this->setLayout(layout);
	//初始状态为登记,预订订单不显示
	bookerInfoTable.setVisible(false);
	//初始化	设置大小
	this->resize(700, 600);
	this->setMinimumSize(600, 400);
	this->setMaximumSize(800, 800);


	QObject::connect(checkInForm.ui.bookBtn,			SIGNAL(clicked(bool)),					this, SLOT(refreshTables()));
	QObject::connect(checkInForm.ui.checkInBtn,			SIGNAL(clicked(bool)),					this, SLOT(refreshTables()));
	QObject::connect(checkInForm.ui.checkBookBox,		SIGNAL(stateChanged(int)),				this, SLOT(onChangeModel(int)));
	QObject::connect(roomInfoTable.ui.roomInfoTable,	SIGNAL(cellDoubleClicked(int, int)),	this, SLOT(chooseRoom(int, int)));
	QObject::connect(bookerInfoTable.ui.bookerTable,	SIGNAL(cellDoubleClicked(int, int)),	this, SLOT(chooseBill(int, int)));
}

//切换模式	登记or预订
void CheckInWnd::onChangeModel(int state) {
	if (state == Qt::Checked) {
		//refreshTables();
		roomInfoTable.setVisible(false);
		bookerInfoTable.setVisible(true);
	}
	else if (state == Qt::Unchecked) {
		//refreshTables();
		bookerInfoTable.setVisible(false);
		roomInfoTable.setVisible(true);
	}
}

//更新两个表格
void CheckInWnd::refreshTables() {
	roomInfoTable.update(-1);
	bookerInfoTable.update();
}


//双击选择房间			//登记状态
void CheckInWnd::chooseRoom(int row, int col) {
	long roomID = roomInfoTable.ui.roomInfoTable->item(row, 0)->text().toLong();
	//用 Room 填充
	checkInForm.fillRoom(roomDB.query(roomID));
	checkInForm.showNote(u8"已更改房间信息！", "blue", 2000);
}
//双击选择预订订单		//已预订状态
void CheckInWnd::chooseBill(int row, int col) {
	long billID = bookerInfoTable.ui.bookerTable->item(row, 0)->text().toLong();
	//用 Bill 填充
	checkInForm.fillBill(billDB.query(billID));
	checkInForm.showNote(u8"已加载预订订单!", "blue", 2000);
}

