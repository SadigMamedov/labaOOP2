#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#define BUFF_SIZE 300

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "jsonException.h"

using namespace std;

class fileManager
{
public:
    string readFile(char* filename);
};

#endif // FILEMANAGER_H
