#ifndef MACRO_H
#define MACRO_H

#include <QObject>

/*
 * 宏指令对象类
 */
class MacroEditor;
class MacroExecuteCondition;
class Macro : public QObject
{
    Q_OBJECT

public:
    explicit Macro(uint macro_index, QObject *parent = nullptr);
    ~Macro();

    /* 宏指令名称 */
    QString macro_name();

    /* 宏指令编号 */
    uint macro_index();

    void show();

    enum ComplieStatu
    {
        /* 编译成功 */
        Complie_Successed,

        /* 编译未完成 */
        Complie_Unsuccessed
    };

Q_SIGNALS:

    /* 保存宏指令信号 */
    void save_macro_signal(Macro*);

    /* 删除宏指令信号 */
    void delete_macro_signal(Macro*);

private Q_SLOTS:

    /* 保存宏指令 */
    void slot_save_macro();

private:

    /* 初始化宏指令名称 */
    void init_macro_name();

    /* 初始化宏指令编辑器 */
    void init_macro_editor();

private:

    /* 宏指令编号 */
    uint m_macro_index;

    /* 宏指令名称 */
    QString m_macro_name;

    /* 宏指令内容 */
    QString m_macro_content;

    /* 宏指令编译状态 */
    ComplieStatu m_macro_complie_statu;

    /* 宏指令启用 */
    bool m_enable;

    /* 宏指令启用执行条件 */
    MacroExecuteCondition *m_macro_execute_condition;

    /* 宏指令是否周期执行 */
    bool m_enable_with_cycle;

    /* 宏指令执行周期 */
    uint m_cycle_interval;

    /* 宏指令是否当 HMI 启动时即执行一次 */
    bool m_is_execute_with_starting;

    /* 宏指令编辑器 */
    MacroEditor *m_macro_editor;
};

#endif // MACRO_H
