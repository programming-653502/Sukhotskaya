#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QFile>
#include <QTextStream>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void mChangeWidget();
    void mRefreshQuestion();
    void mCheckAnswer();

private slots:
    void finalResult();

private:
    bool initializeFile();

private:
    Ui::Widget *ui;
    QFile file;
    QTextStream inStream;

    int correctAnswer;
    int rightAnswers;
    int totalAnswers;

};

#endif // MYWIDGET_H
