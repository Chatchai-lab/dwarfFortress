#ifndef ROOM_H
#define ROOM_H

#include"farmer.h"
#include"guard.h"
#include"miner.h"
#include"dwarf.h"

#include<vector>

enum class Type{
    Gate,
    Mine,
    Farm,
    Dormitory
};

class Room
{
public:
    Room(int capacity, Type type);
     ~Room();
    bool addDwarf(Dwarf * d);
    int getCapacity() const;
    Type getType() const;
    int currentPopulation();
    std::vector<Dwarf *> getPopulation() const;

private:
    int capacity;
    Type type;
    std::vector<Dwarf*>population;
};

#endif // ROOM_H
