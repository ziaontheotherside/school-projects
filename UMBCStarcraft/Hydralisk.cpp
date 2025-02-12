/* File:      Hydralisk.cpp
Author:       Zia Animashaun
Date:         11/17/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build a replica of Blizzard's Starcraft.
*/

#include "Hydralisk.h"

Hydralisk::Hydralisk() : Zerg("Hydralisk", 7) { }
Hydralisk::Hydralisk(string name, int health) : Zerg(name, health) { }
int Hydralisk::SpecialAttack() {
	cout << GetName() << " sprays you with deadly acid!" << endl;
	cout << GetName() << " deals 2 damage." << endl;
	return 2;
}