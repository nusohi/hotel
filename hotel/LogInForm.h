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
	//��¼
	void signIn();
	//�˳���¼
	void signOut();
	//��֤����
	bool checkPassword();
	bool isPass();
	//��ʾ��Ϣ	��ʾ������
	void showNote(QString note, QString color = "black", int time = 3000);
	void hideNote();

private:
	void initial();
	//�л�ģʽ
	void signInModel();
	void signOutModel();
	
	bool pass;
	//��ʱ��
	QTimer* timer;
};
