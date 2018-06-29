#include "CheckInWnd.h"



CheckInWnd::CheckInWnd(QWidget* parent) 
	: QWidget(parent)
	, checkInForm(this)
	, roomInfoTable(this)
	, bookerInfoTable(this)
{
	layout = new QVBoxLayout(this);
	layout->addWidget(&checkInForm);
	layout->addWidget(&roomInfoTable);
	layout->addWidget(&bookerInfoTable);
	checkInForm.show();
	roomInfoTable.show();
	bookerInfoTable.show();

	this->setLayout(layout);
}