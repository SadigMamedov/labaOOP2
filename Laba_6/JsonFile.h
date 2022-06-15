#ifndef JSONFILE_H
#define JSONFILE_H

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "jsonException.h"
#include "fileManager.h"
#include "stringHelper.h"
#include "JsonFormatChecker.h"

using namespace std;

class JsonFile
{
private:    
    string data;

public:
    string getData();

    void fillData(string jsonData);
};


#endif // JSONFILE_H
