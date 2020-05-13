#include "include/speichereArbeitspaket.h"
template <class T> 
void speichereArbeitspaket(T paket)
{
    fstream datei;
    datei.open("Arbeitspakete.xml", ios::in | ios::out);
    if (datei.good())
    {
        datei.seekg(-6, datei.end); // Cursor vor das schließende "</xml>" setzen
        datei << "<data><datum>" + paket.datum + "</datum>";
        datei << "<fach>" + paket.fach + "</fach>";
        datei << "<minuten>" << paket.minuten << "</minuten></data></xml>";
        datei.close();
    }
}