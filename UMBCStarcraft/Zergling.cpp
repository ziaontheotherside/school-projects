/* File:      Zergling.cpp
Author:       Zia Animashaun
Date:         11/17/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build a replica of Blizzard's Starcraft.
*/

#include "Zergling.h"

Zergling::Zergling() : Zerg("Zergling", 3) { }
Zergling::Zergling(string name, int health) : Zerg(name, health) { }
int Zergling::SpecialAttack() {
	cout << GetName() << " scratches at you ferociously!" << endl;
	cout << GetName() << " deals 1 damage." << endl;
	return 1;
}