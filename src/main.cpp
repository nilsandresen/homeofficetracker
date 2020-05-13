#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "include/menue.h"

using namespace std;

int main()
{
    struct ARBEITSPAKET
    {
        string datum;
        string fach;
        int minuten;
    };
    vector<ARBEITSPAKET> Arbeitspakete;

    menue(Arbeitspakete);
    return 0;
}