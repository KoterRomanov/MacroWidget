#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class QsciScintilla;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void slot_compile();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;

    QsciScintilla *textEdit;
};

#endif // DIALOG_H
