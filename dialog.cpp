#include "dialog.h"
#include "ui_dialog.h"

#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexercpp.h>
#include <Qsci/qsciapis.h>
#include <QProcess>
#include <QTextStream>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    textEdit = new QsciScintilla;
    textEdit->hide();


    //对该页边启用行号
    textEdit->setMarginType(0,QsciScintilla::NumberMargin);//设置编号为0的页边显示行号。
    textEdit->setMarginLineNumbers( 0, true );
    textEdit->setMarginWidth(0,35);//设置页边宽度

    //增加关键字定制颜色 (C++语言)
    QsciLexerCPP * text_lexer = new QsciLexerCPP;
    text_lexer->setColor(QColor(Qt::green),QsciLexerCPP::CommentLine);    //设置自带的注释行为绿色
    textEdit->setLexer(text_lexer);

    //设置括号自动补全
    QsciAPIs *apis = new QsciAPIs(text_lexer);
    apis->add(QString("int"));
    apis->add(QString("return"));
    apis->add(QString("{}"));
    apis->add(QString("#include"));
    apis->prepare();
    textEdit->setAutoCompletionSource(QsciScintilla::AcsAll);   //自动补全所以地方出现的
    textEdit->setAutoCompletionCaseSensitivity(true);   //设置自动补全大小写敏感
    textEdit->setAutoCompletionThreshold(1);    //输入一个字符就会出现自动补全的提示
}

Dialog::~Dialog()
{
    delete ui;

    delete textEdit;
    textEdit = nullptr;
}

void Dialog::on_pushButton_clicked()
{
    textEdit->show();
}

void Dialog::slot_compile()
{
    QString cpp_source = textEdit->text();

    QFile file("temp.c");
    if ( !file.open(QIODevice::WriteOnly|QIODevice::Text))
        return;

    QTextStream out(&file);
    out << cpp_source;
    file.close();

    QProcess::startDetached("./tcc/tcc.exe temp.c -o test.exe");
}

void Dialog::on_pushButton_2_clicked()
{
    slot_compile();
}
