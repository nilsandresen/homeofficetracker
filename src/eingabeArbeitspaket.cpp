#include "include/eingabeArbeitspaket.h"

template <class T>
T eingabeArbeitspaket(T paket)
{
    cout << "Datum im Format YYYY/MM/DD ";
    cin >> paket.datum;
    cout << "\nFach: ";
    cin >> paket.fach;
    cout << "Minuten: ";
    cin >> paket.minuten;
    return paket;
}