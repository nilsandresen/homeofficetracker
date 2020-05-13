#include "include/menue.h"

template <class T>
void menue(T Arbeitspakete)
{
    cout << "Hallo" << endl;
    bool ende = false;
    int auswahl;
    do
    {
        cout << "was moechten sie tun?\n 1 = werte nach Datum aus\n 2 = werte nach fach aus \n 3 = gib Paket ein \n alles andere = ende" << endl;
        cin >> auswahl;
        switch (auswahl)
        {
        case 1:
            liesArbeitspaketeEin(Arbeitspakete);
            werteNachDatumAus(Arbeitspakete);
            break;
        case 2:
            liesArbeitspaketeEin();
            werteNachFachAus(Arbeitspakete);
            break;
        case 3:
            speichereArbeitspaket(eingabeArbeitspaket(Arbeitspakete));
            break;
        default:
            cout << "Ende";
            ende = true;
            break;
        }
    } while (ende == false);
}