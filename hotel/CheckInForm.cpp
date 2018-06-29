#include "CheckInForm.h"
#include <qtimer.h>




CheckInForm::CheckInForm(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//初始化
	initial();
	//加载房间号
	updateRoomIDBox(0);

	//---------------------预订
	QObject::connect(ui.bookBtn,			SIGNAL(clicked(bool)),	this, SLOT(book()));
	//---------------------登记入住
	QObject::connect(ui.checkInBtn,			SIGNAL(clicked(bool)),	this, SLOT(checkIn()));
	//-----'单','双'按钮--（禁用文本框）
	QObject::connect(ui.doubleClientBtn,	SIGNAL(toggled(bool)),	this, SLOT(ouDoubleClientBtn()));		//false ?
	QObject::connect(ui.singleClientBtn,	SIGNAL(toggled(bool)),	this, SLOT(onSingleClientBtn()));
	//-----'已预订'按钮
	QObject::connect(ui.checkBookBox,		SIGNAL(stateChanged(int)),			this,	SLOT(onCheckBookBox(int)));
	//-----房间类型BOX--更新房间号BOX
	QObject::connect(ui.roomTypeBox,		SIGNAL(currentIndexChanged(int)),	this,	SLOT(updateRoomIDBox(int)));
	//-----计时器--隐藏提示
	QObject::connect(timer,					SIGNAL(timeout()),					this,	SLOT(hideNote()));
}



//初始化
void CheckInForm::initial() {

	//输入检查	和	SpinBox入住天数 >= 1
	QRegExp digitIDC("(\\d{15}|\\d{17}(\\d|[xX]))");
	QValidator *ValIDigit = new QRegExpValidator(digitIDC, this);
	ui.IDA->setValidator(ValIDigit);
	ui.IDB->setValidator(ValIDigit);
	ui.stayDaysBox->setMinimum(1);

	//计时器	供noteLabel用
	timer = new QTimer(this);

	//隐藏 billIDLabel
	ui.billIDLabel->setVisible(false);
	ui.ddhLabel->setVisible(false);
}

//预订
void CheckInForm::book() {
	if (!checkInputStatus()) {
		showNote(u8"请输入正确的值！", "red", 2000);
	}
	else {
		QString name[2], ID[2];
		//room info
		int roomID = ui.roomIDBox->currentText().toInt();
		if (roomDB.query(roomID)->getStatus() != VACANT) {
			showNote(u8"不是空房！！", "red");
		}
		else {
			RoomType roomType = RoomType(ui.roomTypeBox->currentText().toInt());
			RoomBase room(roomID, roomType);
			roomDB.query(roomID)->setStatus(BOOKED);		//很重要
			sumBill[BOOKING]++;								//也很重要
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
			showNote(u8"预订成功！");
		}
	}
}

//登记入住
void CheckInForm::checkIn() {
	if (ui.checkBookBox->checkState() == Qt::Checked) {
		bookIn();
		return;
	}
	if (!checkInputStatus()) {
		showNote(u8"请输入正确的值！", "red", 2000);
	}
	else {
		int roomID = ui.roomIDBox->currentText().toInt();
		if (roomDB.query(roomID)->getStatus() != VACANT) {
			showNote(u8"不是空房！！");
		}
		else {
			QString name[2], ID[2];
			RoomType roomType = RoomType(ui.roomTypeBox->currentText().toInt());
			RoomBase room(roomID, roomType);
			roomDB.query(roomID)->setStatus(OCCUPIED);		//很重要
			sumBill[CHECKIN]++;								//也很重要
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
			showNote(u8"登记成功！");
		}
	}
}

//登记后入住
void CheckInForm::bookIn() {
	long billID = ui.billIDLabel->text().toLong();
	//billDB	roomDB	sumBill		sumRoom
	Bill* bill = billDB.query(billID);
	if (bill == NULL || billID == 0) {
		showNote(u8"请选择订单!", "red", 2000);
	}
	else if (bill->getStatus() == DONE) {
		showNote(u8"操作失败!该单已完成", "red");
	}
	else if (bill->getStatus() == CHECKIN) {
		showNote(u8"操作失败！该单已登记", "red");
	}
	else {
		bill->checkIn();
		roomDB.query(bill->getRoomID())->setStatus(OCCUPIED);
		sumBill[BOOKING]--;
		sumBill[CHECKIN]++;
		clearForm();
		billDB.saveMap();
		showNote(u8"入住成功！");
	}
}



