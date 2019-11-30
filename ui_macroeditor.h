/********************************************************************************
** Form generated from reading UI file 'macroeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MACROEDITOR_H
#define UI_MACROEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MacroEditor
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *macro_index_edit;
    QLabel *label_2;
    QLineEdit *macro_name_edit;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *macro_enable_checkbox;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *macro_enable_cycle_checkbox;
    QLabel *macro_cycle_prefix_lab;
    QLineEdit *macro_cycle_interval_edit;
    QLabel *macro_cycle_suffix_lab;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *macro_execute_starting_checkbox;
    QFrame *macro_content_frame;
    QLabel *label_3;
    QTextEdit *macro_complie_result_edit;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *macro_functions_button;
    QSpacerItem *horizontalSpacer;
    QPushButton *macro_save_complie_button;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *macro_edit_close_button;
    QPushButton *macro_introdution_button;

    void setupUi(QWidget *MacroEditor)
    {
        if (MacroEditor->objectName().isEmpty())
            MacroEditor->setObjectName(QString::fromUtf8("MacroEditor"));
        MacroEditor->resize(946, 690);
        verticalLayout = new QVBoxLayout(MacroEditor);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        groupBox = new QGroupBox(MacroEditor);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        macro_index_edit = new QLineEdit(groupBox);
        macro_index_edit->setObjectName(QString::fromUtf8("macro_index_edit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(macro_index_edit->sizePolicy().hasHeightForWidth());
        macro_index_edit->setSizePolicy(sizePolicy1);
        macro_index_edit->setMinimumSize(QSize(70, 0));
        macro_index_edit->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(macro_index_edit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        macro_name_edit = new QLineEdit(groupBox);
        macro_name_edit->setObjectName(QString::fromUtf8("macro_name_edit"));

        horizontalLayout->addWidget(macro_name_edit);


        horizontalLayout_6->addWidget(groupBox);

        groupBox_3 = new QGroupBox(MacroEditor);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setMinimumSize(QSize(340, 35));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        macro_enable_checkbox = new QCheckBox(groupBox_3);
        macro_enable_checkbox->setObjectName(QString::fromUtf8("macro_enable_checkbox"));

        horizontalLayout_2->addWidget(macro_enable_checkbox);


        horizontalLayout_6->addWidget(groupBox_3);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        groupBox_2 = new QGroupBox(MacroEditor);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        macro_enable_cycle_checkbox = new QCheckBox(groupBox_2);
        macro_enable_cycle_checkbox->setObjectName(QString::fromUtf8("macro_enable_cycle_checkbox"));

        horizontalLayout_4->addWidget(macro_enable_cycle_checkbox);

        macro_cycle_prefix_lab = new QLabel(groupBox_2);
        macro_cycle_prefix_lab->setObjectName(QString::fromUtf8("macro_cycle_prefix_lab"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(macro_cycle_prefix_lab->sizePolicy().hasHeightForWidth());
        macro_cycle_prefix_lab->setSizePolicy(sizePolicy2);
        macro_cycle_prefix_lab->setMinimumSize(QSize(130, 0));

        horizontalLayout_4->addWidget(macro_cycle_prefix_lab);

        macro_cycle_interval_edit = new QLineEdit(groupBox_2);
        macro_cycle_interval_edit->setObjectName(QString::fromUtf8("macro_cycle_interval_edit"));
        sizePolicy1.setHeightForWidth(macro_cycle_interval_edit->sizePolicy().hasHeightForWidth());
        macro_cycle_interval_edit->setSizePolicy(sizePolicy1);
        macro_cycle_interval_edit->setMinimumSize(QSize(60, 20));
        macro_cycle_interval_edit->setMaximumSize(QSize(60, 20));

        horizontalLayout_4->addWidget(macro_cycle_interval_edit);

        macro_cycle_suffix_lab = new QLabel(groupBox_2);
        macro_cycle_suffix_lab->setObjectName(QString::fromUtf8("macro_cycle_suffix_lab"));
        sizePolicy2.setHeightForWidth(macro_cycle_suffix_lab->sizePolicy().hasHeightForWidth());
        macro_cycle_suffix_lab->setSizePolicy(sizePolicy2);
        macro_cycle_suffix_lab->setMinimumSize(QSize(42, 0));
        macro_cycle_suffix_lab->setMaximumSize(QSize(42, 16777215));

        horizontalLayout_4->addWidget(macro_cycle_suffix_lab);


        horizontalLayout_7->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(MacroEditor);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        sizePolicy1.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy1);
        groupBox_4->setMinimumSize(QSize(340, 35));
        horizontalLayout_3 = new QHBoxLayout(groupBox_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        macro_execute_starting_checkbox = new QCheckBox(groupBox_4);
        macro_execute_starting_checkbox->setObjectName(QString::fromUtf8("macro_execute_starting_checkbox"));

        horizontalLayout_3->addWidget(macro_execute_starting_checkbox);


        horizontalLayout_7->addWidget(groupBox_4);


        verticalLayout->addLayout(horizontalLayout_7);

        macro_content_frame = new QFrame(MacroEditor);
        macro_content_frame->setObjectName(QString::fromUtf8("macro_content_frame"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(macro_content_frame->sizePolicy().hasHeightForWidth());
        macro_content_frame->setSizePolicy(sizePolicy3);
        macro_content_frame->setFrameShape(QFrame::StyledPanel);
        macro_content_frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(macro_content_frame);

        label_3 = new QLabel(MacroEditor);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        macro_complie_result_edit = new QTextEdit(MacroEditor);
        macro_complie_result_edit->setObjectName(QString::fromUtf8("macro_complie_result_edit"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(macro_complie_result_edit->sizePolicy().hasHeightForWidth());
        macro_complie_result_edit->setSizePolicy(sizePolicy4);
        macro_complie_result_edit->setMinimumSize(QSize(0, 60));
        macro_complie_result_edit->setMaximumSize(QSize(16777215, 60));

        verticalLayout->addWidget(macro_complie_result_edit);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        macro_functions_button = new QPushButton(MacroEditor);
        macro_functions_button->setObjectName(QString::fromUtf8("macro_functions_button"));
        sizePolicy1.setHeightForWidth(macro_functions_button->sizePolicy().hasHeightForWidth());
        macro_functions_button->setSizePolicy(sizePolicy1);
        macro_functions_button->setMinimumSize(QSize(113, 0));

        horizontalLayout_5->addWidget(macro_functions_button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        macro_save_complie_button = new QPushButton(MacroEditor);
        macro_save_complie_button->setObjectName(QString::fromUtf8("macro_save_complie_button"));
        sizePolicy1.setHeightForWidth(macro_save_complie_button->sizePolicy().hasHeightForWidth());
        macro_save_complie_button->setSizePolicy(sizePolicy1);
        macro_save_complie_button->setMinimumSize(QSize(180, 0));

        horizontalLayout_5->addWidget(macro_save_complie_button);

        pushButton_3 = new QPushButton(MacroEditor);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMinimumSize(QSize(150, 0));

        horizontalLayout_5->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(MacroEditor);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setMinimumSize(QSize(150, 0));

        horizontalLayout_5->addWidget(pushButton_4);

        macro_edit_close_button = new QPushButton(MacroEditor);
        macro_edit_close_button->setObjectName(QString::fromUtf8("macro_edit_close_button"));
        sizePolicy1.setHeightForWidth(macro_edit_close_button->sizePolicy().hasHeightForWidth());
        macro_edit_close_button->setSizePolicy(sizePolicy1);
        macro_edit_close_button->setMinimumSize(QSize(80, 0));

        horizontalLayout_5->addWidget(macro_edit_close_button);

        macro_introdution_button = new QPushButton(MacroEditor);
        macro_introdution_button->setObjectName(QString::fromUtf8("macro_introdution_button"));
        sizePolicy1.setHeightForWidth(macro_introdution_button->sizePolicy().hasHeightForWidth());
        macro_introdution_button->setSizePolicy(sizePolicy1);
        macro_introdution_button->setMinimumSize(QSize(80, 0));

        horizontalLayout_5->addWidget(macro_introdution_button);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(MacroEditor);

        QMetaObject::connectSlotsByName(MacroEditor);
    } // setupUi

    void retranslateUi(QWidget *MacroEditor)
    {
        MacroEditor->setWindowTitle(QCoreApplication::translate("MacroEditor", "\347\274\226\350\276\221\345\231\250", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MacroEditor", "\347\274\226\345\217\267:", nullptr));
        label_2->setText(QCoreApplication::translate("MacroEditor", "\345\256\217\346\214\207\344\273\244\345\220\215\347\247\260:", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MacroEditor", "\345\256\211\345\205\250", nullptr));
        macro_enable_checkbox->setText(QCoreApplication::translate("MacroEditor", "\345\220\257\347\224\250\346\211\247\350\241\214\346\235\241\344\273\266", nullptr));
        groupBox_2->setTitle(QString());
        macro_enable_cycle_checkbox->setText(QCoreApplication::translate("MacroEditor", "\345\221\250\346\234\237\346\211\247\350\241\214", nullptr));
        macro_cycle_prefix_lab->setText(QCoreApplication::translate("MacroEditor", "\346\227\266\351\227\264\351\227\264\351\232\224\357\274\2100~864000\357\274\211:", nullptr));
        macro_cycle_suffix_lab->setText(QCoreApplication::translate("MacroEditor", "x 100ms", nullptr));
        groupBox_4->setTitle(QString());
        macro_execute_starting_checkbox->setText(QCoreApplication::translate("MacroEditor", "\345\275\223 HMI \345\220\257\345\212\250\346\227\266\345\215\263\346\211\247\350\241\214\344\270\200\346\254\241", nullptr));
        label_3->setText(QCoreApplication::translate("MacroEditor", "* \347\202\271\345\207\273\351\274\240\346\240\207\345\217\263\351\224\256\345\217\257\346\230\276\347\244\272\347\274\226\350\276\221\350\217\234\345\215\225.", nullptr));
        macro_functions_button->setText(QCoreApplication::translate("MacroEditor", "\345\207\275\346\225\260...", nullptr));
        macro_save_complie_button->setText(QCoreApplication::translate("MacroEditor", "\344\277\235\345\255\230 & \347\274\226\350\257\221", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MacroEditor", "\347\246\273\347\272\277\346\250\241\346\213\237", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MacroEditor", "\345\234\250\347\272\277\346\250\241\346\213\237", nullptr));
        macro_edit_close_button->setText(QCoreApplication::translate("MacroEditor", "\345\205\263\351\227\255", nullptr));
        macro_introdution_button->setText(QCoreApplication::translate("MacroEditor", "\350\257\264\346\230\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MacroEditor: public Ui_MacroEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MACROEDITOR_H
