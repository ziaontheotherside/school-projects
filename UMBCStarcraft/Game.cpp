/* File:      Game.cpp
Author:       Zia Animashaun
Date:         11/17/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build a replica of Blizzard's Starcraft.
*/


#include "Game.h"

// Name: Game() - Default Constructor
// Description: Creates a new Game
// Preconditions: None
// Postconditions: Initializes all game variables to defaults (constants)
// including rests, specials, curArea, filename, curZerg (nullptr), and starting wins
Game::Game() {
	m_filename = FILE_NAME;
	m_curArea = START_AREA;
	m_numRests = NUM_RESTS;
	m_numSpecial = NUM_SPECIAL;
	m_wins = START_WINS;
	m_curZerg = nullptr;
	m_myTerran = nullptr;
}

Game::Game(string filename) : Game() {
	m_filename = filename;
}

Game::~Game() {
	delete m_curZerg;
	delete m_myTerran;
	for(Area* a : m_myMap) {
		delete a;
	}
}

void Game::LoadMap() {
	ifstream in(m_filename);
    cout << m_filename << endl;
	int map_id;
	string map_name, map_desc;
	int n, e, s, w;
    if (! in){
        cout << "Could not load the map" << " " << m_filename << endl;
        return;
    }
	while(in) {
		if (!(in >> map_id))break;
		in.ignore(); //Skip |
		getline(in, map_name, DELIMITER);
		/* in.ignore(); //Skip | */
		getline(in, map_desc, DELIMITER);
		/* in.ignore(); //Skip | */
		in >> n;
		in.ignore(); //Skip |
		in >> e;
		in.ignore(); //Skip |
		in >> s;
		in.ignore(); //Skip |
		in >> w;
		in.ignore(); //Skip |
		Area* a = new Area(map_id, map_name, map_desc, n, e, s, w);
		m_myMap.push_back(a);
        cout << "Loaded map" << " " << map_id << endl;
	}
}

void Game::TerranCreation() {
	cout << "Terran Name: ";
	string name;
	getline(cin, name);
	cout << "Select a class" << endl;
	cout << "1. Marine\n2. Ghost\n3. Battlecruiser\n4. No Class" << endl;
	int choice;
	do {
		cin >> choice;
		if(choice < 1 || choice > 4) {
			cout << "Invalid Selection, please choose again." << endl;
		}
	} while(choice < 1 || choice > 4);
	switch(choice) {
		case 1: {
			m_myTerran = static_cast<Entity*>(new Marine(name, MARINE_HEALTH));
			break;
		}
		case 2: {
			m_myTerran = static_cast<Entity*>(new Ghost(name, GHOST_HEALTH));
			break;
		}
		case 3: {
			m_myTerran = static_cast<Entity*>(new Battlecruiser(name, BATTLECRUISER_HEALTH));
			break;
		}
		case 4: {
			m_myTerran = static_cast<Entity*>(new Terran(name, TERRAN_HEALTH));
			break;
		}
	}
}

void Game::StartGame() {
	cout << "Welcome to UMBC Starcraft!" << endl;
	srand(time(0));
	LoadMap();
	TerranCreation();
	Action();
}

void Game::Action() {
    cout << "Action started" << endl;
	bool playing = true, continueMenu = false;
	int choice;
	do { //outer game loop
		//Note: new zergling is only called on movement when continueMenu=false
		Area& loc = *m_myMap[m_curArea];
		loc.PrintArea();
		m_curZerg = RandomZerg();
		do { //inner game loop: continue actions until movement or quit
			cout << "What would you like to do?" << endl;
			cout << "1. Look\n2. Move\n3. Attack Zerg\n4. Rest\n5. Check Stats\n6. Quit\n";
			continueMenu = true;
			cin >> choice;
			switch(choice) {
				case 1: {
					loc.PrintArea();
					break;
				}
				case 2: {
					Move();
					continueMenu = false;
					break;
				}
				case 3: {
					Attack();
					//force game to end if died
					if(m_myTerran->GetHealth() < 1) {
						playing = false;
						continueMenu = false;
					}
					break;
				}
				case 4: {
					Rest();
					break;
				}
				case 5: {
					Stats();
					break;
				}
				case 6: {
					playing = false;
					continueMenu = false;
					break;
				}
				default: {
					cout << "Invalid Choice, please try again." << endl;
					break;
				}
			}
		} while(continueMenu);
	} while(playing);
	cout << "Please play again!\n Good bye!\n";
}

