/* File:      Ghost.cpp
Author:       Zia Animashaun
Date:         11/17/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build a replica of Blizzard's Starcraft.
*/

#include "Ghost.h"
#include <cstdlib>

Ghost::Ghost() : Terran("Ghost", 10) { }
Ghost::Ghost(string name, int health) : Terran(name, health) { }
Ghost::~Ghost() { }
int Ghost::SpecialAttack() {
	cout << GetName() << " performs a sneak attack!" << endl;
	int damage = 2 + rand()%11;
	cout << GetName() << " deals " << damage << " damage!" << endl;
	return damage;
}