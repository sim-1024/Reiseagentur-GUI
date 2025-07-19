#include "reiseziel.h"

Reiseziel::Reiseziel(string n, string l, vector<string> a)
    : name(n), land(l), aktivitaeten(a) {}

Reiseziel::Reiseziel(json j)
{
    name = j["name"];
    land = j["land"];
    aktivitaeten = j["aktivitaeten"].get<vector<string>>();
}

json Reiseziel::toJson()
{
    json j;

    j["name"] = this->name;
    j["land"] = this->land;
    j["aktivitaeten"] = this->aktivitaeten;

    return j;
}

string Reiseziel::getName() const
{
    return name;
}

string Reiseziel::getLand() const
{
    return land;
}

vector<string>& Reiseziel::getAktivitaeten()
{
    return aktivitaeten;
}
