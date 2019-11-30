#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class Macro;
class MacroManage;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:

    /* 初始化宏指令管理器 */
    void init_macro_manage();

    /* 更新宏指令列表 */
    void macro_list_update();

private Q_SLOTS:

    /* 新增 */
    void on_add_macro_button_clicked();

    /* 删除 */
    void on_delete_macro_button_clicked();

    /* 编辑 */
    void on_edit_macro_button_clicked();

    /* 复制 */
    void on_copy_macro_button_clicked();

    /* 粘贴 */
    void on_paste_macro_button_clicked();

    /* 导出 */
    void on_export_macro_button_clicked();

    /* 导入 */
    void on_import_macro_button_clicked();

    /* 离开 */
    void on_close_clicked();

    /* 保存宏指令 */
    void slot_save_macro(Macro *macro);

private:
    Ui::Dialog *ui;

    /* 宏指令管理器 */
    MacroManage *m_macro_manage;
};

#endif // DIALOG_H
