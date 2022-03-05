#include "checkdialog.h"
#include "ui_checkdialog.h"

CheckDialog::CheckDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckDialog)
{
    ui->setupUi(this);
}

CheckDialog::~CheckDialog()
{
    delete ui;
}
