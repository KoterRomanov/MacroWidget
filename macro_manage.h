#ifndef MACRO_MANAGE_H
#define MACRO_MANAGE_H

#include <QObject>
#include <QMap>

//宏指令对象管理类
class Macro;
class MacroManage : public QObject
{
    Q_OBJECT
public:
    explicit MacroManage(QObject *parent = nullptr);
    ~MacroManage();

    /* 新的宏指令编号 */
    uint get_macro_index();

    /* 新增 */
    void add_macro(Macro* macro);

    /* 删除 */
    void delete_macro(uint macro_index);

    /* 是否存在 */
    bool contain(Macro*);

    /* 修改编号 */
    void modify_macro_index(uint macro_index_src, uint macro_index_dest);

    /* 修改名称 */
    void modify_macro_name(uint macro_index, QString macro_name);

    /* 宏指令对象 */
    Macro* macro(uint);

private:




private:

    /* 宏指令脚本集合 */
    QMap<uint,Macro*> m_macro_map;
};

#endif // MACRO_MANAGE_H
