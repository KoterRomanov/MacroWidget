#ifndef MACROEDITOR_H
#define MACROEDITOR_H

#include <QDialog>

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

Q_SIGNALS:
    void save_macro_signal();

private slots:
    void on_macro_save_complie_button_clicked();

    void on_macro_edit_close_button_clicked();

private:

    /* 初始化宏指令编辑器 */
    void init_macro_editor();

private:
    Ui::MacroEditor *ui;

    QsciScintilla *macro_editor;

};

#endif // MACROEDITOR_H
