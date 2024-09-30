#include "dwarffortress.h"

using namespace std;

DwarfFortress::DwarfFortress(std::string name) : name(name)
{

}

DwarfFortress::~DwarfFortress()
{
    for (auto e: rooms){
        delete e;
    }
    rooms.clear();
}



void DwarfFortress::addRoom(Room *r)
{
    rooms.push_back(r);
    cout << "Raum " << roomtype(r) << " wurde hinzugefuegt" << endl;
}

std::string DwarfFortress::roomtype(Room *r)
{
    if (r->getType() == Type::Dormitory) {
        return "Dormitory";
    } else if (r->getType() == Type::Farm) {
        return "Farm";
    } else if (r->getType() == Type::Gate) {
        return "Gate";
    } else if (r->getType() == Type::Mine) {
        return "Mine";
    }

    return "Unknown";
}

void DwarfFortress::createExample()
{
    for(auto e: rooms){
        delete e;
    }
    rooms.clear();

    Room *gate1 = new Room(4, Type::Gate);
    Room *gate2 = new Room(4, Type::Gate);
    Room *mine1 = new Room(30, Type::Mine);
    Room *farm1 = new Room(20, Type::Farm);
    Room *farm2 = new Room(40, Type::Farm);
    Room *dorm1 = new Room(120, Type::Dormitory);
    Room *dorm2 = new Room(200, Type::Dormitory);

    rooms.push_back(gate1);
    rooms.push_back(gate2);
    rooms.push_back(mine1);
    rooms.push_back(farm1);
    rooms.push_back(farm2);
    rooms.push_back(dorm1);
    rooms.push_back(dorm2);



}