//更新房间号 （和余量）
void CheckInForm::updateRoomIDBox(int index) {
							//此调用的index为 A0 B1 C2
	//先清除
	ui.roomIDBox->clear();
	//后查询
	long * roomID = roomDB.queryID(RoomType(index));
	//再填充
	for (int i = 0; i < sumRoom[index]; i++)
		ui.roomIDBox->insertItem(i, QString::number(roomID[i]));
	//更新余量显示
	ui.leftRoomLabel->setText(QString::number(sumRoom[index]));
	delete roomID;
}

//检查表单
bool CheckInForm::checkInputStatus() {
	//验证身份证号码		///第二个只能验证18位	///待修改
							///QRegExp RegExpIDC("^[1-9]\\d{5}(18|19|([23]\\d))\\d{2}((0[1-9])|(10|11|12))(([0-2][1-9])|10|20|30|31)\\d{3}[0-9Xx]$)|(^[1-9]\\d{5}\\d{2}((0[1-9])|(10|11|12))(([0-2][1-9])|10|20|30|31)\\d{2}$");
	QRegExp RegExpIDC("^\\d{6}(18\\d{2}|19\\d{2}|20[01]\\d)(0[1-9]|1[012])(0[1-9]|[12]\\d|3[01])\\d{3}(\\d|[xX])$");
	//双 Client B
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

//已预订按钮 checkBox
void CheckInForm::onCheckBookBox(int state) {
	if (state == Qt::Unchecked) {
		//预订按钮
		ui.bookBtn->setEnabled(true);
		//单双按钮
		ui.singleClientBtn->setEnabled(true);
		ui.doubleClientBtn->setEnabled(true);
		//BOX
		ui.roomTypeBox->setEnabled(true);
		ui.roomIDBox->setEnabled(true);
		ui.stayDaysBox->setEnabled(true);
		//文本编辑框
		ui.IDA->setEnabled(true);
		if (ui.doubleClientBtn->isChecked()) {
			ui.nameB->setEnabled(true);
			ui.IDB->setEnabled(true);
		}
		else {
			ui.nameB->setEnabled(false);
			ui.IDB->setEnabled(false);
		}
		//隐藏订单编号
		ui.billIDLabel->setVisible(false);
		ui.ddhLabel->setVisible(false);
	}
	else if (state == Qt::Checked) {
		//预订按钮
		ui.bookBtn->setEnabled(false);
		//单双按钮
		ui.singleClientBtn->setEnabled(false);
		ui.doubleClientBtn->setEnabled(false);
		//BOX
		ui.roomTypeBox->setEnabled(false);
		ui.roomIDBox->setEnabled(false);
		ui.stayDaysBox->setEnabled(false);
		//文本编辑框
		ui.IDA->setEnabled(false);
		if (ui.doubleClientBtn->isChecked()) {
			ui.nameB->setEnabled(false);
			ui.IDB->setEnabled(false);
		}
		//显示订单编号
		ui.billIDLabel->setVisible(true);
		ui.ddhLabel->setVisible(true);
	}
}
//单 双
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


//清除 Form
void CheckInForm::clearForm() {
	ui.nameA->clear();
	ui.nameB->clear();
	ui.IDA->clear();
	ui.IDB->clear();
	ui.billIDLabel->clear();
}
//提示信息
void CheckInForm::showNote(QString note, QString color, int time) {
	ui.noteLabel->setStyleSheet("color:" + color);
	ui.noteLabel->setText(note);
	timer->start(time);
}
void CheckInForm::hideNote() {
	ui.noteLabel->clear();
}


//从 Bill 填充		全
void CheckInForm::fillBill(Bill* bill) {
	// 房间信息
	fillRoom(&(bill->room));
	// Client A
	ui.nameA->setText(bill->clientA.getName());
	ui.IDA->setText(bill->clientA.getIDC());
	// Client B
	if (bill->isTwo()) {
		ui.nameB->setText(bill->clientB.getName());
		ui.IDB->setText(bill->clientB.getIDC());
	}
	// 入住天数	和订单号
	ui.stayDaysBox->setValue(bill->getStayDays());
	ui.billIDLabel->setText(QString::number(bill->getID()));
}
//从 RoomBase 填充		仅BOX
void CheckInForm::fillRoom(RoomBase* room) {
	int roomTypeIndex = int(room->getType());
	ui.roomTypeBox->setCurrentIndex(roomTypeIndex);
	updateRoomIDBox(roomTypeIndex);

	int index = ui.roomIDBox->findText(QString::number(room->getID()));
	ui.roomIDBox->setCurrentIndex(index);
}

