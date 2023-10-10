#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <math.h>

class calculator
{
public:
    calculator();
    QString calculate(bool flag, QString firstStr, QString secondStr);
};

#endif // CALCULATOR_H
