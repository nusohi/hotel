#pragma once

#include <QWidget>
#include "ui_BossCtrl.h"

class BossCtrl : public QWidget
{
	Q_OBJECT

public:
	BossCtrl(QWidget *parent = Q_NULLPTR);
	~BossCtrl() {}

private:
	Ui::BossCtrl ui;
};
