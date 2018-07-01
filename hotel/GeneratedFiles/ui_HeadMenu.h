/********************************************************************************
** Form generated from reading UI file 'HeadMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEADMENU_H
#define UI_HEADMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HeadMenu
{
public:
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QRadioButton *inPartBtn;
    QRadioButton *outPartBtn;
    QRadioButton *bossPartBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *HeadMenu)
    {
        if (HeadMenu->objectName().isEmpty())
            HeadMenu->setObjectName(QStringLiteral("HeadMenu"));
        HeadMenu->resize(538, 70);
        horizontalLayout_2 = new QHBoxLayout(HeadMenu);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(113, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        inPartBtn = new QRadioButton(HeadMenu);
        inPartBtn->setObjectName(QStringLiteral("inPartBtn"));

        horizontalLayout->addWidget(inPartBtn);

        outPartBtn = new QRadioButton(HeadMenu);
        outPartBtn->setObjectName(QStringLiteral("outPartBtn"));

        horizontalLayout->addWidget(outPartBtn);

        bossPartBtn = new QRadioButton(HeadMenu);
        bossPartBtn->setObjectName(QStringLiteral("bossPartBtn"));

        horizontalLayout->addWidget(bossPartBtn);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(112, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        retranslateUi(HeadMenu);

        QMetaObject::connectSlotsByName(HeadMenu);
    } // setupUi

    void retranslateUi(QWidget *HeadMenu)
    {
        HeadMenu->setWindowTitle(QApplication::translate("HeadMenu", "HeadMenu", Q_NULLPTR));
        inPartBtn->setText(QApplication::translate("HeadMenu", "\345\205\245\344\275\217\347\231\273\350\256\260", Q_NULLPTR));
        outPartBtn->setText(QApplication::translate("HeadMenu", "\351\200\200\346\210\277", Q_NULLPTR));
        bossPartBtn->setText(QApplication::translate("HeadMenu", "\347\256\241\347\220\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HeadMenu: public Ui_HeadMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADMENU_H
