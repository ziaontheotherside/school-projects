/* File:      Mutalisk.cpp
Author:       Zia Animashaun
Date:         11/17/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build a replica of Blizzard's Starcraft.
*/

#include "Mutalisk.h"

Mutalisk::Mutalisk() : Zerg("Mutalisk", 7) { }
Mutalisk::Mutalisk(string name, int health) : Zerg(name, health) { }
int Mutalisk::SpecialAttack() {
	cout << GetName() << " blasts you with their attack!" << endl;
	cout << GetName() << " deals 4 damage." << endl;
	return 4;
}