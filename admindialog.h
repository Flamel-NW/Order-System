#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QDialog>

namespace Ui {
class AdminDialog;
}

class AdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminDialog(QWidget *parent = nullptr);
    ~AdminDialog();

private slots:
    void on_checkButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::AdminDialog *ui;
};

#endif // ADMINDIALOG_H
