#include "macro.h"

#include "macro_editor.h"
#include "macro_enable_condition.h"

Macro::Macro(uint macro_index, QObject *parent)
    :QObject(parent),
     m_macro_index(macro_index),
     m_macro_editor(nullptr)
{
    init_macro_name();
    init_macro_editor();
}

Macro::~Macro()
{

}

QString Macro::macro_name()
{
    return m_macro_name;
}

uint Macro::macro_index()
{
    return m_macro_index;
}

void Macro::init_macro_name()
{
    m_macro_name = "macro_1";
}

void Macro::init_macro_editor()
{
    m_macro_editor = new MacroEditor;
    connect( m_macro_editor, &MacroEditor::save_macro_signal, this, &Macro::slot_save_macro );
}

void Macro::show()
{
    if (!m_macro_editor)
        return;

    m_macro_editor->show();
}

void Macro::slot_save_macro()
{
    emit save_macro_signal(this);
}
