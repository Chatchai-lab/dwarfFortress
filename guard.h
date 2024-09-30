#ifndef GUARD_H
#define GUARD_H

#include"dwarf.h"

class Guard : public Dwarf
{
public:
    Guard(std::string name, int age, Gender gender, int strength, int stamina);
    void info()override;
    int getStrength() const;

    int getStamina() const;

private:
    int strength;
    int stamina;
};

#endif // GUARD_H
