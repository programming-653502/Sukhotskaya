#include "myWidget.h"
#include "ui_myWidget.h"

#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget), rightAnswers(0), totalAnswers(0)
{
    ui->setupUi(this);
    connect(ui->okButton, SIGNAL(released()), this, SLOT(mChangeWidget()));
    connect(ui->answerButton, SIGNAL(released()), this, SLOT(mCheckAnswer()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mChangeWidget()
{
    qDebug() << "PRESSED";
    if (initializeFile())
    {
        ui->stackedWidget->setCurrentIndex(1);
        inStream.setDevice(&file);
        mRefreshQuestion();
    }
    else if (!initializeFile())
    {
        QMessageBox msgBox(QMessageBox::Critical,tr("Ошибка открытия файла"), tr("Пожалуйста, выберите другой файл"), QMessageBox::Ok);
        msgBox.exec();
    }
}

void Widget::mRefreshQuestion()
{
    QString line;
    if (!inStream.atEnd())
    {
        ++totalAnswers;
        line = inStream.readLine();
        ui->questionLabel->setText(line);
        line = inStream.readLine();
        if (line.at(0) == '+')
        {
            line.remove(0, 1);
            correctAnswer = 1;
        }
        ui->first->setText(line);
        line = inStream.readLine();
        if (line.at(0) == '+')
        {
            line.remove(0, 1);
            correctAnswer = 2;
        }
        ui->second->setText(line);
        line = inStream.readLine();
        if (line.at(0) == '+')
        {
            line.remove(0, 1);
            correctAnswer = 3;
        }
        ui->third->setText(line);
        line = inStream.readLine();
        if (line.at(0) == '+')
        {
            line.remove(0, 1);
            correctAnswer = 4;
        }
        ui->fourth->setText(line);
    }
    else
    {
        QMessageBox warningMsgBox(QMessageBox::Information,tr("Конец"), tr("Тест завершён"), QMessageBox::Ok);
        warningMsgBox.exec();
        finalResult();
    }
}

void Widget::mCheckAnswer()
{
    QMessageBox errorMsgBox(QMessageBox::Critical,tr("Ошибка!"), tr("Неверный ответ"), QMessageBox::Ok);
    QMessageBox rightMsgBox(QMessageBox::Information,tr("Верно!"), tr("Правильный ответ, так держать!"), QMessageBox::Ok);
    QMessageBox warningMsgBox(QMessageBox::Critical,tr("Внимательнее!"), tr("Необходимо выбрать вариант"), QMessageBox::Ok);
    if (ui->first->isChecked())
    {
        if (correctAnswer == 1)
        {
            rightMsgBox.exec();
            rightAnswers++;
        }
        else if (correctAnswer != 1)
            errorMsgBox.exec();
        mRefreshQuestion();
    }
    else if (ui->second->isChecked())
    {
        if (correctAnswer == 2)
        {
            rightMsgBox.exec();
            rightAnswers++;
        }
        else if (correctAnswer != 2)
            errorMsgBox.exec();
        mRefreshQuestion();
    }
    else if (ui->third->isChecked())
    {
        if (correctAnswer == 3)
        {
            rightMsgBox.exec();
            rightAnswers++;
        }
        else if (correctAnswer != 3)
            errorMsgBox.exec();
        mRefreshQuestion();
    }
    else if (ui->fourth->isChecked())
    {
        if (correctAnswer == 4)
        {
            rightMsgBox.exec();
            rightAnswers++;
        }
        else if (correctAnswer != 4)
            errorMsgBox.exec();
        mRefreshQuestion();
    }
    else
        warningMsgBox.exec();
}

void Widget::finalResult()
{
    QString result;
    result = "Вы правильно ответили на " + QString::number(rightAnswers) + " из " + QString::number(totalAnswers) + " вопросов.";
    QMessageBox finalMsgBox(QMessageBox::Information,tr("Тест завершён"), result, QMessageBox::Ok);
    finalMsgBox.exec();
    ui->stackedWidget->setCurrentIndex(0);
}

bool Widget::initializeFile()
{
    file.setFileName("D:\\Files\\Test.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    else
        return true;
}
