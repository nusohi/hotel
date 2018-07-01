#include "AddRoomWnd.h"

AddRoomWnd::AddRoomWnd(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initial();

	//添加按钮
	QObject::connect(ui.addBtn, SIGNAL(clicked(bool)),		this, SLOT(addRoom()));
	QObject::connect(ui.IDEdit, SIGNAL(returnPressed()),	this, SLOT(addRoom()));
	//计时器
	QObject::connect(timer,		SIGNAL(timeout()),			this, SLOT(hideNote()));
}


void AddRoomWnd::initial() {
	setFixedSize(400, 150);
	//计时器	供noteLabel用
	timer = new QTimer(this);

	//正则表达式 验证输入的房间号为数字
	QRegExp digitOnly("^[0-9]+$");
	QValidator *ValIDigitOnly = new QRegExpValidator(digitOnly, this);
	ui.IDEdit->setValidator(ValIDigitOnly);


	ui.noteLabel->setText(u8"输入房间号添加新房.");
}

//添加按钮
void AddRoomWnd::addRoom() {
	long roomID = ui.IDEdit->text().toLong();
	int index = ui.typeBox->currentIndex();

	if (roomID == 0) {
		showNote(u8"请输入有效的房间号！", "red");
	}
	else {
		if (roomDB.query(roomID) != NULL) {
			showNote(QString::number(roomID) + u8"已经存在");
		}
		else {
			Room newRoom(roomID, RoomType(index));
			roomDB.insert(newRoom);
			sumRoom[index]++;			///太难用		

			QString noteType = RoomTypeToQString(RoomType(index));
			showNote(noteType + QString::number(roomID) + u8"添加成功！");
		}
	}
	ui.IDEdit->selectAll();
}


//提示信息
void AddRoomWnd::showNote(QString note, QString color, int time) {
	ui.noteLabel->setStyleSheet("color:" + color);
	ui.noteLabel->setText(note);
	timer->start(time);
}
void AddRoomWnd::hideNote() {
	ui.noteLabel->clear();
}

