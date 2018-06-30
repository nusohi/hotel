/********************************************************************************
** Form generated from reading UI file 'BossCtrl.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOSSCTRL_H
#define UI_BOSSCTRL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BossCtrl
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *addRoomBtn;
    QPushButton *deleteRoomBtn;
    QHBoxLayout *horizontalLayout;
    QPushButton *showBillBtn;
    QPushButton *closeBillBtn;
    QPushButton *outputBillBtn;

    void setupUi(QWidget *BossCtrl)
    {
        if (BossCtrl->objectName().isEmpty())
            BossCtrl->setObjectName(QStringLiteral("BossCtrl"));
        BossCtrl->resize(261, 202);
        verticalLayout = new QVBoxLayout(BossCtrl);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        addRoomBtn = new QPushButton(BossCtrl);
        addRoomBtn->setObjectName(QStringLiteral("addRoomBtn"));

        verticalLayout->addWidget(addRoomBtn);

        deleteRoomBtn = new QPushButton(BossCtrl);
        deleteRoomBtn->setObjectName(QStringLiteral("deleteRoomBtn"));

        verticalLayout->addWidget(deleteRoomBtn);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        showBillBtn = new QPushButton(BossCtrl);
        showBillBtn->setObjectName(QStringLiteral("showBillBtn"));

        horizontalLayout->addWidget(showBillBtn);

        closeBillBtn = new QPushButton(BossCtrl);
        closeBillBtn->setObjectName(QStringLiteral("closeBillBtn"));

        horizontalLayout->addWidget(closeBillBtn);


        verticalLayout->addLayout(horizontalLayout);

        outputBillBtn = new QPushButton(BossCtrl);
        outputBillBtn->setObjectName(QStringLiteral("outputBillBtn"));

        verticalLayout->addWidget(outputBillBtn);


        retranslateUi(BossCtrl);

        QMetaObject::connectSlotsByName(BossCtrl);
    } // setupUi

    void retranslateUi(QWidget *BossCtrl)
    {
        BossCtrl->setWindowTitle(QApplication::translate("BossCtrl", "BossCtrl", Q_NULLPTR));
        addRoomBtn->setText(QApplication::translate("BossCtrl", "\346\267\273\345\212\240\346\210\277\351\227\264", Q_NULLPTR));
        deleteRoomBtn->setText(QApplication::translate("BossCtrl", "\345\210\240\351\231\244\346\210\277\351\227\264", Q_NULLPTR));
        showBillBtn->setText(QApplication::translate("BossCtrl", "\346\230\276\347\244\272\350\264\246\345\215\225", Q_NULLPTR));
        closeBillBtn->setText(QApplication::translate("BossCtrl", "\345\205\263\351\227\255\350\264\246\345\215\225", Q_NULLPTR));
        outputBillBtn->setText(QApplication::translate("BossCtrl", "\350\264\246\345\215\225\350\276\223\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BossCtrl: public Ui_BossCtrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOSSCTRL_H
