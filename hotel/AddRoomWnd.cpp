#include "AddRoomWnd.h"

AddRoomWnd::AddRoomWnd(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initial();

	//��Ӱ�ť
	QObject::connect(ui.addBtn, SIGNAL(clicked(bool)),		this, SLOT(addRoom()));
	QObject::connect(ui.IDEdit, SIGNAL(returnPressed()),	this, SLOT(addRoom()));
	//��ʱ��
	QObject::connect(timer,		SIGNAL(timeout()),			this, SLOT(hideNote()));
}


void AddRoomWnd::initial() {
	setFixedSize(400, 150);
	//��ʱ��	��noteLabel��
	timer = new QTimer(this);

	//������ʽ ��֤����ķ����Ϊ����
	QRegExp digitOnly("^[0-9]+$");
	QValidator *ValIDigitOnly = new QRegExpValidator(digitOnly, this);
	ui.IDEdit->setValidator(ValIDigitOnly);


	ui.noteLabel->setText(u8"���뷿�������·�.");
}

//��Ӱ�ť
void AddRoomWnd::addRoom() {
	long roomID = ui.IDEdit->text().toLong();
	int index = ui.typeBox->currentIndex();

	if (roomID == 0) {
		showNote(u8"��������Ч�ķ���ţ�", "red");
	}
	else {
		if (roomDB.query(roomID) != NULL) {
			showNote(QString::number(roomID) + u8"�Ѿ�����");
		}
		else {
			Room newRoom(roomID, RoomType(index));
			roomDB.insert(newRoom);
			sumRoom[index]++;			///̫����		

			QString noteType = RoomTypeToQString(RoomType(index));
			showNote(noteType + QString::number(roomID) + u8"��ӳɹ���");
		}
	}
	ui.IDEdit->selectAll();
}


//��ʾ��Ϣ
void AddRoomWnd::showNote(QString note, QString color, int time) {
	ui.noteLabel->setStyleSheet("color:" + color);
	ui.noteLabel->setText(note);
	timer->start(time);
}
void AddRoomWnd::hideNote() {
	ui.noteLabel->clear();
}

