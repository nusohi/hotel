#pragma once

#include <QtWidgets/QWidget>
#include "ui_hotel.h"

class hotel : public QWidget
{
	Q_OBJECT

public:
	hotel(QWidget *parent = Q_NULLPTR);

private:
	Ui::hotelClass ui;
};
