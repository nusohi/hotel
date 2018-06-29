/********************************************************************************
** Form generated from reading UI file 'BookerInfoTable.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKERINFOTABLE_H
#define UI_BOOKERINFOTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookerInfoTable
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *bookerTable;

    void setupUi(QWidget *BookerInfoTable)
    {
        if (BookerInfoTable->objectName().isEmpty())
            BookerInfoTable->setObjectName(QStringLiteral("BookerInfoTable"));
        BookerInfoTable->resize(552, 354);
        verticalLayout = new QVBoxLayout(BookerInfoTable);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(BookerInfoTable);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        bookerTable = new QTableWidget(BookerInfoTable);
        if (bookerTable->columnCount() < 5)
            bookerTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        bookerTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        bookerTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        bookerTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        bookerTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        bookerTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        bookerTable->setObjectName(QStringLiteral("bookerTable"));

        verticalLayout->addWidget(bookerTable);


        retranslateUi(BookerInfoTable);

        QMetaObject::connectSlotsByName(BookerInfoTable);
    } // setupUi

    void retranslateUi(QWidget *BookerInfoTable)
    {
        BookerInfoTable->setWindowTitle(QApplication::translate("BookerInfoTable", "BookerInfoTable", Q_NULLPTR));
        label->setText(QApplication::translate("BookerInfoTable", "\345\267\262\351\242\204\350\256\242\344\277\241\346\201\257", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = bookerTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BookerInfoTable", "\345\215\225\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = bookerTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BookerInfoTable", "\345\256\242\346\210\267A", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = bookerTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BookerInfoTable", "\345\256\242\346\210\267B", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = bookerTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("BookerInfoTable", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = bookerTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("BookerInfoTable", "\346\210\277\351\227\264\347\261\273\345\236\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BookerInfoTable: public Ui_BookerInfoTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKERINFOTABLE_H
