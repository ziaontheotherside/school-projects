/* File:      Area.cpp
Author:       Zia Animashaun
Date:         11/17/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build a replica of Blizzard's Starcraft.
*/

#include "Area.h"

Area::Area(int id, string name, string desc, int n, int e, int s, int w) : m_ID(id), m_name(name), m_desc(desc) {
	m_direction[0] = n;
	m_direction[1] = e;
	m_direction[2] = s;
	m_direction[3] = w;
}

string Area::GetName() { return m_name; }
int Area::GetID() { return m_ID; }
string Area::GetDesc() { return m_desc; }
int Area::CheckDirection(char myDirection) {
	switch(myDirection) {
        case 'N': case 'n': return m_direction[0]; break;
		case 'E': case 'e': return m_direction[1]; break;
		case 'S': case 's': return m_direction[2]; break;
		case 'W': case 'w': return m_direction[3]; break;
		default: break;
	}
	return -1;
}
void Area::PrintArea() {
	cout << GetName() << endl << GetDesc() << endl;
	cout << "Possible Exits: ";
	if(m_direction[0] != -1) cout << "N";
	if(m_direction[1] != -1) cout << "E";
	if(m_direction[2] != -1) cout << "S";
	if(m_direction[3] != -1) cout << "W";
	cout << endl;
}