/********************************************************************************
** Form generated from reading UI file 'BillTable.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILLTABLE_H
#define UI_BILLTABLE_H

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

class Ui_BillTable
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QComboBox *typeBox;
    QSpacerItem *horizontalSpacer_4;
    QTableWidget *billTable;

    void setupUi(QWidget *BillTable)
    {
        if (BillTable->objectName().isEmpty())
            BillTable->setObjectName(QStringLiteral("BillTable"));
        BillTable->resize(1000, 450);
        verticalLayout = new QVBoxLayout(BillTable);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_10 = new QLabel(BillTable);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout->addWidget(label_10);

        typeBox = new QComboBox(BillTable);
        typeBox->setObjectName(QStringLiteral("typeBox"));

        horizontalLayout->addWidget(typeBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        billTable = new QTableWidget(BillTable);
        if (billTable->columnCount() < 9)
            billTable->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        billTable->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        billTable->setObjectName(QStringLiteral("billTable"));

        verticalLayout->addWidget(billTable);


        retranslateUi(BillTable);

        QMetaObject::connectSlotsByName(BillTable);
    } // setupUi

    void retranslateUi(QWidget *BillTable)
    {
        BillTable->setWindowTitle(QApplication::translate("BillTable", "BillTable", Q_NULLPTR));
        label_10->setText(QApplication::translate("BillTable", "\350\264\246\345\215\225\350\256\260\345\275\225", Q_NULLPTR));
        typeBox->clear();
        typeBox->insertItems(0, QStringList()
         << QApplication::translate("BillTable", "\346\211\200\346\234\211\347\261\273\345\236\213", Q_NULLPTR)
         << QApplication::translate("BillTable", "\351\242\204\350\256\242", Q_NULLPTR)
         << QApplication::translate("BillTable", "\345\205\245\344\275\217", Q_NULLPTR)
         << QApplication::translate("BillTable", "\345\256\214\346\210\220", Q_NULLPTR)
        );
        QTableWidgetItem *___qtablewidgetitem = billTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BillTable", "\345\215\225\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = billTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BillTable", "\347\212\266\346\200\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = billTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BillTable", "\345\247\223\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = billTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("BillTable", "\350\272\253\344\273\275\350\257\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = billTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("BillTable", "\346\210\277\351\227\264\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = billTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("BillTable", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = billTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("BillTable", "\345\205\245\344\275\217\345\244\251\346\225\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = billTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("BillTable", "\345\205\245\344\275\217\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = billTable->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("BillTable", "\351\200\200\346\210\277\346\227\266\351\227\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BillTable: public Ui_BillTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILLTABLE_H
