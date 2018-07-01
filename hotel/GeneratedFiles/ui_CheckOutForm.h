/********************************************************************************
** Form generated from reading UI file 'CheckOutForm.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKOUTFORM_H
#define UI_CHECKOUTFORM_H

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

class Ui_CheckOutForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *roomIDEdit;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *checkInTimeEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *moneyEdit;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *billIDLabel;
    QLabel *noteLabel;
    QPushButton *checkOutBtn;

    void setupUi(QWidget *CheckOutForm)
    {
        if (CheckOutForm->objectName().isEmpty())
            CheckOutForm->setObjectName(QStringLiteral("CheckOutForm"));
        CheckOutForm->resize(763, 109);
        verticalLayout = new QVBoxLayout(CheckOutForm);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(CheckOutForm);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label);

        roomIDEdit = new QLineEdit(CheckOutForm);
        roomIDEdit->setObjectName(QStringLiteral("roomIDEdit"));

        horizontalLayout_2->addWidget(roomIDEdit);


        horizontalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(CheckOutForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_2);

        checkInTimeEdit = new QLineEdit(CheckOutForm);
        checkInTimeEdit->setObjectName(QStringLiteral("checkInTimeEdit"));

        horizontalLayout->addWidget(checkInTimeEdit);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(CheckOutForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_3);

        moneyEdit = new QLineEdit(CheckOutForm);
        moneyEdit->setObjectName(QStringLiteral("moneyEdit"));

        horizontalLayout_3->addWidget(moneyEdit);


        horizontalLayout_5->addLayout(horizontalLayout_3);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(CheckOutForm);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_4);

        billIDLabel = new QLabel(CheckOutForm);
        billIDLabel->setObjectName(QStringLiteral("billIDLabel"));

        horizontalLayout_4->addWidget(billIDLabel);


        horizontalLayout_7->addLayout(horizontalLayout_4);

        noteLabel = new QLabel(CheckOutForm);
        noteLabel->setObjectName(QStringLiteral("noteLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(noteLabel->sizePolicy().hasHeightForWidth());
        noteLabel->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(noteLabel);

        checkOutBtn = new QPushButton(CheckOutForm);
        checkOutBtn->setObjectName(QStringLiteral("checkOutBtn"));

        horizontalLayout_7->addWidget(checkOutBtn);


        verticalLayout->addLayout(horizontalLayout_7);


        retranslateUi(CheckOutForm);

        QMetaObject::connectSlotsByName(CheckOutForm);
    } // setupUi

    void retranslateUi(QWidget *CheckOutForm)
    {
        CheckOutForm->setWindowTitle(QApplication::translate("CheckOutForm", "CheckOutForm", Q_NULLPTR));
        label->setText(QApplication::translate("CheckOutForm", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("CheckOutForm", "\345\205\245\344\275\217\346\227\266\351\227\264", Q_NULLPTR));
        label_3->setText(QApplication::translate("CheckOutForm", "\346\266\210\350\264\271\351\207\221\351\242\235", Q_NULLPTR));
        label_4->setText(QApplication::translate("CheckOutForm", "\350\256\242\345\215\225\345\217\267", Q_NULLPTR));
        billIDLabel->setText(QString());
        noteLabel->setText(QApplication::translate("CheckOutForm", "\345\217\214\345\207\273\351\200\200\346\210\277\344\277\241\346\201\257\350\277\233\350\241\214\351\200\211\346\213\251", Q_NULLPTR));
        checkOutBtn->setText(QApplication::translate("CheckOutForm", "\351\200\200\346\210\277", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CheckOutForm: public Ui_CheckOutForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUTFORM_H
