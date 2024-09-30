#include <iostream>
#include"dwarf.h"
#include"guard.h"
#include"miner.h"
#include"farmer.h"
#include"room.h"
#include"dwarffortress.h"

using namespace std;

int main()
{
    // //#test id generator

    // //#test mit pointer display() Methode
    //     Dwarf* d = new Dwarf("atakan", 12, Gender::male);
    //     Dwarf* d2 = new Dwarf("atakan", 12, Gender::male);
    //     d->display(d);
    //     d->display(d2);

    // //#test der normalen display() Methode
    // Dwarf d("Nikan", 22, Gender::female);
    // d.display();
    // return 0;

    // Guard g("atakan", 22, Gender::male, 14, 12);
    // g.info();

    // //#test addDwarfMethode aus room.cpp
    // Room r(2, Type::Mine);
    // Room r2(1, Type::Dormitory);
    // Miner* m = new Miner("Nikan", 22, Gender::male, 20, 20);
    // Farmer* f = new Farmer("Chai", 24, Gender::male, 200);
    // Guard* g = new Guard("Shk", 23, Gender::male, 12,20);
    // r2.addDwarf(f);
    // r.addDwarf(m);
    // r.addDwarf(g);

    //#test addDwarf aus dwarffortress.cpp
    DwarfFortress d ("chais crip");
    Room* r1 = new Room(2, Type::Farm);
    Room* r2 = new Room(2, Type::Dormitory);
    d.addRoom(r1);
    d.addRoom(r2);
    Farmer* chai = new Farmer("chai", 24, Gender::male, 200);
    d.addDwarf(chai);


}
