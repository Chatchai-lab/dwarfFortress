#include "farmer.h"
using namespace std;

Farmer::Farmer(std::string name, int age, Gender gender, int farmingskill) : Dwarf(name, age, gender), farmingskill(farmingskill)
{

}

void Farmer::info()
{
    cout << "id:" << id << endl;
    cout<< "alter" << age << endl;
    cout<<"Geschlecht: " << enumToString(gender) << endl;
    cout << "Farmingskill: "<< farmingskill << endl;
}

int Farmer::getFarmingskill() const
{
    return farmingskill;
}
