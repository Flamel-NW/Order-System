#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "orderinfo.h"
#include "orderdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->aSpinBox->setRange(0, 100);
    ui->bSpinBox->setRange(0, 100);
    ui->cSpinBox->setRange(0, 100);
    ui->dSpinBox->setRange(0, 100);
    ui->tableLabel->setNum(tableInfo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_submitButton_clicked()
{
    orderInfo[tableInfo][1] = ui->aSpinBox->value();
    orderInfo[tableInfo][2] = ui->bSpinBox->value();
    orderInfo[tableInfo][3] = ui->cSpinBox->value();
    orderInfo[tableInfo][4] = ui->dSpinBox->value();
    orderInfo[tableInfo][5] = orderInfo[tableInfo][1] * PRICES[1]
            + orderInfo[tableInfo][2] * PRICES[2]
            + orderInfo[tableInfo][3] * PRICES[3]
            + orderInfo[tableInfo][4] * PRICES[4];
    OrderDialog orderDialog;
    orderDialog.exec();
}

void MainWindow::on_cancelButton_clicked()
{
    ui->aSpinBox->setValue(0);
    ui->bSpinBox->setValue(0);
    ui->cSpinBox->setValue(0);
    ui->dSpinBox->setValue(0);
}
