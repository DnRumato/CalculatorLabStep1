#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   C.calculate(ui->plusCheck->isChecked(), ui->firstNum->text(), ui->secondNum->text());
   ui->resultNum->setText(C.calculate(ui->plusCheck->isChecked(), ui->firstNum->text(), ui->secondNum->text()));
}

