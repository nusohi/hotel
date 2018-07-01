#include "LogInForm.h"

LogInForm::LogInForm(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initial();

	//µÇÂ¼°´Å¥
	QObject::connect(ui.signInBtn,		SIGNAL(clicked(bool)),		this, SLOT(signIn()));
	QObject::connect(ui.passwordEdit,	SIGNAL(returnPressed()),	this, SLOT(signIn()));
	//ÍË³öµÇÂ¼°´Å¥
	QObject::connect(ui.signOutBtn, SIGNAL(clicked(bool)),	this, SLOT(signOut()));
	//-----¼ÆÊ±Æ÷--Òþ²ØÌáÊ¾
	QObject::connect(timer,			SIGNAL(timeout()),		this, SLOT(hideNote()));
}


void LogInForm::initial() {
	pass = false;
	this->setFixedSize(280, 160);

	//ÔÝÊ±¹Ì¶¨ÕË»§ºÍÃÜÂë
	ui.userNameEdit->setText(u8"admin");
	ui.userNameEdit->setDisabled(true);
	//°µÂë
	ui.passwordEdit->setEchoMode(QLineEdit::Password);
	//Òþ²Ø'ÍË³öµÇÂ¼'°´Å¥
	ui.signOutBtn->setVisible(false);
	//¼ÆÊ±Æ÷
	timer = new QTimer(this);
}

//µÇÂ¼
void LogInForm::signIn() {
	if (checkPassword()) {
		pass = true;
		signOutModel();
		emit passChanged(pass);
		showNote(u8"µÇÂ¼³É¹¦£¡");
	}
	else {
		showNote(u8"ÃÜÂë´íÎó£¡");
	}
}
//ÍË³öµÇÂ¼
void LogInForm::signOut() {
	signInModel();
	showNote(u8"ÒÑÍË³öµÇÂ¼£¡", "blue", 5000);
}

//ÇÐ»»Ä£Ê½
void LogInForm::signInModel() {
	//ÇÐ»»°´Å¥
	ui.signInBtn->setVisible(true);
	ui.signOutBtn->setVisible(false);
	//´ò¿ª±à¼­¿ò
	ui.passwordEdit->clear();
	ui.passwordEdit->setEnabled(true);
	pass = false;
}
void LogInForm::signOutModel() {
	//ÇÐ»»°´Å¥
	ui.signInBtn->setVisible(false);
	ui.signOutBtn->setVisible(true);
	//Çå³ýÃÜÂë£¬ËøËÀ±à¼­¿ò
	ui.passwordEdit->setText("¼Ù×°Õâ¸öÃÜÂëºÜ³¤ºÜ³¤£¡");
	ui.passwordEdit->setEnabled(false);
	pass = false;
}


//ÑéÖ¤ÃÜÂë
bool LogInForm::checkPassword() {
	QString password = ui.passwordEdit->text();
	pass = (password.compare("123123") == 0) ? true : false;
	return pass;
}
bool LogInForm::isPass() {
	return pass;
}

//ÌáÊ¾ÐÅÏ¢
void LogInForm::showNote(QString note, QString color, int time) {
	ui.noteLabel->setStyleSheet("color:" + color);
	ui.noteLabel->setText(note);
	timer->start(time);
}
void LogInForm::hideNote() {
	ui.noteLabel->clear();
}
