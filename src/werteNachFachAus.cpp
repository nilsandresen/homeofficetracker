#include "include/werteNachFachAus.h"

template <class T>
void werteNachFachAus(T Arbeitspakete)
{
    string fach = "";
    int summe_minuten = 0;

    struct ARBEITSPAKET
    {
    string datum;
    string fach;
    int minuten;
    };
    ARBEITSPAKET hilf;
    for (int i = 0; i < Arbeitspakete.size() - 1; i++)
    {
        for (int j = 0; j < Arbeitspakete.size() - i - 1; j++)
        {
            if (Arbeitspakete[i].fach > Arbeitspakete[i + 1].fach)
            {
                hilf = Arbeitspakete[i];
                Arbeitspakete[i] = Arbeitspakete[i + 1];
                Arbeitspakete[i + 1] = hilf;
            }
        }
    }
    for (int i = 0; i < Arbeitspakete.size(); i++)
    {

        if (Arbeitspakete[i].fach != fach)
        {
            if (i > 0)
            {
                cout << "Summe in Minuten: " << summe_minuten << endl;
            }
            cout << "Fach: " << Arbeitspakete[i].fach << endl;
            summe_minuten = Arbeitspakete[i].minuten;
            fach = Arbeitspakete[i].fach;
        }
        else
        {
            summe_minuten += Arbeitspakete[i].minuten;
        }
    }
    cout << "Summe Minuten: " << summe_minuten << endl;
}