#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QPlainTextEdit>


class Dialog : public QDialog
{
    Q_OBJECT
private:
    QCheckBox *checkBox_Underline;
    QCheckBox *checkBox_Italic;
    QCheckBox *checkBox_Bold;

    QRadioButton *rBtn_Balck;
    QRadioButton *rBtn_Blue;
    QRadioButton *rBtn_Red;

    QPlainTextEdit *plainTxtEdit;

    QPushButton *btn_ok;
    QPushButton *btn_cancel;
    QPushButton *btn_esc;

    void initUi();
    void iniSignalSlots();

private slots:
    void on_checkUnderline(bool checked);
    void on_checkBold(bool checked);
    void on_checkItalic(bool checked);

    void setTextFontColor();

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
};

#endif // DIALOG_H
