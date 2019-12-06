#ifndef MACRO_H
#define MACRO_H

#include <QObject>

#include "macro_enable_condition.h"

/*
 * 宏指令对象类
 */
class MacroEditor;
class MacroExecuteCondition;
class Macro : public QObject
{
    Q_OBJECT

public:
    enum ComplieStatu
    {
        /* 未编译 */
        Complie_Not_Done,

        /* 编译成功 */
        Complie_Successed,

        /* 编译未完成 */
        Complie_Unsuccessed
    };

public:
    explicit Macro(uint macro_index, QObject *parent = nullptr);
    ~Macro();

    /* 宏指令编号 */
    uint macro_index();

    /* 宏指令名称 */
    QString macro_name();

    uint macro_complie_statu();

    /* 显示宏指令编辑器 */
    void show();

    /* 执行宏指令 */
    QString execute_macro();

    /* 更新宏指令属性值 */
    void macro_data_update();

    /* 宏指令编号是否变化 */
    bool macro_index_changed();

    /* 复制宏指令对象 */
    Macro* copy(uint macro_index);

    void macro_output();

Q_SIGNALS:

    /* 保存宏指令信号 */
    void save_macro_signal(Macro*);

    /* 删除宏指令信号 */
    void delete_macro_signal(Macro*);

    /* 编译错误信号 */
    void complie_error_signal(QByteArray);

private Q_SLOTS:

    /* 保存宏指令 */
    void slot_save_macro(QString);

private:

    /* 初始化宏指令名称 */
    void init_macro_name();

    /* 初始化宏指令编辑器 */
    void init_macro_editor();

    /* 编译宏指令 */
    bool macro_complie(const QString &source);

private:

    /* 宏指令编号 */
    uint m_macro_index;

    /* 新宏指令编号 */
    uint m_macro_index_new;

    /* 宏指令名称 */
    QString m_macro_name;

    /* 宏指令内容 */
    QString m_macro_content;

    /* 宏指令编译状态 */
    ComplieStatu m_macro_complie_statu;

    /* 宏指令启用 */
    bool m_enable;

    /* 宏指令启用执行条件 */
    MacroExecuteCondition m_macro_execute_condition;

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
