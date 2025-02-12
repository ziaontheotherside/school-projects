/* File:      Zerg.cpp
Author:       Zia Animashaun
Date:         11/17/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build a replica of Blizzard's Starcraft.
*/


#include "Zerg.h"
#include <cstdlib>

Zerg::Zerg() : Entity("Zerg", 10) {}
Zerg::Zerg(string name, int health) : Entity(name, health) { }
int Zerg::Attack() {
	cout << GetName() << " deals 1 point of damage!" << endl;
	return 1;
}