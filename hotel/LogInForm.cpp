#include "LogInForm.h"

LogInForm::LogInForm(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initial();

	//��¼��ť
	QObject::connect(ui.signInBtn,		SIGNAL(clicked(bool)),		this, SLOT(signIn()));
	QObject::connect(ui.passwordEdit,	SIGNAL(returnPressed()),	this, SLOT(signIn()));
	//�˳���¼��ť
	QObject::connect(ui.signOutBtn, SIGNAL(clicked(bool)),	this, SLOT(signOut()));
	//-----��ʱ��--������ʾ
	QObject::connect(timer,			SIGNAL(timeout()),		this, SLOT(hideNote()));
}


void LogInForm::initial() {
	pass = false;
	this->setFixedSize(280, 160);

	//��ʱ�̶��˻�������
	ui.userNameEdit->setText(u8"admin");
	ui.userNameEdit->setDisabled(true);
	//����
	ui.passwordEdit->setEchoMode(QLineEdit::Password);
	//����'�˳���¼'��ť
	ui.signOutBtn->setVisible(false);
	//��ʱ��
	timer = new QTimer(this);
}

//��¼
void LogInForm::signIn() {
	if (checkPassword()) {
		pass = true;
		signOutModel();
		emit passChanged(pass);
		showNote(u8"��¼�ɹ���");
	}
	else {
		showNote(u8"�������");
	}
}
//�˳���¼
void LogInForm::signOut() {
	signInModel();
	showNote(u8"���˳���¼��", "blue", 5000);
}

//�л�ģʽ
void LogInForm::signInModel() {
	//�л���ť
	ui.signInBtn->setVisible(true);
	ui.signOutBtn->setVisible(false);
	//�򿪱༭��
	ui.passwordEdit->clear();
	ui.passwordEdit->setEnabled(true);
	pass = false;
}
void LogInForm::signOutModel() {
	//�л���ť
	ui.signInBtn->setVisible(false);
	ui.signOutBtn->setVisible(true);
	//������룬�����༭��
	ui.passwordEdit->setText("��װ�������ܳ��ܳ���");
	ui.passwordEdit->setEnabled(false);
	pass = false;
}


//��֤����
bool LogInForm::checkPassword() {
	QString password = ui.passwordEdit->text();
	pass = (password.compare("123123") == 0) ? true : false;
	return pass;
}
bool LogInForm::isPass() {
	return pass;
}

//��ʾ��Ϣ
void LogInForm::showNote(QString note, QString color, int time) {
	ui.noteLabel->setStyleSheet("color:" + color);
	ui.noteLabel->setText(note);
	timer->start(time);
}
void LogInForm::hideNote() {
	ui.noteLabel->clear();
}
