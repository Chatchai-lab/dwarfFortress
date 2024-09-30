#ifndef DWARFFORTRESS_H
#define DWARFFORTRESS_H

#include"room.h"
#include"dwarf.h"
#include"miner.h"
#include"guard.h"
#include"farmer.h"
#include <vector>
#include <cstdlib>  // Für rand() und srand()
#include <ctime>    // Für time()


class DwarfFortress
{
public:
    DwarfFortress(std::string name);
    ~DwarfFortress();
    void addRoom(Room *r);
    std::string roomtype(Room* r);
    void createExample();
    bool addDwarf(Dwarf *d);

    void time();
    //Methoden zum Kinder kriegen
    Dwarf* getChild(Dwarf* woman, Dwarf* man);
    std::vector<Room *> getRooms() const;
    Dwarf* alsoMenInRoom();
    std::string generateName();
    Gender generateGender();
    int farmingSkillKid(Farmer* mother, Farmer* father);
    int miningSkillKid(Miner* mother, Miner* father);
    int constructionSkillKid(Miner* mother, Miner* father);
    int strenghtKid(Guard* mother, Guard* father);
    int staminaKid(Guard* mother, Guard* father);

    //Methoden zum für Tod
    void dwarfDeath();
    int chanceToDie();

private:
    std::string name;
    std::vector<Room*>rooms;
};

#endif // DWARFFORTRESS_H
