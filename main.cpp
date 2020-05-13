#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool ende = false;

struct ARBEITSPAKET
{
    string datum;
    string fach;
    int minuten;
};
vector<ARBEITSPAKET> Arbeitspakete;
void menue();
void liesArbeitspaketeEin();
ARBEITSPAKET eingabeArbeitspaket();
void speichereArbeitspaket(ARBEITSPAKET paket);
void werteNachDatumAus(string datum);
void werteNachFachAus();
string getXMLContent(string line, string tagName, int n);

int summe_minuten = 0;
int main()
{
    menue();
    return 0;
}

void menue()
{
    cout << "Hallo" << endl;
    ende = false;
    int auswahl;
    do
    {
        cout << "was moechten sie tun?\n 1 = werte nach Datum aus\n 2 = werte nach fach aus \n 3 = gib Paket ein \n alles andere = ende" << endl;
        cin >> auswahl;
        switch (auswahl)
        {
        case 1:
            liesArbeitspaketeEin();
            werteNachDatumAus("2020/05/06");
            break;
        case 2:
            liesArbeitspaketeEin();
            werteNachFachAus();
            break;
        case 3:
            speichereArbeitspaket(eingabeArbeitspaket());
            break;
        default:
            cout << "Ende";
            ende = true;
            break;
        }
    } while (ende == false);
}

ARBEITSPAKET eingabeArbeitspaket()
{
    ARBEITSPAKET paket;
    cout << "Datum im Format YYYY/MM/DD ";
    cin >> paket.datum;
    cout << "\nFach: ";
    cin >> paket.fach;
    cout << "Minuten: ";
    cin >> paket.minuten;
    return paket;
}

void speichereArbeitspaket(ARBEITSPAKET paket)
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

void liesArbeitspaketeEin()
{
    Arbeitspakete.clear();
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
        ARBEITSPAKET paket;
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

void werteNachDatumAus(string datum = "")
{
    summe_minuten = 0;
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

void werteNachFachAus()
{
    string fach = "";
    summe_minuten = 0;
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