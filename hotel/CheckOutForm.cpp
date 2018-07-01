#include "CheckOutForm.h"




CheckOutForm::CheckOutForm(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initial();


	//�˷���ť
	QObject::connect(ui.checkOutBtn,	SIGNAL(clicked(bool)),		this, SLOT(checkOut()));
	QObject::connect(ui.roomIDEdit,		SIGNAL(returnPressed()),	this, SLOT(checkOut()));
	//-----��ʱ��--������ʾ
	QObject::connect(timer,				SIGNAL(timeout()),			this, SLOT(hideNote()));
}


void CheckOutForm::initial() {
	ui.checkInTimeEdit->setReadOnly(true);
	ui.moneyEdit->setReadOnly(true);
	timer = new QTimer(this);
}

//�˷�
void CheckOutForm::checkOut() {
	if (ui.roomIDEdit->text().isEmpty()) {
		showNote(u8"��������Ϣ��");
	}
	else {
		int	billID = ui.billIDLabel->text().toInt();
		Bill* bill = billDB.query(billID);
		if (bill == NULL) {
			showNote(u8"�˵��Ŵ���","red");
		}
		else {
			BillStatus billStatus = bill->getStatus();
			if (billStatus == DONE) {
				showNote(u8"������Ч���õ�����ɣ�");
			}
			else if (billStatus == BOOKING) {
				showNote(u8"������Ч������Ԥ��״̬��");
			}
			else if (billStatus == CHECKIN) {
				int roomID = ui.roomIDEdit->text().toLong();
				if (roomID != bill->getRoomID()) {
					showNote(u8"��������˵���Ӧ����������ѡ��", "red");
				}
				else {
					//��Ҫ��������
					bill->checkOut();
					roomDB.query(roomID)->setStatus(VACANT);
					sumBill[CHECKIN]--;
					sumBill[DONE]++;
					//��ձ༭��
					ui.roomIDEdit->clear();
					ui.checkInTimeEdit->clear();
					ui.moneyEdit->clear();
					ui.roomIDEdit->clear();

					showNote(u8"�˷��ɹ���");
				}
			}
		}
	}
}

//�� Bill ���
void CheckOutForm::fillBill(Bill* bill) {
	ui.roomIDEdit->setText(QString::number(bill->getRoomID()));
	ui.checkInTimeEdit->setText(bill->checkInTime.Day_Time());
	ui.billIDLabel->setText(QString::number(bill->getID()));
	ui.moneyEdit->setText(QString::number(bill->calMoney()));
}

//��ʾ��Ϣ
void CheckOutForm::showNote(QString note, QString color, int time) {
	ui.noteLabel->setStyleSheet("color:" + color);
	ui.noteLabel->setText(note);
	timer->start(time);
}
void CheckOutForm::hideNote() {
	ui.noteLabel->clear();
}