bool DwarfFortress::addDwarf(Dwarf *d)
{
    for(auto e : rooms){
        if(e->getType() == Type::Dormitory && e->getCapacity() < e->getPopulation().size()+1){
            cout << "kein freier Platz verfügbar, Zwerg kann nicht aufgenommen werden" <<endl;
            return false;
        }
    }

    if(d->getAge() < 16){
        for(auto e: rooms){
            if(e->getType() == Type::Dormitory){
                e->getPopulation().push_back(d);
                cout << "jugendlicher Zwerg wurde hinzugefügt" << endl;
                return true;
            }
        }
    }

    if(Farmer* farmer = dynamic_cast<Farmer*>(d)){
        for(auto e: rooms){
            if(e->getType() == Type::Farm && e->getCapacity() < e->getPopulation().size()){
                e->getPopulation().push_back(farmer);
                cout << "Farmer hat einen Arbeitsplatz bekommen" << endl;
                for(auto f : rooms){
                    if(f->getType() == Type::Dormitory){
                        f->getPopulation().push_back(farmer);
                        cout << "und hat einen Wohnplatz" << endl;
                        cout << endl;
                        return true;
                    }
                }
            }else if(Miner* miner = dynamic_cast<Miner*>(d)){
                for(auto e: rooms){
                    if(e->getType() == Type::Mine && e->getCapacity() < e->getPopulation().size()+1){
                        e->getPopulation().push_back(miner);
                        cout << "Farmer hat einen Arbeitsplatz bekommen" << endl;
                        for(auto f : rooms){
                            if(f->getType() == Type::Dormitory){
                                f->getPopulation().push_back(miner);
                                cout << "und hat einen Wohnplatz" << endl;
                                cout << endl;
                                return true;
                            }
                        }
                    }
                }
            }else if(Guard* guard = dynamic_cast<Guard*>(d)){
                for(auto e: rooms){
                    if(e->getType() == Type::Gate && e->getCapacity() < e->getPopulation().size()+1){
                        e->getPopulation().push_back(guard);
                        cout << "Guard hat einen Arbeitsplatz bekommen" << endl;
                        for(auto f : rooms){
                            if(f->getType() == Type::Dormitory){
                                f->getPopulation().push_back(guard);
                                cout << "und hat einen Wohnplatz" << endl;
                                cout << endl;
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    for(auto e: rooms){
        if(e->getType() == Type::Dormitory){
            e->getPopulation().push_back(d);
            cout << "Zwerg hat leider keinen Job bekommen, wurde aber einem Dorm hinzugefuegt" <<endl;
            return true;
        }
    }
}







std::vector<Room *> DwarfFortress::getRooms() const
{
    return rooms;
}

void DwarfFortress::time()
{

    for(auto e: rooms){
        Type t = e->getType();
        if(t == Type::Dormitory){
            for(auto f: e->getPopulation()){
                f->getAge()+1;
                if(f->getGender() == Gender::female){
                    Dwarf* m = alsoMenInRoom();
                    Dwarf* kid= getChild(f,m);
                    e->getPopulation().push_back(kid);
                }
            }
        }
    }
}


Dwarf* DwarfFortress::getChild(Dwarf* woman, Dwarf* man)
{
    Farmer* femaleFarmer = dynamic_cast<Farmer*>(woman);
    Farmer* maleFarmer = dynamic_cast<Farmer*>(man);
    Miner* femaleMiner = dynamic_cast<Miner*>(woman);
    Miner* maleMiner = dynamic_cast<Miner*>(man);
    Guard* femaleGuard = dynamic_cast<Guard*>(woman);
    Guard* maleGuard = dynamic_cast<Guard*>(man);

    if(femaleFarmer && maleFarmer){
        Farmer* kid = new Farmer(generateName(),1,generateGender(), farmingSkillKid(femaleFarmer, maleFarmer));
        cout << "Farmer kind wurde geboren" << endl;
        return kid;
    }else if(femaleMiner && maleMiner){
        Miner* kid = new Miner(generateName(),1,generateGender(), miningSkillKid(femaleMiner, maleMiner), constructionSkillKid(femaleMiner, maleMiner));
        cout << "Miner kind wurde geboren" << endl;
        return kid;
    }else if(femaleGuard && maleGuard){
        Guard* kid = new Guard(generateName(),1,generateGender(), strenghtKid(femaleGuard, maleGuard), staminaKid(femaleGuard, maleGuard));
        cout << "Guard kind wurde geboren" << endl;
        return kid;
    }else{
        cout << "Kind konnte nicht gemacht werden" << endl;
        return nullptr;
    }
}



Dwarf* DwarfFortress::alsoMenInRoom()
{
    for(auto e : rooms){
        for(auto f: e->getPopulation()){
            Gender g = f->getGender();
            if(g == Gender::male){
                return f;
            }
            else{
                cout << "Es befindet sich kein Mann in dem Raum" <<endl;
                return nullptr;
            }
        }
    }
}

std::string DwarfFortress::generateName()
{
    std::vector<std::string> firstNames = {"Aragorn", "Gimli", "Legolas", "Frodo", "Samwise", "Boromir", "Thorin", "Bilbo"};
    std::vector<std::string> lastNames = {"Eichenwald", "Schmied", "Hammerfaust", "Schildträger", "Lichtbringer", "Starkarm"};

    std::srand(static_cast<unsigned>(std::time(0)));

    std::string firstName = firstNames[rand() % firstNames.size()];
    std::string lastName = lastNames[rand() % lastNames.size()];
    return firstName + " " + lastName;
}


Gender DwarfFortress::generateGender()
{
    std::srand(static_cast<unsigned>(std::time(0)));

    int randomValue = rand() % 2;  // Gibt entweder 0 oder 1 zurück

    if(randomValue==0){
        return Gender::female;
    }else{
        return Gender::male;
    }
}



int DwarfFortress::farmingSkillKid(Farmer* mother, Farmer* father)
{
    int m= mother->getFarmingskill();
    int f= father->getFarmingskill();
    int kidFarmingSkill = (m+f)/2 + 1;
    return kidFarmingSkill;
}

int DwarfFortress::miningSkillKid(Miner *mother, Miner *father)
{
    int m= mother->getMiningSkill();
    int f= father->getMiningSkill();
    int kidMiningSkill = (m+f)/2 + 1;
    return kidMiningSkill;
}

int DwarfFortress::constructionSkillKid(Miner *mother, Miner *father)
{
    int m= mother->getConstructionSkill();
    int f= father->getConstructionSkill();
    int kidConstructionSkill = (m+f)/2 + 1;
    return kidConstructionSkill;
}

int DwarfFortress::strenghtKid(Guard *mother, Guard *father)
{
    int m= mother->getStrength();
    int f= father->getStrength();
    int kidStrength = (m+f)/2 + 1;
    return kidStrength;
}

int DwarfFortress::staminaKid(Guard *mother, Guard *father)
{
    int m= mother->getStamina();
    int f= father->getStamina();
    int kidStamina = (m+f)/2 + 1;
    return kidStamina;
}

void DwarfFortress::dwarfDeath()
{
    std::srand(static_cast<unsigned>(std::time(0)));

    int randomValue = rand() % 100;

    if(randomValue < chanceToDie()){
        for(auto e : rooms){
            for(auto f: e->getPopulation()){
                delete f;
            }
        }
    }
}



int DwarfFortress::chanceToDie()
{
    for(auto e : rooms){
        for(auto f: e->getPopulation()){
            int dieChance = f->getAge();
            return dieChance;
        }
    }
}

