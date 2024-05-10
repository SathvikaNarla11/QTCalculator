#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

int MainWindow::count=0;
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
    connect(ui->pushButtonMinus,SIGNAL(clicked),this,SLOT(on_pushButtonMinus_clicked));
    connect(ui->pushButtonMultiply,SIGNAL(clicked),this,SLOT(on_pushButtonMultiply_clicked));
    connect(ui->pushButtonDiv,SIGNAL(clicked),this,SLOT(on_pushButtonDiv_clicked));
    connect(ui->pushButtonQuo,SIGNAL(clicked),this,SLOT(on_pushButtonQuo_clicked));
     connect(ui->pushButtonDot,SIGNAL(clicked),this,SLOT(on_pushButtonDot_clicked));

    connect(ui->pushButtonEq,SIGNAL(clicked),this,SLOT(on_pushButtonEq_clicked));
    connect(ui->pushButtonClear,SIGNAL(clicked),this,SLOT(on_pushButtonClear_clicked));
    connect(ui->pushButtonBack,SIGNAL(clicked),this,SLOT(onPushButtonBack_clicked));

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
    count=0;
    if(!operand1.isEmpty() && !operand2.isEmpty() && !operation.isEmpty())
    {
        on_pushButtonEq_clicked();
    }
    if (!operand1.isEmpty() && equ.isEmpty())
    {
        operation = '+';
        //        QString operand1 = ui->lineEdit->text();
        ui->lineEditExpression->setText(operand1 + operation);
        ui->lineEdit->setText(operand1 + operation);
        operand2 = "";
    }
    else if(operand1.isEmpty())
    {
        operand1 = "+";
        ui->lineEdit->setText(operand1);
    }
}
void MainWindow::on_pushButtonMinus_clicked()
{
    count=0;
    if(!operand1.isEmpty() && !operand2.isEmpty() && !operation.isEmpty())
    {
        on_pushButtonEq_clicked();
    }
    if(!operand1.isEmpty() && equ.isEmpty())
    {
        operation = '-';
        ui->lineEditExpression->setText(operand1 + operation);
        ui->lineEdit->setText(operand1 + operation);
        operand2 = "";
    }
    else//if(operand1.isEmpty())
    {
        operand1 = "-";
        ui->lineEdit->setText(operand1);
    }
}
void MainWindow::on_pushButtonMultiply_clicked()
{
    count=0;
    if(!operand1.isEmpty() && !operand2.isEmpty() && !operation.isEmpty())
    {
        on_pushButtonEq_clicked();
    }
    if(!operand1.isEmpty() && equ.isEmpty())
    {
        operation = '*';
        ui->lineEditExpression->setText(operand1 + operation);
        ui->lineEdit->setText(operand1 + operation);
        operand2 = "";
    }
    else if(operand1.isEmpty())
    {
        operand1 = "0";
        operation = '*';
        ui->lineEditExpression->setText(operand1 + operation);
        ui->lineEdit->setText(operand1 + operation);
    }
}
void MainWindow::on_pushButtonDiv_clicked()
{
    count=0;
    if(!operand1.isEmpty() && !operand2.isEmpty() && !operation.isEmpty())
    {
        on_pushButtonEq_clicked();
    }
    if(!operand1.isEmpty() && equ.isEmpty())
    {
        operation = '%';
        ui->lineEditExpression->setText(operand1 + operation);
        ui->lineEdit->setText(operand1 + operation);
        operand2 = "";
    }
    else if(operand1.isEmpty())
    {
        operand1 = "0";
        operation = '%';
        ui->lineEditExpression->setText(operand1 + operation);
        ui->lineEdit->setText(operand1 + operation);
    }
}
void MainWindow::on_pushButtonQuo_clicked()
{
    count=0;
    if(!operand1.isEmpty() && !operand2.isEmpty() && !operation.isEmpty())
    {
        on_pushButtonEq_clicked();
    }
    if(!operand1.isEmpty() && equ.isEmpty())
    {
        operation = '/';
        ui->lineEditExpression->setText(operand1 + operation);
        ui->lineEdit->setText(operand1 + operation);
        operand2 = "";
    }
    else if(operand1.isEmpty())
    {
        operand1 = "0";
        operation = '/';
        ui->lineEditExpression->setText(operand1 + operation);
        ui->lineEdit->setText(operand1 + operation);
    }
}

void MainWindow::on_pushButtonEq_clicked()
{
    count=0;
    equ.append('=');
    double result = 0.0;
    double n2;
    ui->lineEdit->setReadOnly(true);
    double n1 = operand1.toDouble();

    if(operand2.isEmpty())
    {

        double d = 0.0;
        n2 = operand1.toDouble();

        expression = operand1 + operation + operand1;
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
        else if(operation == "/")
        {
            result = n1/n2;
            ui->lineEdit->setText(QString::number(result));
        }
        operand2 = operand1;
        operand1 = QString::number(result);
        qDebug()<<"Operation1 in if : "<<operand1;
        qDebug()<<"Operation2 in if : "<<operand2;
        expression ="";
        equ ="";


    }
    else
    {
        n2 = operand2.toDouble();

        int d = 0;
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
        else if(operation == "/")
        {
            result = n1/n2;
            ui->lineEdit->setText(QString::number(result));
        }
        qDebug()<<result;
        operand1 = QString::number(result);
        qDebug()<<"Operation1 in else : "<<operand1;
        qDebug()<<"Operation2 in else : "<<operand2;
//        operand2 = "";
        expression ="";
        equ ="";

    }
}

void MainWindow::on_pushButtonBack_clicked()
{
    operand1 = "";
    operand2 = "";
    operation = "";

    QString cmp = ui->lineEdit->text();
    qDebug()<<"Expression is : "<<cmp;
    cmp.chop(1);

    ui->lineEdit->setText(cmp);
    cmp = ui->lineEdit->text();

    int l=0;
    int n = cmp.length();
    qDebug()<< "length() : "<<n;

    qDebug()<<"Complete else block";
    operand1 = ui->lineEdit->text();
    QChar lastChar = operand1.at(operand1.length() - 1);
    if(lastChar =='+'||lastChar =='-'||lastChar =='*'||lastChar =='%')
    {
        operand1.chop(1);
        ui->lineEdit->setText(operand1);
        qDebug()<<"operand1 : "<<operand1;
        operand2 = "";
        operation = "";
    }
    else
    {
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
        }
    }
}


void MainWindow::on_pushButtonDot_clicked()
{
    if((count == 0) && operand2.isEmpty() && operation.isEmpty())
    {
        operand1 += '.';
        ui->lineEdit->setText(operand1);
        count++;
    }
    else if(count==1)
    {
        return;
    }
    else
    {
        operand2 +='.';
        ui->lineEdit->setText(operand1+operation + operand2);
        count++;
    }
}


void MainWindow::on_pushButtonClear_clicked()
{
    ui->lineEdit->clear();
    ui->lineEditExpression ->clear();

    operand1 = "";
    operand2 = "";
    operation = "";
    count = 0;
}
