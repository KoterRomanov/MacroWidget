#include "macro_enable_condition.h"

MacroExecuteCondition::MacroExecuteCondition(QObject *parent)
    : QObject(parent),
      m_inexecute_condition(Enable_with_ON),
      m_machine_name("Loacl HMI"),
      m_variable_type("0")
{

}

MacroExecuteCondition::MacroExecuteCondition(const MacroExecuteCondition &obj)
{
    Q_UNUSED(obj);
}

MacroExecuteCondition& MacroExecuteCondition::operator=(const MacroExecuteCondition &obj)
{
    if ( &obj == this )
        return *this;

    m_inexecute_condition = obj.m_inexecute_condition;
    m_machine_name = obj.m_machine_name;
    m_variable_type = obj.m_variable_type;

    return *this;
}
