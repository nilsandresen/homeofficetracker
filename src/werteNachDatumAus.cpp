#include "include/werteNachDatumAus.h"


template <class T>
void werteNachDatumAus(T Arbeitspakete)
{
    string datum = "";
    int summe_minuten = 0;
    for (int i = 0; i < Arbeitspakete.size(); i++)
    {
        if (i == 0)
        {
            cout << Arbeitspakete[0].datum << endl;
        }
        if (Arbeitspakete[i].datum != datum)
        {
            if (i > 0)
            {
                cout << "Summe Minuten = " << summe_minuten << endl;
            }
            cout << "Datum: " << Arbeitspakete[i].datum << endl;
            summe_minuten = Arbeitspakete[i].minuten;
            datum = Arbeitspakete[i].datum;
        }
        else
        {
            summe_minuten += Arbeitspakete[i].minuten;
        }
    }
    cout << "Summe Minuten: " << summe_minuten << endl;
}