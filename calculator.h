#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <math.h>
#include <cmath>
#include <QString>
#include <QRegExp>
#include <QLocale>

class calculator
{
public:
    calculator();
    QString calculate_plus_minus(bool flag, QString firstStr, QString secondStr, int precision);
    QString calculate_multiply(QString firstStr, QString secondStr, int precision);
    QString calculate_divide(QString firstStr, QString secondStr, int precision);

    QString round_math(QString str, int precision);
    QString round_bank(QString str, int precision);
    QString truncate(QString str, int precision);
};

#endif // CALCULATOR_H
