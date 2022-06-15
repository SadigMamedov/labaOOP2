#include "JsonFormatChecker.h"

void JsonFormatChecker::startCheck(string data)
{
    set<string> setBase;
    //checkBrackets(data);
    for (int num = 1; num < data.size() - 1; num++)
    {
        checkNameElement(data, &num, &setBase);
        checkColon(data, &num);
        elementProcessingAlgorithmFields(data, &num, &setBase, '}');
        num--;
    }
}

void JsonFormatChecker::checkNameElement(string data, int* num, set<string>* setBase)
{
    if (data[*num] == '\"')
        checkName(data, num, setBase);
    else
        throw jsonException("Missing character \"", data.substr(0, *num));
}

void JsonFormatChecker::elementProcessingAlgorithmFields(string data, int* num, set<string>* setBase, char symbol)
{
    if (data[*num] == '\"') {
        checkName(data, num, setBase);
        if (!checkEnd(data, num, symbol))
            checkComma(data, num);
    } else if (numbers.find(data[*num]) != -1) {
        checkNumbers(data, num);
        if (!checkEnd(data, num, symbol))
            checkComma(data, num);
    } else if (conditionBool(data, num)) {
        if (!checkEnd(data, num, symbol))
            checkComma(data, num);
    } else if (data[*num] == '[') {
        set<string> newSet;
        checkArray(data, num, &newSet);
        if (!checkEnd(data, num, symbol))
            checkComma(data, num);
    } else if (data[*num] == '{') {
        set<string> newSet;
        checkObject(data, num, &newSet);
        if (!checkEnd(data, num, symbol))
            checkComma(data, num);
    } else
        throw jsonException("The file is incorrect", data.substr(0, *num));
}

bool JsonFormatChecker::checkEnd(string data, int* num, char symbol)
{
    return data[*num] == symbol ? true : false;
}

void JsonFormatChecker::checkObject(string data, int* num, set<string>* setBase)
{
    *num += 1;
    while (data[*num] != '}') {
        checkNameElement(data, num, setBase);
        checkColon(data, num);
        elementProcessingAlgorithmFields(data, num, setBase, '}');
    }
    *num += 1;
}

void JsonFormatChecker::checkArray(string data, int* num, set<string>* setBase)
{
    *num += 1;
    while (data[*num] != ']') {
        elementProcessingAlgorithmFields(data, num, setBase, ']');
    }
    *num += 1;
}

bool JsonFormatChecker::conditionBool(string data, int* num)
{
    bool flag = false;
    if (data.substr(*num, 4) == "true" || data.substr(*num, 4) == "null") {
        *num += 4;
        flag = true;
    } else if (data.substr(*num, 5) == "false") {
        *num += 5;
        flag = true;
    }
    return flag;
}

void JsonFormatChecker::checkNumbers(string data, int* num)
{
    while (data[*num] != ',' && data[*num] != ']' && data[*num] != '}') {
        if (numbers.find(data[*num]) == -1) {
            throw jsonException("Incorrect number format", data.substr(0, *num));
        }
        *num += 1;
    }
}

void JsonFormatChecker::checkComma(string data, int* num)
{
    if (data[*num] != ',')
        throw jsonException("Missing character ,", data.substr(0, *num));
    else
        *num += 1;
}

void JsonFormatChecker::checkColon(string data, int* num)
{
    if (data[*num] != ':')
        throw jsonException("Missing character :", data.substr(0, *num));
    *num += 1;
}

void JsonFormatChecker::checkName(string data, int* num, set<string>* set)
{
    if (data[*num + 1] == '\"')
        throw jsonException("The name of the object is not set", data.substr(0, *num));
    if (set->count(data.substr(*num + 1, data.find("\"", *num + 1) - *num - 1)))
        throw jsonException("The name of the object is repeated", data.substr(0, *num));
    set->insert(data.substr(*num + 1, data.find("\"", *num + 1) - *num - 1));
    *num += data.find("\"", *num + 1) - *num + 1;
}

/*void JsonFormatChecker::checkBrackets(string data)
{
    if (data[0] != '{' || data[data.size() - 1] != '}')
        throw jsonException("Missing the initial brackets {}", "");

}*/
