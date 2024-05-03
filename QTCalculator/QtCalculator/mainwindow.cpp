#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>


QString btnName;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < 10; i++)
    {
        QString btnName = "pushButton" + QString::number(i);
        QPushButton *numberButton = findChild<QPushButton*>(btnName);
        connect(numberButton, SIGNAL(clicked()), this, SLOT(on_numberButton_clicked()));

    }
    connect(ui->pushButtonPlus,SIGNAL(clicked),this,SLOT(on_pushButtonPlus_clicked));

    connect(ui->pushButtonEq,SIGNAL(clicked),this,SLOT(on_pushButtonEq_clicked));
    connect(ui->pushButtonClear,SIGNAL(clicked),this,SLOT(on_pushButtonClear_clicked));
    connect(ui->pushButtonPlus,SIGNAL(clicked),this,SLOT(onPushButtonBack_clicked));
    //  connect(ui->pushButtonClear,SIGNAL(clicked),this,SLOT(onPushButtonClearClicked));

    operand1 ="";
    operand2 ="";
    operation ="";
    expression ="";
    equ ="";

    ui->lineEdit->setText(QString::number(0));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_numberButton_clicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString text = button->text();

    if(operation.isEmpty())// && equ.isEmpty())
    {
        operand1.append(text);
        ui->lineEdit->setText(operand1);
    }
    else //if(equ.isEmpty())
    {
        operand2.append(text);
        ui->lineEdit->setText(operand1 + operation + operand2);
    }
}
void MainWindow::on_pushButtonPlus_clicked()
{
    if (!operand1.isEmpty() && equ.isEmpty())
    {
        operation.append('+');
        //        QString operand1 = ui->lineEdit->text();
        ui->lineEditExpression->setText(operand1 + operation);
        ui->lineEdit->setText(operand1 + operation);
    }
}
void MainWindow::on_pushButtonMinus_clicked()
{
    if(!operand1.isEmpty() && equ.isEmpty())
    {
        operation.append('-');
        ui->lineEditExpression->setText(operand1 + operation);
        ui->lineEdit->setText(operand1 + operation);
    }
}
void MainWindow::on_pushButtonMultiply_clicked()
{
    if(!operand1.isEmpty() && equ.isEmpty())
    {
        operation.append('*');
        ui->lineEditExpression->setText(operand1 + operation);
        ui->lineEdit->setText(operand1 + operation);
    }
}
void MainWindow::on_pushButtonDiv_clicked()
{
    if(!operand1.isEmpty() && equ.isEmpty())
    {
        operation.append('%');
        ui->lineEditExpression->setText(operand1 + operation);
        ui->lineEdit->setText(operand1 + operation);
    }
}

void MainWindow::on_pushButtonEq_clicked()
{
    equ.append('=');
    double result = 0.0;
    if(equ == '=')
    {
        ui->lineEdit->setReadOnly(true);
        double n1 = operand1.toDouble();
        double n2 = operand2.toDouble();
        double d = 0.0;
        //        double result = 0.0;
        qDebug()<<n1;
        qDebug()<<n2;

        expression = operand1 + operation + operand2;
        ui->lineEditExpression->setText(expression);
        if(operation == "+")
        {
            result = n1+n2;
            ui->lineEdit->setText(QString::number(result));
        }
        else if(operation == "-")
        {
            result = n1-n2;
            ui->lineEdit->setText(QString::number(result));
        }
        else if(operation == "*")
        {
            result = n1*n2;
            ui->lineEdit->setText(QString::number(result));
        }
        else if(operation == "%")
        {
            if(n2!=0)
            {
                d = n1/n2;
                result = n1-(n2*d);
                ui->lineEdit->setText(QString::number(result));
            }
            else
            {
                ui->lineEdit->setText("Cannot be divided by zero");
            }

        }
        qDebug()<<result;
        operand1 = QString::number(result);
        qDebug()<<"Operation1 is in block : "<<operand1;
    }
    operand1 = QString::number(result);
    qDebug()<<"Operation1 is out block : "<<operand1;
    operation = "";
    operand2="";
    expression ="";
    equ ="";

}

