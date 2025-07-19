#ifndef REISEZIEL_H
#define REISEZIEL_H

#include <iostream>
#include <vector>
#include <json.hpp>
#include <fstream>
using namespace std;
using json = nlohmann::ordered_json;

class Reiseziel
{
public:
    Reiseziel(string n, string l, vector<string> a);
    Reiseziel(json j);
    json toJson();
    string getName() const;
    string getLand() const;
    vector<string>& getAktivitaeten();

private:
    string name;
    string land;
    vector<string>aktivitaeten;
};

#endif // REISEZIEL_H
