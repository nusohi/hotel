#pragma once
#include <QWidget>
#include "ui_BossCtrl.h"



class BossCtrl : public QWidget
{
	Q_OBJECT

public:
	BossCtrl(QWidget *parent = Q_NULLPTR);
	~BossCtrl() {}
public:
	Ui::BossCtrl ui;
public slots:
	//禁用与解禁
	void enable();
	void disable();
	//切换模式
	void billOnModel();
	void billOffModel();
	void roomOnModel();
	void roomOffModel();
private:
	void initial();

};

