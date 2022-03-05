#include "logindialog.h"
#include "ui_logindialog.h"

#include <QMessageBox>

const QString USER_PWD = "1";
const QString ADMIN_PWD = "0";

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginButton_clicked()
{
    int table = ui->nameEdit->text().toInt();
    if (ui->pwdEdit->text() == ADMIN_PWD && ui->nameEdit->text() == "admin")
        accept();
    else if (ui->pwdEdit->text() == USER_PWD && table <= 8 && table >= 1)
        done(table + 1);
    else
    {
        QMessageBox::warning(this, tr("登录失败"),
                             tr("用户名密码错误!"));
        ui->nameEdit->clear();
        ui->pwdEdit->clear();
        ui->nameEdit->setFocus();
    }
}

void LoginDialog::on_cancelButton_clicked()
{
    reject();
}
