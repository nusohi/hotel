#include "BossCtrl.h"



BossCtrl::BossCtrl(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initial();

	bool bsdf=QObject::connect(ui.showBillBtn,	SIGNAL(clicked(bool)), this, SLOT(billOffModel()));
	bool adsa=QObject::connect(ui.closeBillBtn,	SIGNAL(clicked(bool)), this, SLOT(billOnModel()));
}

void BossCtrl::initial() {
	ui.closeBillBtn->setVisible(false);
///	disable();
}


//禁用与解禁
void BossCtrl::enable() {
	ui.addRoomBtn->setEnabled(true);
	ui.closeBillBtn->setEnabled(true);
	ui.deleteRoomBtn->setEnabled(true);
	ui.outputBillBtn->setEnabled(true);
	ui.showBillBtn->setEnabled(true);
}
void BossCtrl::disable() {
	ui.addRoomBtn->setEnabled(false);
	ui.closeBillBtn->setEnabled(false);
	ui.deleteRoomBtn->setEnabled(false);
	ui.outputBillBtn->setEnabled(false);
	ui.showBillBtn->setEnabled(false);
}

//切换模式
void BossCtrl::billOnModel() {
	ui.showBillBtn->setVisible(true);
	ui.closeBillBtn->setVisible(false);
}
void BossCtrl::billOffModel() {
	ui.closeBillBtn->setVisible(true);
	ui.showBillBtn->setVisible(false);
}