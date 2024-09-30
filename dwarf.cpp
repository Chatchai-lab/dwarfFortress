#include "dwarf.h"
using namespace std;


Dwarf::Dwarf(std::string name, int age, Gender gender) : id(generateID()), name(name), age(age), gender(gender)
{

}

int Dwarf::generateID()
{
    static int id = 0;
    id++;
    return id;
}

int Dwarf::getId() const
{
    return id;
}

void Dwarf::display()
{
    cout << id;
}

void Dwarf::displayMitPointer(Dwarf *d)
{
    cout << d->getId();
}

std::string Dwarf::enumToString(Gender g)
{
    if(g==Gender::female){
        return "female";
    }else{
        return "male";
    }
}

std::string Dwarf::getName() const
{
    return name;
}

Gender Dwarf::getGender() const
{
    return gender;
}

int Dwarf::getAge() const
{
    return age;
}



