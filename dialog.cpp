#include "dialog.h"
#include "ui_dialog.h"


#include <QProcess>
#include <QTextStream>
#include <QListWidget>

#include "macro.h"
#include "macro_manage.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_macro_manage(nullptr)
{
    ui->setupUi(this);

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

void Dialog::macro_list_update()
{

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
    QList<QListWidgetItem*> select_items = ui->complie_macro_listwidget->selectedItems();
    if( select_items.count() )
    {
        QListWidgetItem *item = select_items.at(0);
        uint delete_macro_index = item->data(Qt::EditRole).toUInt();
        m_macro_manage->delete_macro(delete_macro_index);

        ui->complie_macro_listwidget->takeItem(ui->complie_macro_listwidget->row(item));
    }
}

void Dialog::on_edit_macro_button_clicked()
{

}

void Dialog::on_copy_macro_button_clicked()
{

}

void Dialog::on_paste_macro_button_clicked()
{

}

void Dialog::on_export_macro_button_clicked()
{

}

void Dialog::on_import_macro_button_clicked()
{

}

void Dialog::on_close_clicked()
{

}

void Dialog::slot_save_macro(Macro *macro)
{
    m_macro_manage->add_macro(macro);

    QListWidgetItem *item = new QListWidgetItem;
    item->setText(macro->macro_name());
    item->setData(Qt::EditRole, QVariant(macro->macro_index()));

    ui->complie_macro_listwidget->addItem(item);
    macro_list_update();
}
