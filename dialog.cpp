#include "dialog.h"
#include "ui_dialog.h"


#include <QDebug>
#include <QProcess>
#include <QTextStream>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMessageBox>

#include "macro.h"
#include "macro_manage.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_macro_manage(nullptr),
    m_selectd_item(nullptr),
    m_macro_copy_index(-1)
{
    ui->setupUi(this);

    init_list_focus();
    init_macro_manage();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::init_macro_manage()
{
    m_macro_manage = new MacroManage;
}

void Dialog::init_list_focus()
{
    connect( ui->complie_macro_listwidget, &QListWidget::itemPressed, this, &Dialog::slot_list_focus_changed );
    connect( ui->uncomplie_macro_listwidget, &QListWidget::itemPressed, this, &Dialog::slot_list_focus_changed );
}

void Dialog::macro_list_update()
{

}

void Dialog::macro_output()
{
    uint macro_index = 0;
    while( macro_index < 256 )
    {
        Macro *macro = m_macro_manage->macro(++macro_index);
        if (!macro)
            break;

        macro->macro_output();
    }
}

void Dialog::on_add_macro_button_clicked()
{
    //显示宏指令编辑器
    Macro *macro = new Macro(m_macro_manage->get_macro_index());
    connect( macro, &Macro::save_macro_signal, this, &Dialog::slot_save_macro );
    macro->show();
}

void Dialog::on_delete_macro_button_clicked()
{
    if ( !m_selectd_item )
        return;

    uint macro_index = m_selectd_item->data(Qt::UserRole).toUInt();
    m_macro_manage->delete_macro( macro_index );

    if ( ui->complie_macro_listwidget->row(m_selectd_item) >= 0 )
    {
        ui->complie_macro_listwidget->takeItem( ui->complie_macro_listwidget->row(m_selectd_item) );
    }
    else if ( ui->uncomplie_macro_listwidget->row(m_selectd_item) >= 0 )
    {
        ui->uncomplie_macro_listwidget->takeItem( ui->uncomplie_macro_listwidget->row(m_selectd_item) );
    }

    qDebug() << "----------------------------------";
    qDebug() << "delete macro index: " << macro_index;
    qDebug() << "----------------------------------";
}

void Dialog::on_edit_macro_button_clicked()
{
    if ( !m_selectd_item )
        return;

    uint macro_index =  m_selectd_item->data(Qt::UserRole).toUInt();
    m_macro_manage->macro(macro_index)->show();
    m_macro_manage->macro(macro_index)->macro_output();
}

void Dialog::on_copy_macro_button_clicked()
{
    if ( !m_selectd_item )
        return;

    m_macro_copy_index = int(m_selectd_item->data(Qt::UserRole).toUInt());
}

void Dialog::on_paste_macro_button_clicked()
{
    if ( m_macro_copy_index < 0 )
        return;

    Macro *macro = m_macro_manage->macro(uint(m_macro_copy_index));
    Macro *paste_macro = macro->copy(m_macro_manage->get_macro_index());
    connect( paste_macro, &Macro::save_macro_signal, this, &Dialog::slot_save_macro );

    paste_macro->macro_output();


    //添加宏指令对象
    m_macro_manage->add_macro(paste_macro);
    QListWidgetItem *item = new QListWidgetItem;
    item->setText(paste_macro->macro_name());
    item->setData(Qt::UserRole, QVariant(paste_macro->macro_index()));

    if ( Macro::Complie_Successed == paste_macro->macro_complie_statu() )
    {
        ui->complie_macro_listwidget->addItem(item);
        m_complie_successed_map.insert( paste_macro->macro_index(), item);
    }
    else if ( Macro::Complie_Unsuccessed == paste_macro->macro_complie_statu() )
    {
        ui->uncomplie_macro_listwidget->addItem(item);
        m_complie_unsuccessed_map.insert( paste_macro->macro_index(), item );
    }

    macro_output();
}

void Dialog::on_export_macro_button_clicked()
{

}

void Dialog::on_import_macro_button_clicked()
{

}

void Dialog::on_close_clicked()
{
    qApp->exit(0);
}

void Dialog::slot_save_macro(Macro *macro)
{
    //检查宏指令对象编号是否重复
    if ( macro->macro_index_changed() && m_macro_manage->contain(macro) )
    {
        QMessageBox::information(nullptr, tr("注意"), tr("[MACRO ID: ") + QString::number(macro->macro_index()) + tr("]已经定义") );
        return;
    }

    uint old_macro_index = macro->macro_index();
    //更新宏指令对象属性
    macro->macro_data_update();

    //添加新的宏指令对象
    if( !m_macro_manage->contain(macro) )
    {
        m_macro_manage->add_macro(macro);
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(macro->macro_name());
        item->setData(Qt::UserRole, QVariant(macro->macro_index()));

        if ( Macro::Complie_Successed == macro->macro_complie_statu() )
        {
            ui->complie_macro_listwidget->addItem(item);
            m_complie_successed_map.insert( macro->macro_index(), item);

        }
        else if ( Macro::Complie_Unsuccessed == macro->macro_complie_statu() )
        {
            ui->uncomplie_macro_listwidget->addItem(item);
            m_complie_unsuccessed_map.insert( macro->macro_index(), item );
        }

    }
    else
    {
        if ( Macro::Complie_Successed == macro->macro_complie_statu() )
        {
            //检测编译失败列表是否存在该宏指令对象
            QListWidgetItem *item = m_complie_unsuccessed_map.value(old_macro_index);
            if (item)
            {
                m_complie_unsuccessed_map.remove(old_macro_index);
                ui->uncomplie_macro_listwidget->takeItem(ui->uncomplie_macro_listwidget->row(item));

                QListWidgetItem *successed_item = new QListWidgetItem;
                successed_item->setText(macro->macro_name());
                successed_item->setData(Qt::UserRole, QVariant(macro->macro_index()));
                ui->complie_macro_listwidget->addItem(successed_item);

                //添加至已编译成功列表
                m_complie_successed_map.insert( macro->macro_index(), successed_item );
            }
        }
        else if ( Macro::Complie_Unsuccessed == macro->macro_complie_statu() )
        {
            //检测编译成功列表是否存在该宏指令对象
            QListWidgetItem *item = m_complie_successed_map.value(old_macro_index);
            if (item)
            {
                m_complie_successed_map.remove(old_macro_index);
                ui->complie_macro_listwidget->takeItem(ui->complie_macro_listwidget->row(item));

                QListWidgetItem *unsuccessed_item = new QListWidgetItem;
                unsuccessed_item->setText(macro->macro_name());
                unsuccessed_item->setData(Qt::UserRole, QVariant(macro->macro_index()));

                ui->uncomplie_macro_listwidget->addItem(unsuccessed_item);

                //添加至未编译成功列表
                m_complie_unsuccessed_map.insert(macro->macro_index(), unsuccessed_item);
            }

        }//end of else if

    }//end of else

    macro_output();
}

void Dialog::slot_list_focus_changed(QListWidgetItem *item)
{
    m_selectd_item = item;

    QListWidget *list_widget = qobject_cast<QListWidget*>(sender());
    if ( list_widget == ui->complie_macro_listwidget )
    {
        ui->uncomplie_macro_listwidget->clearSelection();
    }
    else if ( list_widget == ui->uncomplie_macro_listwidget )
    {
        ui->complie_macro_listwidget->clearSelection();
    }
}
