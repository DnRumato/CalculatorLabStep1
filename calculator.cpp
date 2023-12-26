#include "calculator.h"

bool isValidNumber(const QString& str) {
    QRegExp rxD("^([0-9]{1,3}( [0-9]{3})*(\.[0-9]+)?|[0-9]+(\.[0-9]+)?)$");
    QRegExp rxC("^([0-9]{1,3}( [0-9]{3})*(\,[0-9]+)?|[0-9]+(\,[0-9]+)?)$");
    return (rxD.exactMatch(str) || rxC.exactMatch(str));
}

calculator::calculator(){}

QString calculator::calculate_plus_minus(bool flag, QString firstStr, QString secondStr, int precision)
{
    long long firstNum, secondNum, resultNum;
    int firstIndex, secondIndex, dotIndex;
    QString resultStr;

    if(!(isValidNumber(firstStr) && isValidNumber(secondStr)))
        return "ERROR! INCORRECT NUMBER INPUT!";

    firstStr.remove(' ');
    firstIndex = firstStr.indexOf(".");
    if(firstIndex == -1)
        firstIndex = firstStr.indexOf(",");
    if(firstIndex != -1)
        firstNum = firstStr.left(firstIndex).toLongLong()*pow(10, firstStr.length() - firstIndex - 1) + firstStr.right(firstStr.length() - firstIndex - 1).toLongLong();
    else{
        firstNum = firstStr.toLongLong();
    }

    secondStr.remove(' ');
    secondIndex = secondStr.indexOf(".");
    if(secondIndex == -1)
        secondIndex = secondStr.indexOf(",");
    if(secondIndex != -1)
        secondNum = secondStr.left(secondIndex).toLongLong()*pow(10,secondStr.length() - secondIndex - 1) + secondStr.right(secondStr.length() - secondIndex - 1).toLongLong();
    else{
        secondNum = secondStr.toLongLong();
    }

    if(secondIndex == -1)
        secondIndex = 0;
    else
        secondIndex = secondStr.length() - secondIndex - 1;
    if(firstIndex == -1)
        firstIndex = 0;
    else
        firstIndex = firstStr.length() - firstIndex - 1;

    if(firstIndex < secondIndex){
        dotIndex = secondIndex;
        firstNum *= pow(10, secondIndex - firstIndex);
    }
    else if(secondIndex < firstIndex){
        dotIndex = firstIndex;
        secondNum *= pow(10, firstIndex - secondIndex);
    }
    else
        dotIndex = firstIndex;


    if(flag) resultNum = firstNum + secondNum;
    else resultNum = firstNum - secondNum;

    resultStr = QString::number(resultNum, precision);
    if(dotIndex != 0){
       if(dotIndex < resultStr.length()){
           resultStr.insert(resultStr.length() - dotIndex, ".");
           for(int i = resultStr.indexOf(".") - 3; i > 0; i -= 3){
               resultStr.insert(i, " ");
           }
       }
       else{
           QString temp(dotIndex - resultStr.length() + 1, '0');
           resultStr.insert(0, temp);
           resultStr.insert(1, ".");
       }
    }
    else
        for(int i = resultStr.length() - 3; i > 0; i -= 3){
            resultStr.insert(i, " ");
        }
    resultStr.replace(QRegExp("0+$"), "");
    if (resultStr.endsWith('.')) {
        resultStr.remove(resultStr.length() - 1, 1);
    }
    return resultStr;
}

QString calculator::calculate_divide(QString firstStr, QString secondStr, int precision)
{
    long double firstNum, secondNum, resultNum = 0;
    QString resultStr;

    if(!(isValidNumber(firstStr) && isValidNumber(secondStr)))
        return "ERROR! INCORRECT NUMBER INPUT!";

    firstNum = firstStr.toDouble();
    secondNum = secondStr.toDouble();

    if(secondNum == 0)
        return "ERROR! DIVISION BY ZERO IS NOT POSSIBLE!";
    resultNum = static_cast<long double>(firstNum) / secondNum;
    resultStr = QString::number(resultNum, 'f', precision);
    resultStr.replace(QRegExp("0+$"), "");
    if (resultStr.endsWith('.')) {
        resultStr.remove(resultStr.length() - 1, 1);
    }
    return resultStr;
}

