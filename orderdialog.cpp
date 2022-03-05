#include "orderdialog.h"
#include "ui_orderdialog.h"
#include "orderinfo.h"

OrderDialog::OrderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderDialog)
{
    ui->setupUi(this);
    ui->aPriceLabel->setNum(orderInfo[tableInfo][1] * PRICES[1]);
    ui->bPriceLabel->setNum(orderInfo[tableInfo][2] * PRICES[2]);
    ui->cPriceLabel->setNum(orderInfo[tableInfo][3] * PRICES[3]);
    ui->dPriceLabel->setNum(orderInfo[tableInfo][4] * PRICES[4]);
    ui->allPriceLabel->setNum(orderInfo[tableInfo][5]);
}

OrderDialog::~OrderDialog()
{
    delete ui;
}
