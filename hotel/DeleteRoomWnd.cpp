#include "DeleteRoomWnd.h"

DeleteRoomWnd::DeleteRoomWnd(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initial();

	//ɾ����ť
	QObject::connect(ui.deleteBtn,	SIGNAL(clicked(bool)),		this, SLOT(deleteRoom()));
	QObject::connect(ui.IDEdit,		SIGNAL(returnPressed()),	this, SLOT(deleteRoom()));
	//��ʱ��
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(hideNote()));
}


void DeleteRoomWnd::initial() {
	setFixedSize(400, 150);
	//��ʱ��	��noteLabel��
	timer = new QTimer(this);
	//������ʽ ��֤����ķ����Ϊ����
	QRegExp digitOnly("^[0-9]+$");
	QValidator *ValIDigitOnly = new QRegExpValidator(digitOnly, this);
	ui.IDEdit->setValidator(ValIDigitOnly);

	ui.noteLabel->setText(u8"���뷿���ɾ������.");
}

//ɾ������
void DeleteRoomWnd::deleteRoom() {
	long roomID = ui.IDEdit->text().toLong();
	Room* room = roomDB.query(roomID);
	if (roomID == 0 || room == NULL) {
		showNote(u8"��ѡ����ȷ�ķ���ţ�", "red");
	}
	else {
		RoomStatus roomStatus = room->getStatus();
		if (roomStatus == OCCUPIED)
			showNote(u8"������ס��", "red");
		else if (roomStatus == BOOKED)
			showNote(u8"����Ԥ������", "red");
		else {
			//��Ҫ����
			sumRoom[int(room->getType())]--;	//Ҫ��ǰ�棬roomDBɾ��room��roomָ��δ֪
			roomDB.Delete(roomID);
			showNote(u8"�ɹ�ɾ����", "blue");
		}
		ui.IDEdit->selectAll();
	}
}

//�� Room ���
void DeleteRoomWnd::fillRoom(RoomBase* room) {
	ui.IDEdit->setText(QString::number(room->getID()));
}




//��ʾ��Ϣ
void DeleteRoomWnd::showNote(QString note, QString color, int time) {
	ui.noteLabel->setStyleSheet("color:" + color);
	ui.noteLabel->setText(note);
	timer->start(time);
}
void DeleteRoomWnd::hideNote() {
	ui.noteLabel->clear();
}

