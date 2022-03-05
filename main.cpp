#include "mainwindow.h"
#include "logindialog.h"
#include "orderinfo.h"
#include "admindialog.h"

#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

int tableInfo = 0;
int orderInfo[9][6];

bool saveOrders()
{
    //用IODevice方式打开文本文件
    QFile qFile("C:\\Users\\75499\\Documents\\program\\qt\\OrderSystem\\OrderInfo.txt");
    if (!qFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
        return false;
    QTextStream qTextStream(&qFile);
    for (int i = 1; i < 9; i++)
    {
        for (int j = 0; j < 6; j++)
            qTextStream << orderInfo[i][j] << ' ';
        qTextStream << endl;
    }
    qFile.close();
    return true;
}

bool loadOrders()
{
    //用IODevice方式打开文本文件
    QFile qFile("C:\\Users\\75499\\Documents\\program\\qt\\OrderSystem\\OrderInfo.txt");
    if (!qFile.exists()) //文件不存在
        return false;
    if (!qFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    QTextStream qTextStream(&qFile);
    for (int i = 1; i < 9; i++)
        for (int j = 0; j < 6; j++)
            qTextStream >> orderInfo[i][j];
    qFile.close();
    return true;
}

int main(int argc, char *argv[])
{
    loadOrders();
    QApplication a(argc, argv);

    while (true)
    {
        LoginDialog loginDialog;
        int table = loginDialog.exec();
        if (table == QDialog::Accepted)
        {
            AdminDialog adminDialog;
            adminDialog.show();
            a.exec();
            table = 0;
        }
        else if (table >= 2 && table <= 9)
        {
            if (orderInfo[table - 1][0])
            {
                QMessageBox::warning(NULL, "登录失败",
                                     "这桌有人了!");
                continue;
            }

            tableInfo = table - 1;
            orderInfo[tableInfo][0] = 1;

            MainWindow mainWindow;
            mainWindow.show();
            a.exec();
            table = 0;
        }
        else if (table == QDialog::Rejected)
            break;
    }
    saveOrders();

    return 0;
}
