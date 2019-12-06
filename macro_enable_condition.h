#ifndef MACRO_ENABLE_CONDITION_H
#define MACRO_ENABLE_CONDITION_H

#include <QObject>

/*
 * 宏指令执行条件类
 */
class MacroExecuteCondition : public QObject
{
    Q_OBJECT
public:
    explicit MacroExecuteCondition(QObject *parent = nullptr);
    MacroExecuteCondition(const MacroExecuteCondition &obj);

    MacroExecuteCondition& operator=(const MacroExecuteCondition &obj);

    enum Condition
    {
        Enable_with_ON = 0,
        Enable_with_OFF
    };

private:

    /* 禁止执行条件 */
    Condition m_inexecute_condition;

    /* 设备名称 */
    QString m_machine_name;

    /* 变量地址 */
    QString m_variable_type;

};

#endif // MACRO_ENABLE_CONDITION_H
