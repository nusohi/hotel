#include "CheckOutWnd.h"



CheckOutWnd::CheckOutWnd(QWidget* parent) 
	: QWidget(parent)
	, checkOutForm(this)
	, outerTable(this)
{
	//��ʼ��	����
	layout = new QVBoxLayout(this);
	layout->addWidget(&checkOutForm);
	layout->addWidget(&outerTable);
	this->setLayout(layout);


	//�˷���ˢ�±��
	QObject::connect(checkOutForm.ui.checkOutBtn,	SIGNAL(clicked(bool)),					&outerTable,	SLOT(update()));
	//˫��������Form
	QObject::connect(outerTable.ui.table,			SIGNAL(cellDoubleClicked(int, int)),	this,			SLOT(chooseBill(int, int)));
}


void CheckOutWnd::chooseBill(int row, int col) {
	long billID = outerTable.ui.table->item(row, 0)->text().toLong();
	//�� Bill ���
	checkOutForm.fillBill(billDB.query(billID));
	checkOutForm.showNote(u8"�Ѽ���Ԥ������!", "blue", 2000);
}


void CheckOutWnd::refresh() {
	outerTable.update();
}

