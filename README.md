# Home Office Tracker

### Klasse: AIT90

### Lernfeld 6: Entwickeln und Bereitstellen von Anwendungssystemen

**Abgabe: 27.05.2020**

Schreiben Sie ein Programm, das hilft, Ihren **Arbeitsaufwand für die Berufsschule** zu tracken.

1. Das Programm speichert die Daten Ihrer Arbeitspakete mit Datum, Fach und Anzahl Minuten in
ener **XML-ähnlichen Struktur** in einer Datei.
2. Die Datei heißt "**Arbeitspakete.xml**" und liegt auch in SchulCommSy.
3. Im Programm werden die Daten eines Arbeitspaketes in einer Variablen eines **Strukturdatentyp
"Arbeitspaket"** mit den Elementen **datum (string), fach (string) minuten (int)** gespeichert.
4. Die Daten sind **nach Datum sortiert** gespeichert. Auch Eingaben müssen immer mit gleichem
Datum oder einem höheren Datum angelegt werden. Es ist keine rückwirkende EIngabe möglich.
5. Das Programm soll ein **Menü** enthalten, das in drei Funktionen verzweigt:

   a. Auswerten der Arbeitszeit nach Datum

   b. Auswerten der Arbeitszeit nach Fach

   c. Eingabe neuer Arbeitspakete

6. Bei den ersten beiden Funktionen wird zunächst der **Dateiinhalt eingelesen** und die Daten in einen
**Vector von Arbeitspaketen** geschrieben.
7. Für das Parsen der xml-Datei steht Ihnen bereits die Funktion **"getXMLElement()"** zur Verfügung,
Diese müssen Sie in Ihre Code-Datei kopieren. Diese übernimmt drei Parameter:


   a. einen string, der die xml-Daten enthält 


   b. einen string, der den Namen des Tags enthält ("datum", "fach" oder "minuten")


   c. eine int-Zahl "n", die das n-te Auftreten des jeweiligen XML-Elements bezeichnet. Ist z.B. n
= 3, wird das dritte Auftreten des jeweiligen Elements ausgelesen.


8. Für die Auswertung nach Fach muss der Vektor erst einmal **nach Fach sortiert** werden. Das erfolgt
mit dem Algorithmus **"Bubble Sort"**.