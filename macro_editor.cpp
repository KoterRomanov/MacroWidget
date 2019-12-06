#include "macro_editor.h"
#include "ui_macroeditor.h"

#include <QHBoxLayout>
#include <QTextStream>
#include <QProcess>
#include <QDebug>

#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexercpp.h>
#include <Qsci/qsciapis.h>
#include "macro.h"

MacroEditor::MacroEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MacroEditor),
    macro_editor(nullptr)
{
    ui->setupUi(this);

    init_macro_editor();

}

MacroEditor::~MacroEditor()
{
    delete ui;
}

void MacroEditor::set_macro_index(uint macro_index)
{
    ui->macro_index_edit->setText(QString::number(macro_index));
}

uint MacroEditor::macro_index()
{
   return ui->macro_index_edit->text().toUInt();
}

void MacroEditor::set_macro_name(QString macro_name)
{
    ui->macro_name_edit->setText(macro_name);
}

QString MacroEditor::macro_name()
{
    return ui->macro_name_edit->text();
}

void MacroEditor::set_macro_content(QString macro_content)
{
    macro_editor->setText(macro_content);
}

QString MacroEditor::macro_content()
{
    return macro_editor->text();
}

void MacroEditor::set_macro_enable(bool enable)
{
    ui->macro_enable_checkbox->setChecked(enable);
}

bool MacroEditor::macro_enable()
{
    return ui->macro_enable_checkbox->isChecked();
}

void MacroEditor::set_macro_cycle_enable(bool enable)
{
   ui->macro_enable_cycle_checkbox->setChecked(enable);
}

bool MacroEditor::macro_cycle_enable()
{
    return ui->macro_enable_cycle_checkbox->isChecked();
}

void MacroEditor::set_macro_start_execute_enable(bool enable)
{
    ui->macro_execute_starting_checkbox->setChecked(enable);
}

bool MacroEditor::macro_start_execute_enable()
{
    return ui->macro_execute_starting_checkbox->isChecked();
}

void MacroEditor::slot_complie_error(QByteArray error)
{
    ui->macro_complie_result_edit->clear();
    ui->macro_complie_result_edit->setText(error);
}

void MacroEditor::init_macro_editor()
{
    QHBoxLayout *layout = new QHBoxLayout(ui->macro_content_frame);

    //宏指令编辑器
    macro_editor = new QsciScintilla;

    //对该页边启用行号
    macro_editor->setMarginType(0,QsciScintilla::NumberMargin);//设置编号为0的页边显示行号。
    macro_editor->setMarginLineNumbers( 0, true );
    macro_editor->setMarginWidth(0,35);//设置页边宽度

    //增加关键字定制颜色 (C++语言)
    QsciLexerCPP * text_lexer = new QsciLexerCPP;
    text_lexer->setColor(QColor(Qt::green),QsciLexerCPP::CommentLine);    //设置自带的注释行为绿色
    macro_editor->setLexer(text_lexer);

    //设置括号自动补全
    QsciAPIs *apis = new QsciAPIs(text_lexer);
    apis->add(QString("int"));
    apis->add(QString("return"));
    apis->add(QString("main"));
    apis->add(QString("#include"));
    apis->prepare();
    macro_editor->setAutoCompletionSource(QsciScintilla::AcsAll);   //自动补全所以地方出现的
    macro_editor->setAutoCompletionCaseSensitivity(true);   //设置自动补全大小写敏感
    macro_editor->setAutoCompletionThreshold(1);    //输入一个字符就会出现自动补全的提示

    macro_editor->setAutoIndent(true);//换行自动缩进

    layout->addWidget( macro_editor );
}

void MacroEditor::on_macro_save_complie_button_clicked()
{
    if (!macro_editor)
        return;

    QString source = macro_editor->text();

    emit save_macro_signal(source);
}

void MacroEditor::on_macro_edit_close_button_clicked()
{
    close();
}
