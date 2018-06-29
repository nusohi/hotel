#include "CheckInWnd.h"



CheckInWnd::CheckInWnd(QWidget* parent) 
	: QWidget(parent)
	, checkInForm(this)
	, roomInfoTable(this)
	, bookerInfoTable(this)
{
	//��ʼ��	����
	layout = new QVBoxLayout(this);
	layout->addWidget(&checkInForm);
	layout->addWidget(&roomInfoTable);
	layout->addWidget(&bookerInfoTable);
	this->setLayout(layout);
	//��ʼ״̬Ϊ�Ǽ�,Ԥ����������ʾ
	bookerInfoTable.setVisible(false);
	//��ʼ��	���ô�С
	this->resize(700, 600);
	this->setMinimumSize(600, 400);
	this->setMaximumSize(800, 800);


	QObject::connect(checkInForm.ui.bookBtn,			SIGNAL(clicked(bool)),					this, SLOT(refreshTables()));
	QObject::connect(checkInForm.ui.checkInBtn,			SIGNAL(clicked(bool)),					this, SLOT(refreshTables()));
	QObject::connect(checkInForm.ui.checkBookBox,		SIGNAL(stateChanged(int)),				this, SLOT(onChangeModel(int)));
	QObject::connect(roomInfoTable.ui.roomInfoTable,	SIGNAL(cellDoubleClicked(int, int)),	this, SLOT(chooseRoom(int, int)));
	QObject::connect(bookerInfoTable.ui.bookerTable,	SIGNAL(cellDoubleClicked(int, int)),	this, SLOT(chooseBill(int, int)));
}

//�л�ģʽ	�Ǽ�orԤ��
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

//�����������
void CheckInWnd::refreshTables() {
	roomInfoTable.update(-1);
	bookerInfoTable.update();
}


//˫��ѡ�񷿼�			//�Ǽ�״̬
void CheckInWnd::chooseRoom(int row, int col) {
	long roomID = roomInfoTable.ui.roomInfoTable->item(row, 0)->text().toLong();
	//�� Room ���
	checkInForm.fillRoom(roomDB.query(roomID));
	checkInForm.showNote(u8"�Ѹ��ķ�����Ϣ��", "blue", 2000);
}
//˫��ѡ��Ԥ������		//��Ԥ��״̬
void CheckInWnd::chooseBill(int row, int col) {
	long billID = bookerInfoTable.ui.bookerTable->item(row, 0)->text().toLong();
	//�� Bill ���
	checkInForm.fillBill(billDB.query(billID));
	checkInForm.showNote(u8"�Ѽ���Ԥ������!", "blue", 2000);
}

