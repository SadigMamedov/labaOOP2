#ifndef JSONEXCEPTION_H
#define JSONEXCEPTION_H

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <stdexcept>
#include <iostream>

using namespace std;

class jsonException: public invalid_argument
{
public:
    jsonException(string msg):invalid_argument(msg)
    {

    }
    jsonException(string msg, string data):invalid_argument(msg)
    {
        dataException = data;
    }
    string getDataException()
    {
        return dataException;
    }
private:
    string dataException;
};

#endif // JSONEXCEPTION_H
