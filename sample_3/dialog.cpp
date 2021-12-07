#include "dialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

void Dialog::initUi()
{
    checkBox_Underline = new QCheckBox(tr("Underline"));
    checkBox_Italic = new QCheckBox(tr("Italic"));
    checkBox_Bold = new QCheckBox(tr("Bold"));
    QHBoxLayout *HLayout1 = new QHBoxLayout;
    HLayout1->addWidget(checkBox_Underline);
    HLayout1->addWidget(checkBox_Italic);
    HLayout1->addWidget(checkBox_Bold);

    rBtn_Balck = new QRadioButton(tr("Black"));
    rBtn_Blue =new QRadioButton(tr("Blue"));
    rBtn_Red = new QRadioButton(tr("Red"));
    QHBoxLayout *HLayout2 =new QHBoxLayout;
    HLayout2->addWidget(rBtn_Balck);
    HLayout2->addWidget(rBtn_Blue);
    HLayout2->addWidget(rBtn_Red);

    plainTxtEdit = new QPlainTextEdit();
    QFont font =plainTxtEdit->font();
    font.setPointSize(20);
    plainTxtEdit->setFont(font);
    plainTxtEdit->setPlainText("hello world\n\ng");

    btn_ok = new QPushButton("ok");
    btn_cancel = new QPushButton("cancel");
    btn_esc = new QPushButton("esc");
    QHBoxLayout *HLayout3 =new QHBoxLayout;
    HLayout3->addStretch();
    HLayout3->addWidget(btn_ok);
    HLayout3->addWidget(btn_cancel);
    HLayout3->addStretch();
    HLayout3->addWidget(btn_esc);

    QVBoxLayout *VLayout = new QVBoxLayout;
    VLayout->addLayout(HLayout1);
    VLayout->addLayout(HLayout2);
    VLayout->addWidget(plainTxtEdit);
    VLayout->addLayout(HLayout3);
    setLayout(VLayout);
}

void Dialog::iniSignalSlots()
{
    connect(btn_cancel,SIGNAL(clicked()),this,SLOT(reject()));
    connect(btn_esc,SIGNAL(clicked()),this,SLOT(close()));
    connect(btn_ok,SIGNAL(clicked()),this,SLOT(accept()));

    connect(checkBox_Bold,SIGNAL(clicked(bool)),this,SLOT(on_checkBold(bool)));
    connect(checkBox_Italic,SIGNAL(clicked(bool)),this,SLOT(on_checkItalic(bool)));
    connect(checkBox_Underline,SIGNAL(clicked(bool)),this,SLOT(on_checkUnderline(bool)));

    connect(rBtn_Balck,SIGNAL(clicked(bool)),this,SLOT(setTextFontColor()));
    connect(rBtn_Blue,SIGNAL(clicked(bool)),this,SLOT(setTextFontColor()));
    connect(rBtn_Red,SIGNAL(clicked(bool)),this,SLOT(setTextFontColor()));
}

void Dialog::on_checkUnderline(bool checked)
{
    QFont font =plainTxtEdit->font();
    font.setUnderline(checked);
    plainTxtEdit->setFont(font);
}

void Dialog::on_checkBold(bool checked)
{
    QFont font = plainTxtEdit->font();
    font.setBold(checked);
    plainTxtEdit->setFont(font);
}

void Dialog::on_checkItalic(bool checked)
{
    QFont font =  plainTxtEdit->font();
    font.setItalic(checked);
    plainTxtEdit->setFont(font);
}

void Dialog::setTextFontColor()
{
    QPalette palet = plainTxtEdit->palette();

    if(rBtn_Balck->isChecked())
        palet.setColor(QPalette::Text,Qt::black);
    else if(rBtn_Blue->isChecked())
        palet.setColor(QPalette::Text,Qt::blue);
    else if(rBtn_Red->isChecked())
        palet.setColor(QPalette::Text,Qt::red);
    else
        palet.setColor(QPalette::Text,Qt::gray);
    plainTxtEdit->setPalette(palet);
}

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    initUi();
    iniSignalSlots();
}

Dialog::~Dialog()
{

}
