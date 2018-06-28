/********************************************************************************
** Form generated from reading UI file 'RoomInfoTable.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMINFOTABLE_H
#define UI_ROOMINFOTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomInfoTable
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *roomTypeBox;
    QSpacerItem *horizontalSpacer;
    QTableWidget *roomInfoTable;

    void setupUi(QWidget *RoomInfoTable)
    {
        if (RoomInfoTable->objectName().isEmpty())
            RoomInfoTable->setObjectName(QStringLiteral("RoomInfoTable"));
        RoomInfoTable->resize(550, 360);
        verticalLayout_2 = new QVBoxLayout(RoomInfoTable);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(RoomInfoTable);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        roomTypeBox = new QComboBox(RoomInfoTable);
        roomTypeBox->setObjectName(QStringLiteral("roomTypeBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(roomTypeBox->sizePolicy().hasHeightForWidth());
        roomTypeBox->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(roomTypeBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        roomInfoTable = new QTableWidget(RoomInfoTable);
        if (roomInfoTable->columnCount() < 3)
            roomInfoTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        roomInfoTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        roomInfoTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        roomInfoTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        roomInfoTable->setObjectName(QStringLiteral("roomInfoTable"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(roomInfoTable->sizePolicy().hasHeightForWidth());
        roomInfoTable->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(roomInfoTable);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(RoomInfoTable);

        QMetaObject::connectSlotsByName(RoomInfoTable);
    } // setupUi

    void retranslateUi(QWidget *RoomInfoTable)
    {
        RoomInfoTable->setWindowTitle(QApplication::translate("RoomInfoTable", "RoomInfoTable", Q_NULLPTR));
        label->setText(QApplication::translate("RoomInfoTable", "\346\210\277\351\227\264\344\277\241\346\201\257", Q_NULLPTR));
        roomTypeBox->clear();
        roomTypeBox->insertItems(0, QStringList()
         << QApplication::translate("RoomInfoTable", "\346\211\200\346\234\211\347\261\273\345\236\213", Q_NULLPTR)
         << QApplication::translate("RoomInfoTable", "\346\240\207\351\227\264", Q_NULLPTR)
         << QApplication::translate("RoomInfoTable", "\345\215\225\351\227\264", Q_NULLPTR)
         << QApplication::translate("RoomInfoTable", "\345\245\227\346\210\277", Q_NULLPTR)
        );
        QTableWidgetItem *___qtablewidgetitem = roomInfoTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RoomInfoTable", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = roomInfoTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RoomInfoTable", "\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = roomInfoTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("RoomInfoTable", "\347\212\266\346\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RoomInfoTable: public Ui_RoomInfoTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMINFOTABLE_H