QString calculator::calculate_multiply(QString firstStr, QString secondStr, int precision){
    long long firstNum, secondNum, resultNum = 0;
    int firstIndex, secondIndex, dotIndex = 0;
    QString resultStr;

    if(!(isValidNumber(firstStr) && isValidNumber(secondStr)))
        return "ERROR! INCORRECT NUMBER INPUT!";

    firstStr.remove(' ');
    firstIndex = firstStr.indexOf(".");
    if(firstIndex == -1)
        firstIndex = firstStr.indexOf(",");
    if(firstIndex != -1)
        firstNum = firstStr.left(firstIndex).toLongLong()*pow(10, firstStr.length() - firstIndex - 1) + firstStr.right(firstStr.length() - firstIndex - 1).toLongLong();
    else{
        firstNum = firstStr.toLongLong();
    }

    secondStr.remove(' ');
    secondIndex = secondStr.indexOf(".");
    if(secondIndex == -1)
        secondIndex = secondStr.indexOf(",");
    if(secondIndex != -1)
        secondNum = secondStr.left(secondIndex).toLongLong()*pow(10,secondStr.length() - secondIndex - 1) + secondStr.right(secondStr.length() - secondIndex - 1).toLongLong();
    else
        secondNum = secondStr.toLongLong();


    if(secondIndex == -1)
        secondIndex = 0;
    else
        secondIndex = secondStr.length() - secondIndex - 1;
    if(firstIndex == -1)
        firstIndex = 0;
    else
        firstIndex = firstStr.length() - firstIndex - 1;

    dotIndex = firstIndex + secondIndex;



    resultNum = firstNum * secondNum;
    resultStr = QString::number(resultNum, precision);

    if(dotIndex != 0){
       if(dotIndex < resultStr.length()){
           resultStr.insert(resultStr.length() - dotIndex, ".");
           for(int i = resultStr.indexOf(".") - 3; i > 0; i -= 3){
               resultStr.insert(i, " ");
           }
       }
       else{
           QString temp(dotIndex - resultStr.length() - 1, '0');
           resultStr.insert(0, temp);
           resultStr.insert(1, ".");
       }
    }
    else
        for(int i = resultStr.length() - 3; i > 0; i -= 3){
            resultStr.insert(i, " ");
        }
    resultStr.replace(QRegExp("0+$"), "");
    if (resultStr.endsWith('.')) {
        resultStr.remove(resultStr.length() - 1, 1);
    }
    return resultStr;
}

QString format_number(double num) {
    QLocale locale(QLocale::English);
    locale.setNumberOptions(QLocale::OmitGroupSeparator);
    QString str = locale.toString(num, 'f', 6);
    str.replace(QRegExp("0+$"), "");
    if (str.endsWith('.')) {
        str.remove(str.length() - 1, 1);
    }
    return str;
}

QString calculator::round_math(QString str, int precision) {
    str.remove(' ');
    double num = str.toDouble();
    double shift = std::pow(10, precision);
    return format_number(std::round(num * shift) / shift);
}

QString calculator::round_bank(QString str, int precision) {
    str.remove(' ');
    double num = str.toDouble();
    double shift = std::pow(10, precision);
    if(str.endsWith('5')){
        bool singFlag = (num > 0);
        char temp = str.at(str.length()-2).toLatin1();
        int prev = temp - '0';
        bool prevEven = (!(prev % 2));
        if(singFlag == prevEven){
            return format_number((num*shift - 0.5)/shift);
        }
        else
            return format_number((num*shift + 0.5)/shift);
    }
    else
        return format_number(std::round(num * shift) / shift);
}

QString calculator::truncate(QString str, int precision) {
    str.remove(' ');
    double num = str.toDouble();
    double shift = std::pow(10, precision);
    return format_number(std::trunc(num * shift) / shift);
}

