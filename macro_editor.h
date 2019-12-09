#ifndef MACROEDITOR_H
#define MACROEDITOR_H

#include <QDialog>
#include <Qsci/qscilexercpp.h>

#include "macro_enable_condition.h"

class Macro;
class QsciScintilla;
namespace Ui {
class MacroEditor;
}

class MacroEditor : public QWidget
{
    Q_OBJECT

public:
    explicit MacroEditor(QWidget *parent = nullptr);
    ~MacroEditor();

    /* 宏指令编号 */
    void set_macro_index(uint);
    uint macro_index();

    /* 宏指令名称 */
    void set_macro_name(QString);
    QString macro_name();

    /* 宏指令内容 */
    void set_macro_content(QString);
    QString macro_content();

    /* 宏指令是否启用执行条件 */
    void set_macro_enable(bool);
    bool macro_enable();

    /* 宏指令是否周期执行 */
    void set_macro_cycle_enable(bool);
    bool macro_cycle_enable();

    /* 宏指令是否启动执行 */
    void set_macro_start_execute_enable(bool);
    bool macro_start_execute_enable();

public Q_SLOTS:

    /* 编译结果 */
    void slot_complie_error(QByteArray);

Q_SIGNALS:

    /* 宏指令保存编译 */
    void save_macro_signal(QString);

private slots:

    /* 宏指令 保存 & 编译 */
    void on_macro_save_complie_button_clicked();

    /* 宏指令 关闭 */
    void on_macro_edit_close_button_clicked();

private:

    /* 初始化宏指令编辑器 */
    void init_macro_editor();

private:
    Ui::MacroEditor *ui;

    /* 编辑器 */
    QsciScintilla *macro_editor;

};

class QscilexerCppKeyAttach : public QsciLexerCPP
{
    Q_OBJECT

public:
    virtual const char *keywords(int set) const override;

};

#endif // MACROEDITOR_H
