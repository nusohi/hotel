#include "DeleteRoomWnd.h"

DeleteRoomWnd::DeleteRoomWnd(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initial();

	//删除按钮
	QObject::connect(ui.deleteBtn,	SIGNAL(clicked(bool)),		this, SLOT(deleteRoom()));
	QObject::connect(ui.IDEdit,		SIGNAL(returnPressed()),	this, SLOT(deleteRoom()));
	//计时器
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(hideNote()));
}


void DeleteRoomWnd::initial() {
	setFixedSize(400, 150);
	//计时器	供noteLabel用
	timer = new QTimer(this);
	//正则表达式 验证输入的房间号为数字
	QRegExp digitOnly("^[0-9]+$");
	QValidator *ValIDigitOnly = new QRegExpValidator(digitOnly, this);
	ui.IDEdit->setValidator(ValIDigitOnly);

	ui.noteLabel->setText(u8"输入房间号删除房间.");
}

//删除房间
void DeleteRoomWnd::deleteRoom() {
	long roomID = ui.IDEdit->text().toLong();
	Room* room = roomDB.query(roomID);
	if (roomID == 0 || room == NULL) {
		showNote(u8"请选择正确的房间号！", "red");
	}
	else {
		RoomStatus roomStatus = room->getStatus();
		if (roomStatus == OCCUPIED)
			showNote(u8"还有人住！", "red");
		else if (roomStatus == BOOKED)
			showNote(u8"被人预订啦！", "red");
		else {
			//主要操作
			sumRoom[int(room->getType())]--;	//要在前面，roomDB删除room后room指向未知
			roomDB.Delete(roomID);
			showNote(u8"成功删除！", "blue");
		}
		ui.IDEdit->selectAll();
	}
}

//从 Room 填充
void DeleteRoomWnd::fillRoom(RoomBase* room) {
	ui.IDEdit->setText(QString::number(room->getID()));
}




//提示信息
void DeleteRoomWnd::showNote(QString note, QString color, int time) {
	ui.noteLabel->setStyleSheet("color:" + color);
	ui.noteLabel->setText(note);
	timer->start(time);
}
void DeleteRoomWnd::hideNote() {
	ui.noteLabel->clear();
}

