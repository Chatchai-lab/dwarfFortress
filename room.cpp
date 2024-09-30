#include "room.h"

using namespace std;

Room::Room(int capacity, Type type) : capacity(capacity) , type(type)
{

}

Room::~Room()
{
    for(Dwarf *d : population){
        delete d;
    }
    population.clear();
}

bool Room::addDwarf(Dwarf *d)
{
    if(currentPopulation() >= capacity){
        throw invalid_argument("Raum ist zu voll");
    }

    if(Farmer* farmer = dynamic_cast<Farmer*>(d)){
        if(type == Type::Farm){
            population.push_back(farmer);
            cout << "Zwerg" << farmer->getName() << " wurde der Farm hinzugefuegt" << endl;
            return true;
        }
    }else if(Guard * guard = dynamic_cast<Guard*>(d)){
        if(type == Type::Gate){
            population.push_back(guard);
            cout << "Zwerg" << guard->getName() << " wurde dem Gate hinzugefuegt" << endl;
            return true;
        }
    }else if(Miner *miner = dynamic_cast<Miner*>(d)){
        if(type == Type::Mine){
            population.push_back(miner);
            cout << "Zwerg " << miner->getName() << " wurde der Mine hinzugefuegt" << endl;
            return true;
        }
    }

    if(type == Type::Dormitory){
        population.push_back(d);
        return true;
    }

    throw invalid_argument("Zwerg konnte dem Raum nicht hinzugefuegt werden");
}

int Room::getCapacity() const
{
    return capacity;
}

Type Room::getType() const
{
    return type;
}

int Room::currentPopulation()
{
    int popsize = population.size();
    return popsize;
}

std::vector<Dwarf *> Room::getPopulation() const
{
    return population;
}
