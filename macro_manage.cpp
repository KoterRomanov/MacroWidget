#include "macro_manage.h"
#include "macro.h"

MacroManage::MacroManage(QObject *parent)
    : QObject(parent)
{

}

MacroManage::~MacroManage()
{
   QList<uint> macro_index_list;
   foreach(uint macro_index, macro_index_list)
   {
      Macro *macro = m_macro_map[macro_index];
      delete macro;
      macro = nullptr;
   }
}

uint MacroManage::get_macro_index()
{
    uint macro_index = 0;
    while( m_macro_map.contains(++macro_index) );

    return macro_index;
}

void MacroManage::add_macro(Macro *macro)
{
    m_macro_map.insert( macro->macro_index(), macro );
}

void MacroManage::delete_macro(uint macro_index)
{
    m_macro_map.remove( macro_index );
}

bool MacroManage::contain(Macro *macro)
{
    return m_macro_map.contains(macro->macro_index());
}

void MacroManage::modify_macro_index(uint macro_index_src, uint macro_index_dest)
{

}

void MacroManage::modify_macro_name(uint macro_index, QString macro_name)
{

}

Macro* MacroManage::macro(uint macro_index)
{
    return m_macro_map.value(macro_index);
}


