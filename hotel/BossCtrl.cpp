#include "BossCtrl.h"



BossCtrl::BossCtrl(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initial();

	QObject::connect(ui.showBillBtn,	SIGNAL(clicked(bool)), this, SLOT(billOnModel()));
	QObject::connect(ui.closeBillBtn,	SIGNAL(clicked(bool)), this, SLOT(billOffModel()));
	QObject::connect(ui.showRoomBtn,	SIGNAL(clicked(bool)), this, SLOT(roomOnModel()));
	QObject::connect(ui.closeRoomBtn,	SIGNAL(clicked(bool)), this, SLOT(roomOffModel()));
}

void BossCtrl::initial() {
	ui.closeBillBtn->setVisible(false);
	ui.closeRoomBtn->setVisible(false);

	this->setFixedSize(280, 220);
///	disable();
}


//禁用与解禁
void BossCtrl::enable() {
	ui.showRoomBtn->setEnabled(true);
	ui.closeRoomBtn->setEnabled(true);
	ui.showBillBtn->setEnabled(true);
	ui.closeBillBtn->setEnabled(true);
	ui.outputBillBtn->setEnabled(true);
}
void BossCtrl::disable() {
	ui.showRoomBtn->setEnabled(false);
	ui.closeRoomBtn->setEnabled(false);
	ui.showBillBtn->setEnabled(false);
	ui.closeBillBtn->setEnabled(false);
	ui.outputBillBtn->setEnabled(false);
}

//切换模式
void BossCtrl::billOnModel() {
	ui.closeBillBtn->setVisible(true);
	ui.showBillBtn->setVisible(false);
	roomOffModel();
}
void BossCtrl::billOffModel() {
	ui.showBillBtn->setVisible(true);
	ui.closeBillBtn->setVisible(false);
}

void BossCtrl::roomOnModel() {
	ui.closeRoomBtn->setVisible(true);
	ui.showRoomBtn->setVisible(false);
	billOffModel();
}
void BossCtrl::roomOffModel() {
	ui.showRoomBtn->setVisible(true);
	ui.closeRoomBtn->setVisible(false);
}