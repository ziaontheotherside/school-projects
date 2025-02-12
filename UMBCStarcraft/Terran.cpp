/* File:      Terran.cpp
Author:       Zia Animashaun
Date:         11/17/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build a replica of Blizzard's Starcraft.
*/

#include "Terran.h"
#include <cstdlib>

Terran::Terran() : Entity("Terran", 10) { }
Terran::~Terran() { }
Terran::Terran(string name, int health) : Entity(name, health) { }
int Terran::Attack() {
	int damage = 1 + rand()%6;
	cout << GetName() << " attacks dealing " << damage << " damage." << endl;
	return damage;
}

int Terran::SpecialAttack() {
    cout << "Terrans have no special attack." << endl;
    return 0;
}
