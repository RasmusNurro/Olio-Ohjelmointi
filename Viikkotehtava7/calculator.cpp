#include "calculator.h"
#include <QDebug>

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    QGridLayout *layout = new QGridLayout(this);

    QLabel *label1 = new QLabel("Number 1:", this);
    QLabel *label2 = new QLabel("Number 2:", this);
    QLabel *label3 = new QLabel("Result:", this);

    num1 = new QLineEdit(this);
    num2 = new QLineEdit(this);
    result = new QLineEdit(this);
    result->setReadOnly(true);

    QPushButton *buttons[10];
    for (int i = 0; i < 10; ++i) {
        buttons[i] = new QPushButton(QString::number(i), this);
        connect(buttons[i], &QPushButton::clicked, this, [this, i]() { numberClickHandler(i); });
    }

    QPushButton *add = new QPushButton("+", this);
    QPushButton *sub = new QPushButton("-", this);
    QPushButton *mul = new QPushButton("*", this);
    QPushButton *div = new QPushButton("/", this);
    QPushButton *clear = new QPushButton("Clear", this);
    QPushButton *enter = new QPushButton("Enter", this);

    layout->addWidget(label1, 0, 0);
    layout->addWidget(num1, 0, 1, 1, 3);
    layout->addWidget(label2, 1, 0);
    layout->addWidget(num2, 1, 1, 1, 3);
    layout->addWidget(label3, 2, 0);
    layout->addWidget(result, 2, 1, 1, 3);

    layout->addWidget(buttons[1], 3, 0);
    layout->addWidget(buttons[2], 3, 1);
    layout->addWidget(buttons[3], 3, 2);
    layout->addWidget(add, 3, 3);

    layout->addWidget(buttons[4], 4, 0);
    layout->addWidget(buttons[5], 4, 1);
    layout->addWidget(buttons[6], 4, 2);
    layout->addWidget(sub, 4, 3);

    layout->addWidget(buttons[7], 5, 0);
    layout->addWidget(buttons[8], 5, 1);
    layout->addWidget(buttons[9], 5, 2);
    layout->addWidget(mul, 5, 3);

    layout->addWidget(buttons[0], 6, 0);
    layout->addWidget(clear, 6, 1);
    layout->addWidget(enter, 6, 2);
    layout->addWidget(div, 6, 3);

    connect(add, &QPushButton::clicked, this, [this]() { setOperand(0); });
    connect(sub, &QPushButton::clicked, this, [this]() { setOperand(1); });
    connect(mul, &QPushButton::clicked, this, [this]() { setOperand(2); });
    connect(div, &QPushButton::clicked, this, [this]() { setOperand(3); });
    connect(clear, &QPushButton::clicked, this, &Calculator::clearFields);
    connect(enter, &QPushButton::clicked, this, &Calculator::calculate);
}

void Calculator::numberClickHandler(int num) {
    if (state == 1) {
        number1 += QString::number(num);
        num1->setText(number1);
    } else if (state == 2) {
        number2 += QString::number(num);
        num2->setText(number2);
    }
    qDebug() << "Number1:" << number1 << "Number2:" << number2;
}

void Calculator::setOperand(int op) {
    operand = op;
    state = 2;
}

void Calculator::calculate() {
    bool ok1, ok2;
    float val1 = number1.toFloat(&ok1);
    float val2 = number2.toFloat(&ok2);

    if (ok1 && ok2) {
        float res = 0;
        switch (operand) {
        case 0: res = val1 + val2; break;
        case 1: res = val1 - val2; break;
        case 2: res = val1 * val2; break;
        case 3: res = (val2 != 0) ? val1 / val2 : 0; break;
        }
        result->setText(QString::number(res));
    } else {
        result->setText("Error");
    }
}

void Calculator::clearFields() {
    number1.clear();
    number2.clear();
    num1->clear();
    num2->clear();
    result->clear();
    state = 1;
}
