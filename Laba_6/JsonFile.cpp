#include "JsonFile.h"

string JsonFile::getData()
{
    return this->data;
}

void JsonFile::fillData(string jsonData)
{
    this->data = jsonData;
}
