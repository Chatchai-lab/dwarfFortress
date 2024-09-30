#include "guard.h"
using namespace std;

Guard::Guard(std::string name, int age, Gender gender, int strength, int stamina):Dwarf(name, age, gender),strength(strength), stamina(stamina)
{

}

void Guard::info()
{
    cout << "id:" << id << endl;
    cout<< "alter" << age << endl;
    cout<<"Geschlecht: " << enumToString(gender) << endl;
    cout << "Kraft: "<< strength << endl;
    cout << "Ausdauer: " << stamina << endl;
}

int Guard::getStrength() const
{
    return strength;
}

int Guard::getStamina() const
{
    return stamina;
}
