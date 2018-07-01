#pragma once
#include <QWidget>
#include <qtimer.h>
#include "ui_LogInForm.h"




class LogInForm : public QWidget
{
	Q_OBJECT

public:
	LogInForm(QWidget *parent = Q_NULLPTR);
	~LogInForm() {}
public:
	Ui::LogInForm ui;

signals:
	void passChanged(bool);
public slots:
	//登录
	void signIn();
	//退出登录
	void signOut();
	//验证密码
	bool checkPassword();
	bool isPass();
	//提示信息	显示与隐藏
	void showNote(QString note, QString color = "black", int time = 3000);
	void hideNote();

private:
	void initial();
	//切换模式
	void signInModel();
	void signOutModel();
	
	bool pass;
	//计时器
	QTimer* timer;
};
