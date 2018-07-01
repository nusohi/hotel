#pragma once

#include <QWidget>
#include "ui_HeadMenu.h"

class HeadMenu : public QWidget
{
	Q_OBJECT

public:
	HeadMenu(QWidget *parent = Q_NULLPTR);
	~HeadMenu() {}

public:
	Ui::HeadMenu ui;
};
