
/* File:      Marine.cpp
Author:       Zia Animashaun
Date:         11/17/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build a replica of Blizzard's Starcraft.
*/

#include "Marine.h"
#include <cstdlib>

Marine::Marine() : Terran("Marine", 8) { }
Marine::Marine(string name, int health) : Terran(name, health) { }
Marine::~Marine() { }
int Marine::SpecialAttack() {
	int damage = 1 + rand()%8;
	cout << GetName() << " spins up doing GATLING DAMAGE!" << endl;
	cout << GetName() << " deals " << damage << " damage!" << endl;
	return damage;
}