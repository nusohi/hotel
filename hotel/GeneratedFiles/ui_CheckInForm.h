/********************************************************************************
** Form generated from reading UI file 'CheckInForm.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKINFORM_H
#define UI_CHECKINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckInForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *singleClientBtn;
    QRadioButton *doubleClientBtn;
    QFrame *line_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *nameA;
    QLabel *label_2;
    QLineEdit *IDA;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *nameB;
    QLabel *label_6;
    QLineEdit *IDB;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *roomTypeBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QComboBox *roomIDBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *ddhLabel;
    QLabel *billIDLabel;
    QPushButton *bookBtn;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QSpinBox *stayDaysBox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_11;
    QLabel *leftRoomLabel;
    QLabel *noteLabel;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBookBox;
    QPushButton *checkInBtn;

    void setupUi(QWidget *CheckInForm)
    {
        if (CheckInForm->objectName().isEmpty())
            CheckInForm->setObjectName(QStringLiteral("CheckInForm"));
        CheckInForm->resize(690, 185);
        verticalLayout_2 = new QVBoxLayout(CheckInForm);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        singleClientBtn = new QRadioButton(CheckInForm);
        singleClientBtn->setObjectName(QStringLiteral("singleClientBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(singleClientBtn->sizePolicy().hasHeightForWidth());
        singleClientBtn->setSizePolicy(sizePolicy);
        singleClientBtn->setChecked(false);

        verticalLayout_3->addWidget(singleClientBtn);

        doubleClientBtn = new QRadioButton(CheckInForm);
        doubleClientBtn->setObjectName(QStringLiteral("doubleClientBtn"));
        sizePolicy.setHeightForWidth(doubleClientBtn->sizePolicy().hasHeightForWidth());
        doubleClientBtn->setSizePolicy(sizePolicy);
        doubleClientBtn->setChecked(true);

        verticalLayout_3->addWidget(doubleClientBtn);


        horizontalLayout_5->addLayout(verticalLayout_3);

        line_3 = new QFrame(CheckInForm);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(CheckInForm);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        nameA = new QLineEdit(CheckInForm);
        nameA->setObjectName(QStringLiteral("nameA"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nameA->sizePolicy().hasHeightForWidth());
        nameA->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(nameA);

        label_2 = new QLabel(CheckInForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        IDA = new QLineEdit(CheckInForm);
        IDA->setObjectName(QStringLiteral("IDA"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(IDA->sizePolicy().hasHeightForWidth());
        IDA->setSizePolicy(sizePolicy2);
        IDA->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        horizontalLayout_2->addWidget(IDA);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(CheckInForm);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        nameB = new QLineEdit(CheckInForm);
        nameB->setObjectName(QStringLiteral("nameB"));
        sizePolicy1.setHeightForWidth(nameB->sizePolicy().hasHeightForWidth());
        nameB->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(nameB);

        label_6 = new QLabel(CheckInForm);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        IDB = new QLineEdit(CheckInForm);
        IDB->setObjectName(QStringLiteral("IDB"));
        sizePolicy2.setHeightForWidth(IDB->sizePolicy().hasHeightForWidth());
        IDB->setSizePolicy(sizePolicy2);
        IDB->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        horizontalLayout->addWidget(IDB);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_5->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(CheckInForm);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(4);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(label_4);

        roomTypeBox = new QComboBox(CheckInForm);
        roomTypeBox->setObjectName(QStringLiteral("roomTypeBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(4);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(roomTypeBox->sizePolicy().hasHeightForWidth());
        roomTypeBox->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(roomTypeBox);


        horizontalLayout_9->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(CheckInForm);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(4);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy5);

        horizontalLayout_4->addWidget(label_7);

        roomIDBox = new QComboBox(CheckInForm);
        roomIDBox->setObjectName(QStringLiteral("roomIDBox"));
        sizePolicy4.setHeightForWidth(roomIDBox->sizePolicy().hasHeightForWidth());
        roomIDBox->setSizePolicy(sizePolicy4);

        horizontalLayout_4->addWidget(roomIDBox);


        horizontalLayout_9->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        ddhLabel = new QLabel(CheckInForm);
        ddhLabel->setObjectName(QStringLiteral("ddhLabel"));

        horizontalLayout_6->addWidget(ddhLabel);

        billIDLabel = new QLabel(CheckInForm);
        billIDLabel->setObjectName(QStringLiteral("billIDLabel"));

        horizontalLayout_6->addWidget(billIDLabel);


        horizontalLayout_9->addLayout(horizontalLayout_6);

        bookBtn = new QPushButton(CheckInForm);
        bookBtn->setObjectName(QStringLiteral("bookBtn"));
        sizePolicy.setHeightForWidth(bookBtn->sizePolicy().hasHeightForWidth());
        bookBtn->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(bookBtn);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_3 = new QLabel(CheckInForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy6);

        horizontalLayout_7->addWidget(label_3);

        stayDaysBox = new QSpinBox(CheckInForm);
        stayDaysBox->setObjectName(QStringLiteral("stayDaysBox"));
        sizePolicy1.setHeightForWidth(stayDaysBox->sizePolicy().hasHeightForWidth());
        stayDaysBox->setSizePolicy(sizePolicy1);
        stayDaysBox->setMinimumSize(QSize(49, 25));
        stayDaysBox->setAutoFillBackground(false);

        horizontalLayout_7->addWidget(stayDaysBox);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_11 = new QLabel(CheckInForm);
        label_11->setObjectName(QStringLiteral("label_11"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(2);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy7);

        horizontalLayout_8->addWidget(label_11);

        leftRoomLabel = new QLabel(CheckInForm);
        leftRoomLabel->setObjectName(QStringLiteral("leftRoomLabel"));
        sizePolicy7.setHeightForWidth(leftRoomLabel->sizePolicy().hasHeightForWidth());
        leftRoomLabel->setSizePolicy(sizePolicy7);

        horizontalLayout_8->addWidget(leftRoomLabel);

        noteLabel = new QLabel(CheckInForm);
        noteLabel->setObjectName(QStringLiteral("noteLabel"));

        horizontalLayout_8->addWidget(noteLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);


        horizontalLayout_7->addLayout(horizontalLayout_8);

        checkBookBox = new QCheckBox(CheckInForm);
        checkBookBox->setObjectName(QStringLiteral("checkBookBox"));
        sizePolicy.setHeightForWidth(checkBookBox->sizePolicy().hasHeightForWidth());
        checkBookBox->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(checkBookBox);

        checkInBtn = new QPushButton(CheckInForm);
        checkInBtn->setObjectName(QStringLiteral("checkInBtn"));
        sizePolicy.setHeightForWidth(checkInBtn->sizePolicy().hasHeightForWidth());
        checkInBtn->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(checkInBtn);


        verticalLayout_2->addLayout(horizontalLayout_7);


        retranslateUi(CheckInForm);

        QMetaObject::connectSlotsByName(CheckInForm);
    } // setupUi

    void retranslateUi(QWidget *CheckInForm)
    {
        CheckInForm->setWindowTitle(QApplication::translate("CheckInForm", "CheckInForm", Q_NULLPTR));
        singleClientBtn->setText(QApplication::translate("CheckInForm", "\345\215\225", Q_NULLPTR));
        doubleClientBtn->setText(QApplication::translate("CheckInForm", "\345\217\214", Q_NULLPTR));
        label->setText(QApplication::translate("CheckInForm", "\345\247\223\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("CheckInForm", "\350\272\253\344\273\275\350\257\201\345\217\267\347\240\201", Q_NULLPTR));
        label_5->setText(QApplication::translate("CheckInForm", "\345\247\223\345\220\215", Q_NULLPTR));
        label_6->setText(QApplication::translate("CheckInForm", "\350\272\253\344\273\275\350\257\201\345\217\267\347\240\201", Q_NULLPTR));
        label_4->setText(QApplication::translate("CheckInForm", "\346\210\277\351\227\264\347\261\273\345\236\213", Q_NULLPTR));
        roomTypeBox->clear();
        roomTypeBox->insertItems(0, QStringList()
         << QApplication::translate("CheckInForm", "\346\240\207\351\227\264", Q_NULLPTR)
         << QApplication::translate("CheckInForm", "\345\215\225\351\227\264", Q_NULLPTR)
         << QApplication::translate("CheckInForm", "\345\245\227\346\210\277", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("CheckInForm", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        ddhLabel->setText(QApplication::translate("CheckInForm", "\350\256\242\345\215\225\345\217\267\357\274\232", Q_NULLPTR));
        billIDLabel->setText(QString());
        bookBtn->setText(QApplication::translate("CheckInForm", "\351\242\204\350\256\242", Q_NULLPTR));
        label_3->setText(QApplication::translate("CheckInForm", "\345\205\245\344\275\217\345\244\251\346\225\260", Q_NULLPTR));
        label_11->setText(QApplication::translate("CheckInForm", "\344\275\231\351\207\217:", Q_NULLPTR));
        leftRoomLabel->setText(QApplication::translate("CheckInForm", "0", Q_NULLPTR));
        noteLabel->setText(QString());
        checkBookBox->setText(QApplication::translate("CheckInForm", "\345\267\262\351\242\204\350\256\242", Q_NULLPTR));
        checkInBtn->setText(QApplication::translate("CheckInForm", "\347\231\273\350\256\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CheckInForm: public Ui_CheckInForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKINFORM_H
