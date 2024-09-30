#include "miner.h"

using namespace std;

Miner::Miner(std::string name, int age, Gender gender, int miningSkill, int constructionSkill) : Dwarf(name, age, gender), miningSkill(miningSkill), constructionSkill(constructionSkill)
{

}

void Miner::info()
{
    cout << "id:" << id << endl;
    cout<< "alter" << age << endl;
    cout<<"Geschlecht: " << enumToString(gender) << endl;
    cout << "Minen Skill: "<< miningSkill << endl;
    cout << "Konstruktions Skill: " << constructionSkill << endl;
}

int Miner::getMiningSkill() const
{
    return miningSkill;
}

int Miner::getConstructionSkill() const
{
    return constructionSkill;
}
