/********************************************************************************
** Form generated from reading UI file 'LogInForm.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogInForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *userNameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *noteLabel;
    QPushButton *signInBtn;
    QPushButton *signOutBtn;

    void setupUi(QWidget *LogInForm)
    {
        if (LogInForm->objectName().isEmpty())
            LogInForm->setObjectName(QStringLiteral("LogInForm"));
        LogInForm->resize(392, 165);
        verticalLayout = new QVBoxLayout(LogInForm);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(LogInForm);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        userNameEdit = new QLineEdit(LogInForm);
        userNameEdit->setObjectName(QStringLiteral("userNameEdit"));

        horizontalLayout->addWidget(userNameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(LogInForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        passwordEdit = new QLineEdit(LogInForm);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));

        horizontalLayout_2->addWidget(passwordEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        noteLabel = new QLabel(LogInForm);
        noteLabel->setObjectName(QStringLiteral("noteLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(noteLabel->sizePolicy().hasHeightForWidth());
        noteLabel->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(noteLabel);

        signInBtn = new QPushButton(LogInForm);
        signInBtn->setObjectName(QStringLiteral("signInBtn"));

        horizontalLayout_3->addWidget(signInBtn);

        signOutBtn = new QPushButton(LogInForm);
        signOutBtn->setObjectName(QStringLiteral("signOutBtn"));

        horizontalLayout_3->addWidget(signOutBtn);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(LogInForm);

        QMetaObject::connectSlotsByName(LogInForm);
    } // setupUi

    void retranslateUi(QWidget *LogInForm)
    {
        LogInForm->setWindowTitle(QApplication::translate("LogInForm", "LogInForm", Q_NULLPTR));
        label->setText(QApplication::translate("LogInForm", "\350\264\246  \345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("LogInForm", "\345\257\206  \347\240\201", Q_NULLPTR));
        noteLabel->setText(QApplication::translate("LogInForm", "\350\257\267\347\231\273\345\275\225", Q_NULLPTR));
        signInBtn->setText(QApplication::translate("LogInForm", "\347\231\273\345\275\225", Q_NULLPTR));
        signOutBtn->setText(QApplication::translate("LogInForm", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LogInForm: public Ui_LogInForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
