#include "fileManager.h"

string fileManager::readFile(char* filename)
{
    FILE* file = fopen(filename, "r");
    if (!file)
        throw jsonException("Could not open the file");
    string data = "";
    char line[BUFF_SIZE];
    while (fgets(line, BUFF_SIZE, file))
    {
        data.append(line);
    }
    fclose(file);
    return data;
}
