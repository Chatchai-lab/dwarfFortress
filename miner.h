#ifndef MINER_H
#define MINER_H
#include"dwarf.h"

class Miner : public Dwarf
{
public:
    Miner(std::string name, int age, Gender gender, int miningSkill, int constructionSkill);
    void info()override;
    int getMiningSkill() const;

    int getConstructionSkill() const;

private:
    int miningSkill;
    int constructionSkill;
};

#endif // MINER_H