void Game::Move() {
	auto a = m_myMap.at(m_curArea);
	do {
		cout << "Which direction? (N E S W): ";
		char c;
		cin >> c;
		int dir = a->CheckDirection(c);
		if(dir == -1) {
			cout << "Invalid direction.\n";
		}
		else {
			m_curArea = dir;
			break;
		}
	} while(true);
}

void Game::Attack() {
	if(m_curZerg == nullptr) {
		cout << "There is nothing here to attack.\n";
		return;
	}
	int attackChoice;
	while(m_myTerran->GetHealth() > 0 && m_curZerg->GetHealth() > 0) {
		do {
			cout << "1. Normal Attack\n2. Special Attack\n";
			cin >> attackChoice;
			if(attackChoice == 1) {
				int dmg = m_myTerran->Attack();
				m_curZerg->SetHealth(m_curZerg->GetHealth()-dmg);
				break;
			}
			else if(attackChoice == 2) {
				if(m_numSpecial > 0) {
					int dmg = m_myTerran->SpecialAttack();
					m_curZerg->SetHealth(m_curZerg->GetHealth()-dmg);
					m_numSpecial--;
					break;
				}
				else { cout << "You're out of special attacks until you rest!\n"; }
			}
			else { cout << "Invalid option.\n"; }
		} while(true);
		//Deciding whether zerg does normal or special based on 50/50
		int roll = rand()%2;
		int zdmg = roll == 0 ? m_curZerg->Attack() : m_curZerg->SpecialAttack();
		m_myTerran->SetHealth(m_myTerran->GetHealth()-zdmg);
	}
	ProcessBattle(m_curZerg->GetHealth() > 0, m_myTerran->GetHealth() > 0);
}

void Game::ProcessBattle(bool zergAlive, bool alive) {
	if(!zergAlive && !alive) {
		cout << "You defeated each other at the same time!\n";
		delete m_curZerg;
		m_curZerg = nullptr;
	}
	else if(!zergAlive) {
		cout << "You have defeated the " << m_curZerg->GetName() << ".\n";
		m_wins++;
		if(rand()%10 == 0) {
			cout << "You earned another rest!\n";
			m_numRests++;
		}
		delete m_curZerg;
		m_curZerg = nullptr;
	}
	else {
		cout << "You were defeated by the " << m_curZerg->GetName() << ".\n";
	}
}

void Game::Rest() {
	if(m_curZerg != nullptr) {
		cout << "You cannot rest with a zerg nearby.\n";
		return;
	}
	m_myTerran->SetHealth(m_myTerran->GetHealth() + REST_HEAL);
	m_numSpecial = NUM_SPECIAL;
	cout << "You rest and wake refreshed.\n";
}

void Game::Stats() {
	cout << "Name: " << m_myTerran->GetName() << endl;
	cout << "HP: " << m_myTerran->GetHealth() << endl;
	cout << "Rests: " << m_numRests << endl;
	cout << "Special: " << m_numSpecial << endl;
	cout << "Wins: " << m_wins << endl;
}

Entity* Game::RandomZerg() {
    int roll = rand()%4;
    if(roll == 0) {
        cout << "A small terrifying zergling waits here." << endl;
        return new Zergling();
    }
    else if(roll == 1) {
        cout << "A large flying mutalisk hovers here." << endl;
        return new Mutalisk();
    }
    else if(roll == 2) {
        cout << "A medium sized hydralisk slithers here waiting to cover you with acid." << endl;
        return new Hydralisk();
    }
    else {
        cout << "It is peaceful here." << endl;
        return nullptr;
    }
}