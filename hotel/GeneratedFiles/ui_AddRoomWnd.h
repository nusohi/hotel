/********************************************************************************
** Form generated from reading UI file 'AddRoomWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDROOMWND_H
#define UI_ADDROOMWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddRoomWnd
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *typeBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QLineEdit *IDEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *noteLabel;
    QPushButton *addBtn;

    void setupUi(QWidget *AddRoomWnd)
    {
        if (AddRoomWnd->objectName().isEmpty())
            AddRoomWnd->setObjectName(QStringLiteral("AddRoomWnd"));
        AddRoomWnd->resize(454, 122);
        verticalLayout = new QVBoxLayout(AddRoomWnd);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(AddRoomWnd);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        typeBox = new QComboBox(AddRoomWnd);
        typeBox->setObjectName(QStringLiteral("typeBox"));

        horizontalLayout_3->addWidget(typeBox);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(AddRoomWnd);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        IDEdit = new QLineEdit(AddRoomWnd);
        IDEdit->setObjectName(QStringLiteral("IDEdit"));

        horizontalLayout_2->addWidget(IDEdit);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        noteLabel = new QLabel(AddRoomWnd);
        noteLabel->setObjectName(QStringLiteral("noteLabel"));

        horizontalLayout->addWidget(noteLabel);

        addBtn = new QPushButton(AddRoomWnd);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addBtn->sizePolicy().hasHeightForWidth());
        addBtn->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(addBtn);


        verticalLayout->addLayout(horizontalLayout);

        IDEdit->raise();
        typeBox->raise();
        label_4->raise();
        label_7->raise();
        addBtn->raise();
        addBtn->raise();
        noteLabel->raise();
        addBtn->raise();

        retranslateUi(AddRoomWnd);

        QMetaObject::connectSlotsByName(AddRoomWnd);
    } // setupUi

    void retranslateUi(QWidget *AddRoomWnd)
    {
        AddRoomWnd->setWindowTitle(QApplication::translate("AddRoomWnd", "AddRoomWnd", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddRoomWnd", "\346\210\277\351\227\264\347\261\273\345\236\213", Q_NULLPTR));
        typeBox->clear();
        typeBox->insertItems(0, QStringList()
         << QApplication::translate("AddRoomWnd", "\346\240\207\351\227\264", Q_NULLPTR)
         << QApplication::translate("AddRoomWnd", "\345\215\225\351\227\264", Q_NULLPTR)
         << QApplication::translate("AddRoomWnd", "\345\245\227\346\210\277", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("AddRoomWnd", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        noteLabel->setText(QString());
        addBtn->setText(QApplication::translate("AddRoomWnd", "\346\267\273\345\212\240", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddRoomWnd: public Ui_AddRoomWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDROOMWND_H
