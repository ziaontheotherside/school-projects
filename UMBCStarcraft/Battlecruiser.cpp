/* File:      Battlecruiser.cpp
Author:       Zia Animashaun
Date:         11/17/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build a replica of Blizzard's Starcraft.
*/

#include "Battlecruiser.h"
#include <cstdlib>

Battlecruiser::Battlecruiser() : Terran("Battlecruiser", 12) { }
Battlecruiser::Battlecruiser(string name, int health) : Terran(name, health) { }
Battlecruiser::~Battlecruiser() { }
int Battlecruiser::SpecialAttack() {
	cout << GetName() << " uses the Yamato Cannon!" << endl;
	int damage = 3 + rand()%10;
	cout << GetName() << " deals " << damage << " damage!" << endl;
	return damage;
}