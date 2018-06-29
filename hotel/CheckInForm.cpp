#include "CheckInForm.h"
#include <qtimer.h>

extern DataBase<Bill> billDB;
extern DataBase<Room> roomDB;
extern int sumRoom[];



CheckInForm::CheckInForm(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//��ʼ��
	initial();
	//���ط����
	updateRoomIDBox(0);

	//---------------------Ԥ��
	QObject::connect(ui.bookBtn,			SIGNAL(clicked(bool)),	this, SLOT(book()));
	//---------------------�Ǽ���ס
	QObject::connect(ui.checkInBtn,			SIGNAL(clicked(bool)),	this, SLOT(checkIn()));
	//-----'��','˫'��ť--�������ı���
	QObject::connect(ui.doubleClientBtn,	SIGNAL(toggled(bool)),	this, SLOT(ouDoubleClientBtn()));		//false ?
	QObject::connect(ui.singleClientBtn,	SIGNAL(toggled(bool)),	this, SLOT(onSingleClientBtn()));
	//-----'��Ԥ��'��ť
	QObject::connect(ui.checkBookBox,		SIGNAL(stateChanged(int)),			this,	SLOT(onCheckBookBox(int)));
	//-----��������BOX--���·����BOX
	QObject::connect(ui.roomTypeBox,		SIGNAL(currentIndexChanged(int)),	this,	SLOT(updateRoomIDBox(int)));
	//-----��ʱ��--������ʾ
	QObject::connect(timer,					SIGNAL(timeout()),					this,	SLOT(hideNote()));
}



//��ʼ��
void CheckInForm::initial() {

	//������	��	SpinBox��ס���� >= 1
	QRegExp digitIDC("(\\d{15}|\\d{17}(\\d|[xX]))");
	QValidator *ValIDigit = new QRegExpValidator(digitIDC, this);
	ui.IDA->setValidator(ValIDigit);
	ui.IDB->setValidator(ValIDigit);
	ui.stayDaysBox->setMinimum(1);

	//��ʱ��	��noteLabel��
	timer = new QTimer(this);
}

//Ԥ��
void CheckInForm::book() {
	if (!checkInputStatus()) {
		showNote(u8"��������ȷ��ֵ��", "red", 2000);
	}
	else {
		QString name[2], ID[2];
		//room info
		int roomID = ui.roomIDBox->currentText().toInt();
		if (roomDB.query(roomID)->getStatus() != VACANT) {
			showNote(u8"���ǿշ�����", "red");
		}
		else {
			RoomType roomType = RoomType(ui.roomTypeBox->currentText().toInt());
			RoomBase room(roomID, roomType);
			roomDB.query(roomID)->setStatus(BOOKED);		//����Ҫ
			int stayDays = ui.stayDaysBox->value();
			//Client A
			ID[0] = ui.IDA->text();							
			name[0] = ui.nameA->text();
			Client clientA(ID[0].toStdString().c_str(), name[0].toStdString().c_str());
			if (ui.doubleClientBtn->isChecked()) {
				//Client B
				name[1] = ui.nameB->text();
				ID[1] = ui.IDB->text();
				Client clientB(ID[1].toStdString().c_str(), name[1].toStdString().c_str());

				Bill bill(&room, clientA, clientB, stayDays, false);
				billDB.insert(bill);
			}
			else {
				Bill bill(&room, clientA, stayDays, false);
				billDB.insert(bill);
			}
			billDB.saveMap();
			clearForm();
			showNote(u8"Ԥ���ɹ���");
		}
	}
}

//�Ǽ���ס
void CheckInForm::checkIn() {
	if (!checkInputStatus()) {
		showNote(u8"��������ȷ��ֵ��", "red", 2000);
	}
	else {
		int roomID = ui.roomIDBox->currentText().toInt();
		if (roomDB.query(roomID)->getStatus() != VACANT) {
			showNote(u8"���ǿշ�����");
		}
		else {
			QString name[2], ID[2];
			RoomType roomType = RoomType(ui.roomTypeBox->currentText().toInt());
			RoomBase room(roomID, roomType);
			roomDB.query(roomID)->setStatus(OCCUPIED);		//����Ҫ
			int stayDays = ui.stayDaysBox->value();
			//Client A
			ID[0] = ui.IDA->text();
			name[0] = ui.nameA->text();
			Client clientA(ID[0].toStdString().c_str(), name[0].toStdString().c_str());
			if (ui.doubleClientBtn->isChecked()) {
				//Client B
				name[1] = ui.nameB->text();
				ID[1] = ui.IDB->text();
				Client clientB(ID[1].toStdString().c_str(), name[1].toStdString().c_str());

				Bill bill(&room, clientA, clientB, stayDays, true);
				billDB.insert(bill);
			}
			else {
				Bill bill(&room, clientA, stayDays, true);
				billDB.insert(bill);
			}
			billDB.saveMap();
			clearForm();
			showNote(u8"�Ǽǳɹ���");
		}
	}
}


