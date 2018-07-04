#include "hotel.h"





hotel::hotel(QWidget *parent)
	: QWidget(parent)
	, headMenu(this)
	, checkInWnd(this)
	, checkOutWnd(this)
	, bossWnd(this)
{
	//ui.setupUi(this);
	initial();

	QObject::connect(headMenu.ui.inPartBtn,		SIGNAL(toggled(bool)), this, SLOT(change()));
	QObject::connect(headMenu.ui.outPartBtn,	SIGNAL(toggled(bool)), this, SLOT(change()));
	QObject::connect(headMenu.ui.bossPartBtn,	SIGNAL(toggled(bool)), this, SLOT(change()));

}

void hotel::initial() {
	//布局
	layout = new QVBoxLayout(this);
	layout->addWidget(&headMenu);
	layout->addWidget(&checkInWnd);
	layout->addWidget(&checkOutWnd);
	layout->addWidget(&bossWnd);
	this->setLayout(layout);
	//初始状态 入住模式
	headMenu.ui.inPartBtn->setChecked(true);
	inPartModel();
	//大小
	this->setFixedSize(1100, 800);
}

void hotel::change() {
	if (headMenu.ui.inPartBtn->isChecked()) {
		inPartModel();
	}
	else if (headMenu.ui.outPartBtn->isChecked()) {
		outPartModel();
	}
	else if (headMenu.ui.bossPartBtn->isChecked()) {
		bossPartModel();
	}
}

void hotel::inPartModel() {
	checkInWnd.setVisible(true);
	checkOutWnd.setVisible(false);
	bossWnd.setVisible(false);
	checkInWnd.refresh();
}
void hotel::outPartModel() {
	checkInWnd.setVisible(false);
	checkOutWnd.setVisible(true);
	bossWnd.setVisible(false);
	checkOutWnd.refresh();
}
void hotel::bossPartModel(){
	checkInWnd.setVisible(false);
	checkOutWnd.setVisible(false);
	bossWnd.setVisible(true);
	bossWnd.refresh();
}

void hotel::closeEvent(QCloseEvent *event) {
	roomDB.saveMap();
	billDB.saveMap();
}
