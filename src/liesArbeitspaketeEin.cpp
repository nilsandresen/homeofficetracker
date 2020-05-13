#include "include/liesArbeitspaketeEin.h"

template <class T>
void liesArbeitspaketeEin(T Arbeitspakete)
{

    struct ARBEITSPAKET
    {
        string datum;
        string fach;
        int minuten;
    };
    ARBEITSPAKET paket;
    // Arbeitspakete.clear();
    string data;
    string inhalt;
    fstream datei;
    datei.open("Arbeitspakete.xml", ios::in);
    if (datei.good())
    {
        datei >> data;
        inhalt = getXMLContent(data, "xml", 1);
    }
    datei.close();
    int i = 1;
    do
    {
        data = getXMLContent(inhalt, "data", i);
        if (data != "")
        {
            paket.datum = getXMLContent(data, "datum", 1);
            paket.fach = getXMLContent(data, "fach", 1);
            // stoi für umwandlung zu int
            paket.minuten = stoi(getXMLContent(data, "minuten", 1));
            Arbeitspakete.push_back(paket);
        }
        i++;
    } while (data != "");
}