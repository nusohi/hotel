/********************************************************************************
** Form generated from reading UI file 'DeleteRoomWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEROOMWND_H
#define UI_DELETEROOMWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeleteRoomWnd
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *IDEdit;
    QPushButton *deleteBtn;
    QLabel *noteLabel;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *DeleteRoomWnd)
    {
        if (DeleteRoomWnd->objectName().isEmpty())
            DeleteRoomWnd->setObjectName(QStringLiteral("DeleteRoomWnd"));
        DeleteRoomWnd->resize(452, 120);
        verticalLayout = new QVBoxLayout(DeleteRoomWnd);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DeleteRoomWnd);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        IDEdit = new QLineEdit(DeleteRoomWnd);
        IDEdit->setObjectName(QStringLiteral("IDEdit"));

        horizontalLayout->addWidget(IDEdit);

        deleteBtn = new QPushButton(DeleteRoomWnd);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));

        horizontalLayout->addWidget(deleteBtn);


        verticalLayout->addLayout(horizontalLayout);

        noteLabel = new QLabel(DeleteRoomWnd);
        noteLabel->setObjectName(QStringLiteral("noteLabel"));

        verticalLayout->addWidget(noteLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(DeleteRoomWnd);

        QMetaObject::connectSlotsByName(DeleteRoomWnd);
    } // setupUi

    void retranslateUi(QWidget *DeleteRoomWnd)
    {
        DeleteRoomWnd->setWindowTitle(QApplication::translate("DeleteRoomWnd", "DeleteRoomWnd", Q_NULLPTR));
        label->setText(QApplication::translate("DeleteRoomWnd", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        deleteBtn->setText(QApplication::translate("DeleteRoomWnd", "\345\210\240\351\231\244", Q_NULLPTR));
        noteLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DeleteRoomWnd: public Ui_DeleteRoomWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEROOMWND_H
