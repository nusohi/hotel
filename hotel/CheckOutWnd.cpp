#include "CheckOutWnd.h"



CheckOutWnd::CheckOutWnd(QWidget* parent) 
	: QWidget(parent)
	, checkOutForm(this)
	, outerTable(this)
{
	//初始化	布局
	layout = new QVBoxLayout(this);
	layout->addWidget(&checkOutForm);
	layout->addWidget(&outerTable);
	this->setLayout(layout);


	//退房后刷新表格
	QObject::connect(checkOutForm.ui.checkOutBtn,	SIGNAL(clicked(bool)),					&outerTable,	SLOT(update()));
	//双击表格填充Form
	QObject::connect(outerTable.ui.table,			SIGNAL(cellDoubleClicked(int, int)),	this,			SLOT(chooseBill(int, int)));
}


void CheckOutWnd::chooseBill(int row, int col) {
	long billID = outerTable.ui.table->item(row, 0)->text().toLong();
	//用 Bill 填充
	checkOutForm.fillBill(billDB.query(billID));
	checkOutForm.showNote(u8"已加载预订订单!", "blue", 2000);
}


void CheckOutWnd::refresh() {
	outerTable.update();
}

