#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class Calculator : public QWidget {
    Q_OBJECT

private:
    QLineEdit *num1, *num2, *result;
    QString number1, number2;
    int operand = -1;
    int state = 1;

public:
    Calculator(QWidget *parent = nullptr);

private slots:
    void numberClickHandler(int num);
    void setOperand(int op);
    void calculate();
    void clearFields();
};

#endif // CALCULATOR_H
