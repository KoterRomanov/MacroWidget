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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QListWidget *complie_macro_listwidget;
    QGroupBox *groupBox_2;
    QListWidget *uncomplie_macro_listwidget;
    QPushButton *add_macro_button;
    QPushButton *delete_macro_button;
    QPushButton *edit_macro_button;
    QPushButton *copy_macro_button;
    QPushButton *paste_macro_button;
    QPushButton *export_macro_button;
    QPushButton *import_macro_button;
    QPushButton *close;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(456, 572);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 351, 391));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 360, 101, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 360, 91, 16));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 330, 181, 16));
        complie_macro_listwidget = new QListWidget(groupBox);
        complie_macro_listwidget->setObjectName(QString::fromUtf8("complie_macro_listwidget"));
        complie_macro_listwidget->setGeometry(QRect(10, 20, 331, 300));
        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 410, 351, 151));
        uncomplie_macro_listwidget = new QListWidget(groupBox_2);
        uncomplie_macro_listwidget->setObjectName(QString::fromUtf8("uncomplie_macro_listwidget"));
        uncomplie_macro_listwidget->setGeometry(QRect(10, 20, 331, 121));
        add_macro_button = new QPushButton(Dialog);
        add_macro_button->setObjectName(QString::fromUtf8("add_macro_button"));
        add_macro_button->setGeometry(QRect(365, 28, 85, 30));
        delete_macro_button = new QPushButton(Dialog);
        delete_macro_button->setObjectName(QString::fromUtf8("delete_macro_button"));
        delete_macro_button->setGeometry(QRect(365, 61, 85, 30));
        edit_macro_button = new QPushButton(Dialog);
        edit_macro_button->setObjectName(QString::fromUtf8("edit_macro_button"));
        edit_macro_button->setGeometry(QRect(365, 105, 85, 30));
        copy_macro_button = new QPushButton(Dialog);
        copy_macro_button->setObjectName(QString::fromUtf8("copy_macro_button"));
        copy_macro_button->setGeometry(QRect(365, 138, 85, 30));
        paste_macro_button = new QPushButton(Dialog);
        paste_macro_button->setObjectName(QString::fromUtf8("paste_macro_button"));
        paste_macro_button->setGeometry(QRect(365, 170, 85, 30));
        export_macro_button = new QPushButton(Dialog);
        export_macro_button->setObjectName(QString::fromUtf8("export_macro_button"));
        export_macro_button->setGeometry(QRect(365, 218, 85, 30));
        import_macro_button = new QPushButton(Dialog);
        import_macro_button->setObjectName(QString::fromUtf8("import_macro_button"));
        import_macro_button->setGeometry(QRect(365, 250, 85, 30));
        close = new QPushButton(Dialog);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(365, 530, 85, 30));

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
        add_macro_button->setText(QCoreApplication::translate("Dialog", "\346\226\260\345\242\236...", nullptr));
        delete_macro_button->setText(QCoreApplication::translate("Dialog", "\345\210\240\351\231\244", nullptr));
        edit_macro_button->setText(QCoreApplication::translate("Dialog", "\347\274\226\350\276\221", nullptr));
        copy_macro_button->setText(QCoreApplication::translate("Dialog", "\345\244\215\345\210\266", nullptr));
        paste_macro_button->setText(QCoreApplication::translate("Dialog", "\347\262\230\350\264\264", nullptr));
        export_macro_button->setText(QCoreApplication::translate("Dialog", "\345\257\274\345\207\272...", nullptr));
        import_macro_button->setText(QCoreApplication::translate("Dialog", "\345\257\274\345\205\245...", nullptr));
        close->setText(QCoreApplication::translate("Dialog", "\347\246\273\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
