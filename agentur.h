#ifndef AGENTUR_H
#define AGENTUR_H

#include "reiseziel.h"

class Agentur
{
public:
    Agentur();
    ~Agentur();
    void laden(string dateiname);
    void speichern(string dateiname);
    bool reisezielLoeschen(string reiseziel_name);
    bool aktivitaetHinzufuegen(string reiseziel_name, string aktivitaet);
    bool aktivitaetLoeschen(string reiseziel_name, string aktivitaet);
    vector<Reiseziel>& getReiseziele();

private:
    vector<Reiseziel> reiseziele;
};

#endif // AGENTUR_H
