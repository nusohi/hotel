#include "BossWnd.h"

BossWnd::BossWnd(QWidget* parent)
	: logInForm(this)
	, bossCtrl(this)
	, billTable(this)
	, roomInfoTable(this)
	, addRoomWnd(this)
	, deleteRoomWnd(this)
{
	initial();



	//��¼
	QObject::connect(&logInForm,				SIGNAL(passChanged(bool)), this, SLOT(signIn()));
	QObject::connect(logInForm.ui.signOutBtn, SIGNAL(clicked(bool)), this, SLOT(signOut()));
	//�л�ģʽ
	QObject::connect(bossCtrl.ui.showRoomBtn,	SIGNAL(clicked(bool)), this, SLOT(roomModelOn()));
	QObject::connect(bossCtrl.ui.closeRoomBtn,	SIGNAL(clicked(bool)), this, SLOT(roomModelOff()));
	QObject::connect(bossCtrl.ui.showBillBtn,	SIGNAL(clicked(bool)), this, SLOT(billModelOn()));
	QObject::connect(bossCtrl.ui.closeBillBtn,	SIGNAL(clicked(bool)), this, SLOT(billModelOff()));
	//˫�� ���
	QObject::connect(roomInfoTable.ui.roomInfoTable,	SIGNAL(cellDoubleClicked(int, int)), this, SLOT(chooseRoom(int, int)));
	//��ӻ�ɾ�����䰴ť���º�ˢ�·�����
	QObject::connect(addRoomWnd.ui.addBtn,				SIGNAL(clicked(bool)),		&roomInfoTable, SLOT(refresh()));
	QObject::connect(addRoomWnd.ui.IDEdit,				SIGNAL(returnPressed()),	&roomInfoTable, SLOT(refresh()));
	QObject::connect(deleteRoomWnd.ui.deleteBtn,		SIGNAL(clicked(bool)),		&roomInfoTable, SLOT(refresh()));
	QObject::connect(deleteRoomWnd.ui.IDEdit,			SIGNAL(returnPressed()),	&roomInfoTable, SLOT(refresh()));
}


void BossWnd::initial() {
	this->resize(1030, 750);
	//����
	layout = new QVBoxLayout(this);
	roomLayout = new QVBoxLayout(this);
	headLayout = new QHBoxLayout(this);
	footLayout = new QHBoxLayout(this);
	headSpacerL = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
	headSpacerR = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

	headLayout->addSpacerItem(headSpacerL);
	headLayout->addWidget(&logInForm);
	headLayout->addWidget(&bossCtrl);
	headLayout->addSpacerItem(headSpacerR);

	roomLayout->addWidget(&addRoomWnd);
	roomLayout->addWidget(&deleteRoomWnd);
	footLayout->addWidget(&roomInfoTable);
	footLayout->addLayout(roomLayout);

	layout->addLayout(headLayout);
	layout->addWidget(&billTable);
	layout->addLayout(footLayout);

	//����
	hideBillTable();
	hideRoomCtrl();
	//����bossCtrl
	bossCtrl.disable();
}

void BossWnd::signIn() {
	bossCtrl.enable();
}
void BossWnd::signOut() {
	bossCtrl.disable();
	hideBillTable();
	hideRoomCtrl();
}



void BossWnd::chooseRoom(int row, int col) {
	int roomID = roomInfoTable.ui.roomInfoTable->item(row, 0)->text().toInt();
	Room* room = roomDB.query(roomID);
	//���
	deleteRoomWnd.fillRoom(room);
}


//�л�ģʽ
void BossWnd::billModelOn() {
	showBillTable();
	hideRoomCtrl();
}
void BossWnd::billModelOff() {
	hideBillTable();
}
void BossWnd::roomModelOn() {
	showRoomCtrl();
	hideBillTable();
}
void BossWnd::roomModelOff() {
	hideRoomCtrl();
}



//��ʾ������
void BossWnd::showBillTable() {
	billTable.setVisible(true);
}
void BossWnd::hideBillTable() {
	billTable.setVisible(false);
}
void BossWnd::showRoomCtrl() {
	roomInfoTable.setVisible(true);
	addRoomWnd.setVisible(true);
	deleteRoomWnd.setVisible(true);
}
void BossWnd::hideRoomCtrl() {
	roomInfoTable.setVisible(false);
	addRoomWnd.setVisible(false);
	deleteRoomWnd.setVisible(false);
}

//ˢ�±��
void BossWnd::refresh() {
	billTable.update(-1);
	roomInfoTable.update(-1);
}

