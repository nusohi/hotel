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
	//��������
	void enable();
	void disable();
	//�л�ģʽ
	void billOnModel();
	void billOffModel();
	void roomOnModel();
	void roomOffModel();
private:
	void initial();

};

