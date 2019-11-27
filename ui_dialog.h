/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QListView *listView;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QGroupBox *groupBox_2;
    QListView *listView_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(456, 572);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 351, 391));
        listView = new QListView(groupBox);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 20, 331, 301));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 360, 101, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 360, 91, 16));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 330, 181, 16));
        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 410, 351, 151));
        listView_2 = new QListView(groupBox_2);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));
        listView_2->setGeometry(QRect(10, 20, 331, 121));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(365, 28, 85, 30));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(365, 61, 85, 30));
        pushButton_3 = new QPushButton(Dialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(365, 105, 85, 30));
        pushButton_4 = new QPushButton(Dialog);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(365, 138, 85, 30));
        pushButton_5 = new QPushButton(Dialog);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(365, 170, 85, 30));
        pushButton_6 = new QPushButton(Dialog);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(365, 218, 85, 30));
        pushButton_7 = new QPushButton(Dialog);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(365, 250, 85, 30));
        pushButton_8 = new QPushButton(Dialog);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(365, 530, 85, 30));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog", "\345\267\262\347\274\226\350\257\221\346\210\220\345\212\237", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "*S\357\274\232\345\220\257\347\224\250\346\211\247\350\241\214\346\235\241\344\273\266", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "*P\357\274\232\345\221\250\346\234\237\346\211\247\350\241\214", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "*I\357\274\232\345\275\223HMI\345\220\257\345\212\250\346\227\266\345\215\263\346\211\247\350\241\214\344\270\200\346\254\241", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Dialog", "\346\234\252\347\274\226\350\257\221\346\210\220\345\212\237", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "\346\226\260\345\242\236...", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "\345\210\240\351\231\244", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Dialog", "\347\274\226\350\276\221", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Dialog", "\345\244\215\345\210\266", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Dialog", "\347\262\230\350\264\264", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Dialog", "\345\257\274\345\207\272...", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Dialog", "\345\257\274\345\205\245...", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Dialog", "\347\246\273\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
