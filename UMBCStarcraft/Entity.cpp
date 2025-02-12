/* File:      Entity.cpp
Author:       Zia Animashaun
Date:         11/17/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build a replica of Blizzard's Starcraft.
*/

#include "Entity.h"

Entity::Entity() { m_health = 0; }
Entity::Entity(string name, int health) : m_name(name), m_health(health) { }
Entity:: ~Entity (){}
string Entity::GetName() { return m_name; }
int Entity::GetHealth() { return m_health; }
void Entity::SetName(string name) { m_name = name; }
void Entity::SetHealth(int health) { m_health = health; }

ostream& operator<<(ostream& out, Entity& entity) {
	out << "Name: " << entity.m_name << endl;
	out << "Health: " << entity.m_health << endl;
	return out;
}