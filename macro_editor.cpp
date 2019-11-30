#include "macro_editor.h"
#include "ui_macroeditor.h"

#include <QHBoxLayout>
#include <QTextStream>
#include <QProcess>

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
    apis->add(QString("{}"));
    apis->add(QString("#include"));
    apis->prepare();
    macro_editor->setAutoCompletionSource(QsciScintilla::AcsAll);   //自动补全所以地方出现的
    macro_editor->setAutoCompletionCaseSensitivity(true);   //设置自动补全大小写敏感
    macro_editor->setAutoCompletionThreshold(1);    //输入一个字符就会出现自动补全的提示

    layout->addWidget( macro_editor );
}

void MacroEditor::on_macro_save_complie_button_clicked()
{
    if (!macro_editor)
        return;

    QString cpp_source = macro_editor->text();

    QFile file("temp.c");
    if ( !file.open(QIODevice::WriteOnly|QIODevice::Text))
        return;

    QTextStream out(&file);
    out << cpp_source;
    file.close();

    QProcess::startDetached("./tcc/tcc.exe temp.c -o test.exe");

    emit save_macro_signal();
}

void MacroEditor::on_macro_edit_close_button_clicked()
{
    close();
}
