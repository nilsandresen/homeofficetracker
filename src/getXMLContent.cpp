#include "include/getXMLContent.h"

string getXMLContent(string line, string tagName, int n)
{
    string content = "";
    int i = 0;
    int pos_0 = 0;
    int pos_1 = 0;
    int pos_2 = 0;

    do
    {
        if (i > 0)
            pos_0++;
        pos_0 = line.find("<" + tagName + ">", pos_0);
        i++;
    } while (pos_0 != string::npos && i < n);

    if (pos_0 != string::npos)
    {
        pos_1 = pos_0 + 2 + tagName.length();
        pos_2 = line.find("</" + tagName + ">", pos_1);
        if (pos_2 != string::npos)
            content = line.substr(pos_1, pos_2 - pos_1);
    }
    return content;
}