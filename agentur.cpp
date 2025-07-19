#include "agentur.h"

Agentur::Agentur() {}

Agentur::~Agentur() {}

void Agentur::laden(string dateiname)
{
    ifstream in(dateiname);
    if(!in.is_open()) {
        cerr << "Datei " << dateiname << " konnte nicht geoeffnet werden!" << endl;
        return;
    }

    json j;
    in >> j;

    for (auto& reiseziel : j["reiseziele"]) {
        Reiseziel neuerZiel(reiseziel);
        reiseziele.push_back(neuerZiel);
    }

    in.close();
    cout << "Daten erfolgreich geladen" << endl;
}

void Agentur::speichern(string dateiname)
{
    ofstream out(dateiname);
    if(!out.is_open()) {
        cerr << "Datei " << dateiname << " konnte nicht geoeffnet werden!" << endl;
        return;
    }

    json j;

    for (auto& ziel : reiseziele) {
        j["reiseziele"].push_back(ziel.toJson());
    }

    out << j.dump(2);

    out.close();
    cout << "Daten erfolgreich gespeichert" << endl;
}

bool Agentur::reisezielLoeschen(string reiseziel_name)
{
    for (size_t i=0; i<reiseziele.size(); i++) {
        if(reiseziel_name == reiseziele[i].getName()){
            reiseziele.erase(reiseziele.begin() + i);
            return true;
        }
    }
    return false;
}

bool Agentur::aktivitaetHinzufuegen(string reiseziel_name, string aktivitaet)
{
    for (auto& ziel : reiseziele) {
        if(ziel.getName() == reiseziel_name) {
            ziel.getAktivitaeten().push_back(aktivitaet);
            return true;
        }
    }
    return false;
}

bool Agentur::aktivitaetLoeschen(string reiseziel_name, string aktivitaet)
{
    for (auto& ziel : reiseziele) {
        if(ziel.getName() == reiseziel_name) {
            for (size_t i=0; i<ziel.getAktivitaeten().size(); i++) {
                if(ziel.getAktivitaeten()[i] == aktivitaet) {
                    ziel.getAktivitaeten().erase(ziel.getAktivitaeten().begin() + i);
                    return true;
                }
            }
        }
    }
    return false;
}

vector<Reiseziel>& Agentur::getReiseziele()
{
    return reiseziele;
}
