#include "stringHelper.h"

string stringHelper::deleteSymbol(string data, char symbol)
{
    for (int i = 0; i < data.size(); i++)
        if (data[i] == symbol) {
            data.replace(i, 1, "");
            i--;
        }
    return data;
}
