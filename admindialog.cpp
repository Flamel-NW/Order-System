#include "admindialog.h"
#include "ui_admindialog.h"
#include "orderinfo.h";
#include "orderdialog.h"
#include <QMessageBox>

AdminDialog::AdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDialog)
{
    ui->setupUi(this);
    ui->spinBox->setRange(1, 8);
}

AdminDialog::~AdminDialog()
{
    delete ui;
}

void AdminDialog::on_checkButton_clicked()
{
    tableInfo = ui->spinBox->value();
    if (!orderInfo[tableInfo][0])
    {
        QMessageBox::warning(this, tr("查询失败"),
                             tr("这桌没人!"));
        ui->spinBox->setValue(0);
    }
    else
    {
        OrderDialog orderDialog;
        orderDialog.exec();
    }
}

void AdminDialog::on_deleteButton_clicked()
{
    tableInfo = ui->spinBox->value();
    if (!orderInfo[tableInfo][0])
    {
        QMessageBox::warning(this, tr("结账失败"),
                             tr("这桌没人!"));
        ui->spinBox->setValue(0);
    }
    else
    {
        tableInfo = ui->spinBox->value();
        for (int i = 0; i < 6; i++)
            orderInfo[tableInfo][i] = 0;
        QMessageBox::warning(this, tr("结账成功"),
                             tr("这桌没人了!"));
    }
}
