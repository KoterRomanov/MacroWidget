#include "macro.h"

#include <QFile>
#include <QProcess>
#include <QTextStream>
#include <QDebug>

#include "macro_editor.h"

Macro::Macro(uint macro_index, QObject *parent)
    :QObject(parent),
     m_macro_index(macro_index),
     m_macro_index_new(macro_index),
     m_macro_name("macro_"+QString::number(m_macro_index)),
     m_macro_content(QString("macro_command main()\r\n\r\nend macro_command")),
     m_macro_complie_statu(Complie_Not_Done),
     m_enable(false),
     m_enable_with_cycle(false),
     m_cycle_interval(0),
     m_is_execute_with_starting(false),
     m_macro_editor(new MacroEditor)
{
    init_macro_editor();
}

Macro::~Macro()
{

}

QString Macro::macro_name()
{
    return m_macro_name;
}

uint Macro::macro_complie_statu()
{
    return m_macro_complie_statu;
}

uint Macro::macro_index()
{
    return m_macro_index_new;
}

void Macro::init_macro_editor()
{
    m_macro_editor->set_macro_index(m_macro_index);
    m_macro_editor->set_macro_name(m_macro_name);
    m_macro_editor->set_macro_content(m_macro_content);
    m_macro_editor->set_macro_enable(m_enable);
    m_macro_editor->set_macro_cycle_enable(m_enable_with_cycle);
    m_macro_editor->set_macro_start_execute_enable(m_is_execute_with_starting);

    connect( m_macro_editor, &MacroEditor::save_macro_signal, this, &Macro::slot_save_macro );
    connect(this, &Macro::complie_error_signal, m_macro_editor, &MacroEditor::slot_complie_error);
}

bool Macro::macro_complie(const QString &source)
{
    // 编译宏指令脚本
    QFile file("macro/temp.c");
    if ( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
        return false;

    //宏指令语言转换为 C 语言
    QString source_copy = source;
    source_copy.replace( "macro_command main()", "int main()\r\n{");
    source_copy.replace("end macro_command", "}");


    QTextStream out(&file);
    out << source_copy;

    file.close();

    //编译
    QProcess process;
    process.start("./tcc/tcc.exe -c ./macro/temp.c");
    process.waitForFinished();

    //删除临时文件
    file.remove();

    //标准输出
    //QByteArray out_put = process.readAllStandardOutput();

    //标准错误
    QByteArray out_error = process.readAllStandardError();
    if (!out_error.isEmpty())
    {
        m_macro_complie_statu = Complie_Unsuccessed;
        emit complie_error_signal(out_error);
        return false;
    }

    //宏指令编号
    m_macro_index_new = m_macro_editor->macro_index();

    //宏指令编译状态
    m_macro_complie_statu = Complie_Successed;

    emit complie_error_signal(QByteArray("0 error(s)"));
    return true;
}

void Macro::macro_data_update()
{
    m_macro_index = m_macro_editor->macro_index();
    m_macro_name = m_macro_editor->macro_name();
    m_macro_content = m_macro_editor->macro_content();
    m_enable = m_macro_editor->macro_enable();
    m_enable_with_cycle = m_macro_editor->macro_cycle_enable();
    m_is_execute_with_starting = m_macro_editor->macro_start_execute_enable();
}

bool Macro::macro_index_changed()
{
    return (m_macro_index == m_macro_index_new)? false:true;
}

Macro* Macro::copy(uint macro_index)
{
    Macro *macro = new Macro(macro_index);

    macro->m_macro_content = m_macro_content;
    macro->m_macro_complie_statu = m_macro_complie_statu;
    macro->m_enable = m_enable;
    macro->m_macro_execute_condition = m_macro_execute_condition;
    macro->m_enable_with_cycle = m_enable_with_cycle;
    macro->m_cycle_interval = m_cycle_interval;
    macro->m_is_execute_with_starting = m_is_execute_with_starting;

    return macro;
}

void Macro::macro_output()
{
    qDebug() << "******Start Macro Object******";
    qDebug() << "macro index: " << m_macro_index;
    qDebug() << "macro index new: " << m_macro_index_new;
    qDebug() << "macro name: " << m_macro_name;
    qDebug() << "macro content: " << m_macro_content;
    qDebug() << "macro complie statu: " << m_macro_complie_statu;
    qDebug() << "macro enable: " << m_enable;
    qDebug() << "macro enable with cycle: " << m_enable_with_cycle;
    qDebug() << "macro cycle interval: " << m_cycle_interval;
    qDebug() << "macro is execute with starting: " << m_is_execute_with_starting;
    qDebug() << "macro editor object: " << m_macro_editor;
    qDebug() << "******End Macro Object******";
}

void Macro::show()
{
    if (!m_macro_editor)
        return;

    init_macro_editor();
    m_macro_editor->show();
}

QString Macro::execute_macro()
{
    //TODO 外部调用这个方法执行宏指令脚本
    return QString();
}

void Macro::slot_save_macro(QString source)
{
    macro_complie(source);
    emit save_macro_signal(this);
}
