#ifndef FARMER_H
#define FARMER_H

#include"dwarf.h"

class Farmer : public Dwarf
{
public:
    Farmer(std::string name, int age, Gender gender, int farmingskill);
    void info() override;
    int getFarmingskill() const;

private:
    int farmingskill;
};

#endif // FARMER_H
