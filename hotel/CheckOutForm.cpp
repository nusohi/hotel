#include "CheckOutForm.h"




CheckOutForm::CheckOutForm(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initial();


	//退房按钮
	QObject::connect(ui.checkOutBtn,	SIGNAL(clicked(bool)),		this, SLOT(checkOut()));
	QObject::connect(ui.roomIDEdit,		SIGNAL(returnPressed()),	this, SLOT(checkOut()));
	//-----计时器--隐藏提示
	QObject::connect(timer,				SIGNAL(timeout()),			this, SLOT(hideNote()));
}


void CheckOutForm::initial() {
	ui.checkInTimeEdit->setReadOnly(true);
	ui.moneyEdit->setReadOnly(true);
	timer = new QTimer(this);
}

//退房
void CheckOutForm::checkOut() {
	if (ui.roomIDEdit->text().isEmpty()) {
		showNote(u8"请输入信息！");
	}
	else {
		int	billID = ui.billIDLabel->text().toInt();
		Bill* bill = billDB.query(billID);
		if (bill == NULL) {
			showNote(u8"账单号错误！","red");
		}
		else {
			BillStatus billStatus = bill->getStatus();
			if (billStatus == DONE) {
				showNote(u8"操作无效，该单已完成！");
			}
			else if (billStatus == BOOKING) {
				showNote(u8"操作无效，处于预订状态！");
			}
			else if (billStatus == CHECKIN) {
				int roomID = ui.roomIDEdit->text().toLong();
				if (roomID != bill->getRoomID()) {
					showNote(u8"房间号与账单对应错误！请重新选择！", "red");
				}
				else {
					//主要操作！！
					bill->checkOut();
					roomDB.query(roomID)->setStatus(VACANT);
					sumBill[CHECKIN]--;
					sumBill[DONE]++;
					//清空编辑框
					ui.roomIDEdit->clear();
					ui.checkInTimeEdit->clear();
					ui.moneyEdit->clear();
					ui.roomIDEdit->clear();

					showNote(u8"退房成功！");
				}
			}
		}
	}
}

//从 Bill 填充
void CheckOutForm::fillBill(Bill* bill) {
	ui.roomIDEdit->setText(QString::number(bill->getRoomID()));
	ui.checkInTimeEdit->setText(bill->checkInTime.Day_Time());
	ui.billIDLabel->setText(QString::number(bill->getID()));
	ui.moneyEdit->setText(QString::number(bill->calMoney()));
}

//提示信息
void CheckOutForm::showNote(QString note, QString color, int time) {
	ui.noteLabel->setStyleSheet("color:" + color);
	ui.noteLabel->setText(note);
	timer->start(time);
}
void CheckOutForm::hideNote() {
	ui.noteLabel->clear();
}

