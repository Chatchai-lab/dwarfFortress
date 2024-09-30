#ifndef DWARF_H
#define DWARF_H

#include<string>
#include<iostream>

enum class Gender{
    male,
    female
};

class Dwarf
{
public:
    Dwarf(std::string name, int age, Gender gender);
    virtual ~Dwarf() = default;
    int generateID();
    int getId() const;
    //Methoden der Klausur
    virtual void info() = 0;
    //eigene Methoden
    void display();
    void displayMitPointer(Dwarf *d);
    std::string enumToString(Gender g);
    std::string getName() const;
    Gender getGender() const;
    int getAge() const;
protected:
    const int id;
    std::string name;
    int age;
    Gender gender;

};

#endif // DWARF_H
