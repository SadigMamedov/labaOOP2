#ifndef JSONFORMATCHECKER_H
#define JSONFORMATCHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <set>

#include "jsonException.h"

using namespace std;

class JsonFormatChecker
{
private:
    string numbers = "1234567890eE.-";

    void checkBrackets(string data);

    void checkName(string data, int* num, set<string>* set);

    void checkComma(string data, int* num);

    void checkColon(string data, int* num);

    void checkNumbers(string data, int* num);

    bool conditionBool(string data, int* num);

    void checkArray(string data, int* num, set<string>* set);

    void checkObject(string data, int* num, set<string>* set);

    bool checkEnd(string data, int* num, char symbol);

    void elementProcessingAlgorithmFields(string data, int* num, set<string>* set, char symbol);

    void checkNameElement(string data, int* num, set<string>* set);
public:
    void startCheck(string data);
};

#endif // JSONFORMATCHECKER_H
