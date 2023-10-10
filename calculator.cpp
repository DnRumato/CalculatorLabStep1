#include "calculator.h"

calculator::calculator(){}

QString calculator::calculate(bool flag, QString firstStr, QString secondStr)
{
    long long firstNum, secondNum, resultNum;
    int firstIndex, secondIndex, dotIndex;
    QString resultStr;

    firstIndex = firstStr.indexOf(".");
    if(firstIndex == -1)
        firstIndex = firstStr.indexOf(",");
    if(firstIndex != -1)
        firstNum = firstStr.left(firstIndex).toLongLong()*pow(10, firstStr.length() - firstIndex - 1) + firstStr.right(firstStr.length() - firstIndex - 1).toLongLong();
    else{
        firstNum = firstStr.toLongLong();
    }

    secondIndex = secondStr.indexOf(".");
    if(secondIndex == -1)
        secondIndex = secondStr.indexOf(",");
    if(secondIndex != -1)
        secondNum = secondStr.left(secondIndex).toLongLong()*pow(10,secondStr.length() - secondIndex - 1) + secondStr.right(secondStr.length() - secondIndex - 1).toLongLong();
    else{
        secondNum = secondStr.toLongLong();
    }


    if(firstIndex > secondIndex){
        dotIndex = firstIndex;
        if(secondIndex != -1)
          secondNum *= pow(10, firstStr.length() - firstIndex - secondStr.length() + secondIndex);
        else
            secondNum *= pow(10, firstStr.length() - firstIndex - 1);
    } else if(secondIndex > firstIndex){
        dotIndex = secondIndex;
        if(firstIndex != -1)
            firstNum *= pow(10, secondStr.length() - secondIndex - firstStr.length() + firstIndex);
        else
            firstNum *= pow(10, secondStr.length() - secondIndex - 1);
    } else dotIndex = firstIndex;


    if(flag) resultNum = firstNum + secondNum;
    else resultNum = firstNum - secondNum;

    resultStr = QString::number(resultNum);
    if(dotIndex != 0 && dotIndex != -1){
       resultStr.insert(dotIndex, ",");
    }
    return resultStr;
}


