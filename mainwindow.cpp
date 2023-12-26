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
   if(ui->plusCheck_1->isChecked() || ui->minusCheck_1->isChecked())
        ui->resultNum->setText(C.calculate_plus_minus(ui->plusCheck_1->isChecked(), ui->firstNum->text(), ui->secondNum->text(), 10));
   else
       if(ui->multiplyCheck_1->isChecked())
            ui->resultNum->setText(C.calculate_multiply(ui->firstNum->text(), ui->secondNum->text(), 10));
       else
            ui->resultNum->setText(C.calculate_divide(ui->firstNum->text(), ui->secondNum->text(), 10));


   /*if(ui->plusCheck_2->isChecked() || ui->minusCheck_2->isChecked())
        ui->resultNum->setText(C.calculate_plus_minus(ui->plusCheck_2->isChecked(), ui->resultNum->text(), ui->thirdNum->text(), 10));
   else
       if(ui->multiplyCheck_2->isChecked())
            ui->resultNum->setText(C.calculate_multiply(ui->thirdNum->text(), ui->resultNum->text(), 10));
       else
            ui->resultNum->setText(C.calculate_divide(ui->thirdNum->text(), ui->resultNum->text(), 10));


   if(ui->plusCheck_3->isChecked() || ui->minusCheck_3->isChecked())
        ui->resultNum->setText(C.calculate_plus_minus(ui->plusCheck_3->isChecked(), ui->resultNum->text(), ui->fourthNum->text(), 10));
   else
       if(ui->multiplyCheck_3->isChecked())
            ui->resultNum->setText(C.calculate_multiply(ui->resultNum->text(), ui->fourthNum->text(), 10));
       else
            ui->resultNum->setText(C.calculate_divide(ui->resultNum->text(), ui->fourthNum->text(), 10));

   if(ui->mathButton->isChecked())
       ui->resultNum->setText(C.round_math(ui->resultNum->text(), 6));
   else if(ui->bankButton->isChecked())
       ui->resultNum->setText(C.round_bank(ui->resultNum->text(), 6));
   else
       ui->resultNum->setText(C.truncate(ui->resultNum->text(), 6));*/
}

