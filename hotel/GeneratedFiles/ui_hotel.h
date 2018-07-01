/********************************************************************************
** Form generated from reading UI file 'hotel.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTEL_H
#define UI_HOTEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hotelClass
{
public:

    void setupUi(QWidget *hotelClass)
    {
        if (hotelClass->objectName().isEmpty())
            hotelClass->setObjectName(QStringLiteral("hotelClass"));
        hotelClass->resize(936, 710);

        retranslateUi(hotelClass);

        QMetaObject::connectSlotsByName(hotelClass);
    } // setupUi

    void retranslateUi(QWidget *hotelClass)
    {
        hotelClass->setWindowTitle(QApplication::translate("hotelClass", "hotel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class hotelClass: public Ui_hotelClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTEL_H