void MainWindow::on_pushButtonBack_clicked()
{
    qDebug()<<"operand1 : "<<operand1;
    qDebug()<<"operand2 : "<<operand2;
    qDebug()<<"operation : "<<operation;

    operand1 = "";
    operand2 = "";
    operation = "";

    qDebug()<<"operand1 : "<<operand1;
    qDebug()<<"operand2 : "<<operand2;
    qDebug()<<"operation : "<<operation;

    QString cmp = ui->lineEdit->text();
    qDebug()<<"Expression is : "<<cmp;
    cmp.chop(1);
    ui->lineEdit->setText(cmp);
    cmp = ui->lineEdit->text();
    qDebug()<<"Length of expression after chop : "<<cmp.length();
    qDebug()<<"Expression after chop is : "<<cmp;
    int l=0;

    //    QChar lastChar = cmp.at(cmp.length() - 1);

    for(int i=0;i<cmp.length();i++)
    {
        if(cmp.at(i)== '+'||cmp.at(i)== '-'||cmp.at(i)== '*'||cmp.at(i)== '%')
        {
            l = i;
            qDebug()<<"l is : "<<l;
            if(l< cmp.length()-1)
            {
                qDebug()<<"In loop "<<l;

                operand1="";
                for(int j=l+1;j< cmp.length();j++)
                {
                    operand2+= cmp.at(j);
                    qDebug()<<"operand2 : "<<operand2;
                }
                for(int j=0;j<(l);j++)
                {
                    operand1+= cmp.at(j);
                    qDebug()<<"operand1 : "<<operand1;
                }
                operation = cmp.at(i);
                qDebug()<<"operation : "<<operation;

                break;
            }
            else if(l== cmp.length()-1)
            {
                for(int j=0;j< (l-1);j++)
                {
                    operand1+= cmp.at(j);
                    qDebug()<<"operand1 : "<<operand1;
                }
                operand2="";
                break;
            }

        }
        else
        {
            qDebug()<<"Complete else block";
            operand1 = ui->lineEdit->text();
            QChar lastChar = operand1.at(operand1.length() - 1);
            if(lastChar =='+'||lastChar =='-'||lastChar =='*'||lastChar =='%')
            {
                operand1.chop(1);
                ui->lineEdit->setText(operand1);
            }
            qDebug()<<"operand1 : "<<operand1;
            operand2 = "";
            operation = "";
            break;
        }

    }
}

void MainWindow::on_pushButtonClear_clicked()
{
    ui->lineEdit->clear();
    ui->lineEditExpression ->clear();

    operand1 = "";
    operand2 = "";
    operation = "";
}




//void MainWindow::on_pushButton0_clicked()
//{
//    if(operation.isEmpty())
//    {
//        operand1.append('0');
//        ui->lineEdit->setText(operand1);
//    }
//    else
//    {
//        operand2.append('0');
//        ui->lineEdit->setText(operand1 +" "+ operation +" "+ operand2);
//    }
//}
//void MainWindow::on_pushButton1_clicked()
//{
//    if(operation.isEmpty())
//    {
//        operand1.append('1');
//        ui->lineEdit->setText(operand1);
//    }
//    else
//    {
//        operand2.append('1');
//        ui->lineEdit->setText(operand1 +" "+ operation +" "+ operand2);
//    }

//}
//void MainWindow::on_pushButton2_clicked()
//{
//    if(operation.isEmpty())
//    {
//        operand1.append('2');
//        ui->lineEdit->setText(operand1);
//    }
//    else
//    {
//        operand2.append('2');
//        ui->lineEdit->setText(operand1 +" "+ operation +" "+ operand2);
//    }
//}
//void MainWindow::on_pushButton3_clicked()
//{
//    if(operation.isEmpty())
//    {
//        operand1.append('3');
//        ui->lineEdit->setText(operand1);
//    }
//    else
//    {
//        operand2.append('3');
//        ui->lineEdit->setText(operand1 +" "+ operation +" "+ operand2);
//    }
//}
//void MainWindow::on_pushButton4_clicked()
//{
//    if(operation.isEmpty())
//    {
//        operand1.append('4');
//        ui->lineEdit->setText(operand1);
//    }
//    else
//    {
//        operand2.append('4');
//        ui->lineEdit->setText(operand1 +" "+ operation +" "+ operand2);
//    }
//}
//void MainWindow::on_pushButton5_clicked()
//{
//    if(operation.isEmpty())
//    {
//        operand1.append('5');
//        ui->lineEdit->setText(operand1);
//    }
//    else
//    {
//        operand2.append('5');
//        ui->lineEdit->setText(operand1 +" "+ operation +" "+ operand2);
//    }
//}
//void MainWindow::on_pushButton6_clicked()
//{
//    if(operation.isEmpty())
//    {
//        operand1.append('6');
//        ui->lineEdit->setText(operand1);
//    }
//    else
//    {
//        operand2.append('6');
//        ui->lineEdit->setText(operand1 +" "+ operation +" "+ operand2);
//    }
//}
//void MainWindow::on_pushButton7_clicked()
//{
//    if(operation.isEmpty())
//    {
//        operand1.append('7');
//        ui->lineEdit->setText(operand1);
//    }
//    else
//    {
//        operand2.append('7');
//        ui->lineEdit->setText(operand1 +" "+ operation +" "+ operand2);
//    }
//}
//void MainWindow::on_pushButton8_clicked()
//{
//    if(operation.isEmpty())
//    {
//        operand1.append('8');
//        ui->lineEdit->setText(operand1);
//    }
//    else
//    {
//        operand2.append('8');
//        ui->lineEdit->setText(operand1 +" "+ operation +" "+ operand2);
//    }
//}
//void MainWindow::on_pushButton9_clicked()
//{
//    if(operation.isEmpty())
//    {
//        operand1.append('9');
//        ui->lineEdit->setText(operand1);
//    }
//    else
//    {
//        operand2.append('9');
//        ui->lineEdit->setText(operand1 +" "+ operation +" "+ operand2);
//    }
//}
//void MainWindow::onPushButtonPlusClicked()

//    if(!operand1.isEmpty())
//    {
//        operation.append('+');
//        ui->lineEdit->setText(operand1 +" "+ operation);
//    }