//���·���� ����������
void CheckInForm::updateRoomIDBox(int index) {
							//�˵��õ�indexΪ A0 B1 C2
	//�����
	ui.roomIDBox->clear();
	//���ѯ
	long * roomID = roomDB.queryID(RoomType(index));
	//�����
	for (int i = 0; i < sumRoom[index]; i++)
		ui.roomIDBox->insertItem(i, QString::number(roomID[i]));
	//����������ʾ
	ui.leftRoomLabel->setText(QString::number(sumRoom[index]));
	delete roomID;
}

//������
bool CheckInForm::checkInputStatus() {
	//��֤����֤����		///�ڶ���ֻ����֤18λ	///���޸�
							///QRegExp RegExpIDC("^[1-9]\\d{5}(18|19|([23]\\d))\\d{2}((0[1-9])|(10|11|12))(([0-2][1-9])|10|20|30|31)\\d{3}[0-9Xx]$)|(^[1-9]\\d{5}\\d{2}((0[1-9])|(10|11|12))(([0-2][1-9])|10|20|30|31)\\d{2}$");
	QRegExp RegExpIDC("^\\d{6}(18\\d{2}|19\\d{2}|20[01]\\d)(0[1-9]|1[012])(0[1-9]|[12]\\d|3[01])\\d{3}(\\d|[xX])$");
	//˫ Client B
	if (ui.doubleClientBtn->isChecked()) {
		if (ui.nameB->text().isEmpty()
			|| ui.IDB->text().isEmpty()
			|| !RegExpIDC.exactMatch(ui.IDB->text())) {
			return false;
		}
	}
	// Client A
	if (ui.nameA->text().isEmpty()
		|| ui.IDA->text().isEmpty()
		|| !RegExpIDC.exactMatch(ui.IDA->text())) {
		return false;
	}
	//
	int test = ui.roomIDBox->currentIndex();
	if (sumRoom[ui.roomTypeBox->currentIndex()]==0)
		return false;
	return true;
}

//��Ԥ����ť checkBox
void CheckInForm::onCheckBookBox(int state) {
	if (state == Qt::Unchecked) {
		//��˫��ť
		ui.singleClientBtn->setEnabled(true);
		ui.doubleClientBtn->setEnabled(true);
		//BOX
		ui.roomTypeBox->setEnabled(true);
		ui.roomIDBox->setEnabled(true);
		ui.stayDaysBox->setEnabled(true);
		//�ı��༭��
		ui.IDA->setEnabled(true);
		if (ui.doubleClientBtn->isChecked()) {
			ui.nameB->setEnabled(true);
			ui.IDB->setEnabled(true);
		}
		else {
			ui.nameB->setEnabled(false);
			ui.IDB->setEnabled(false);
		}
	}
	else if (state == Qt::Checked) {
		//��˫��ť
		ui.singleClientBtn->setEnabled(false);
		ui.doubleClientBtn->setEnabled(false);
		//BOX
		ui.roomTypeBox->setEnabled(false);
		ui.roomIDBox->setEnabled(false);
		ui.stayDaysBox->setEnabled(false);
		//�ı��༭��
		ui.IDA->setEnabled(false);
		if (ui.doubleClientBtn->isChecked()) {
			ui.nameB->setEnabled(false);
			ui.IDB->setEnabled(false);
		}
	}
}
//�� ˫
void CheckInForm::onSingleClientBtn() {
	if (ui.singleClientBtn->isChecked()) {
		ui.nameB->setDisabled(true);
		ui.IDB->setDisabled(true);
	}
	else {
		ui.nameB->setEnabled(true);
		ui.IDB->setEnabled(true);
	}
}
void CheckInForm::onDoubleClientBtn() {
	if (ui.doubleClientBtn->isChecked()) {
		ui.nameB->setEnabled(true);
		ui.IDB->setEnabled(true);
	}
	else {
		ui.nameB->setDisabled(true);
		ui.IDB->setDisabled(true);
	}
}


//��� Form
void CheckInForm::clearForm() {
	ui.nameA->clear();
	ui.nameB->clear();
	ui.IDA->clear();
	ui.IDB->clear();
}
//��ʾ��Ϣ
void CheckInForm::showNote(QString note, QString color, int time) {
	ui.noteLabel->setStyleSheet("color:" + color);
	ui.noteLabel->setText(note);
	timer->start(time);
}
void CheckInForm::hideNote() {
	ui.noteLabel->clear();
}
