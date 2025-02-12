/* File:      race.cpp
Author:       Zia Animashaun
Date:         10/10/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  Apart of the Project 2 program.
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Race.h"
using namespace std;

Race::Race() { }

void Race::StartRace() {
    //Configure Track
    m_track.SetLength(4);
    m_myPlayer.SetRaces(m_myPlayer.GetRaces()+1);
    int length = 0;
    do {
        cout << "How long would you like the race?" << endl;
        cin >> length;
        if(length < 1 || length >= MAX_LENGTH) {
            cout << "Race length must be between " << 1 << " and " << MAX_LENGTH << endl;
            cout << "Please try again." << endl;
        }
    } while(length < 1 || length >= MAX_LENGTH);
    m_track.SetLength(length);
    m_track.PopulateObstacles();
    m_track.ResetLocation();
    //Run race until completed
    while(m_track.CheckWin() == -1) {
        //Get player choice
        int choice = RaceOptions();
        if (choice == 1) {
            m_track.GetStatus();
            continue;
        }
        ProgressRace(choice - 2); //choice - 2 gets us the skill the player chose, because the menu says 2,3,4 = speed,agi,jump and 0,1,2 is speed,agi,jump
    }
    int winner = m_track.CheckWin();
    if(winner == 0) {
        cout << "You won the race!" << endl;
        m_myPlayer.IncreaseStat();
        m_myPlayer.IncreaseWins();
    }
    else cout << "Player " << winner << " won the race!" << endl;
    MainMenu();
}

void Race::GetRacerInfo() {
    cout << "What is your racer's name?" << endl;
    string name;
    getline(cin, name);
    m_myPlayer.SetName(name);
}

void Race::ProgressRace(int skill) {
    int difficulty = 1 + rand()%(BASE_DIFFICULTY-1);
    int skillRating = BASE_SKILL + m_myPlayer.GetStat(skill) * 5;
    cout << "You are trying to progress the race!" << endl;
    if(skillRating > difficulty) {
        cout << "You made it through the " << m_track.ConvertObstacle(0) << " obstacle!" << endl;
        m_track.IncrementLocation(0);
    }
    else {
        cout << "You fell!" << endl;
        m_myPlayer.SetFalls(m_myPlayer.GetFalls()+1);
    }
    ProgressComputer(difficulty);
}

void Race::ProgressComputer(int obstacleDifficulty) {
    for(int i=1; i<NUM_RACERS; i++) {
        int skillRating = COMP_MIN + rand()%(COMP_MAX-COMP_MIN);
        if(skillRating > obstacleDifficulty) {
            cout << "Player " << i << " made it through the " << m_track.ConvertObstacle(i) << " obstacle!" << endl;
            m_track.IncrementLocation(i);
        }
        else {
            cout << "Player " << i << " fell!" << endl;
        }
    }
}

bool Race::MainMenu() {
    int choice;
    do {
        cout << "What would you like to do?" << endl;
        cout << "1. Start New Race" << endl;
        cout << "2. View Racer History" << endl;
        cout << "3. Quit" << endl;
        cin >> choice;
        if(choice < 1 || choice > 3) {
            cout << "Invalid selection. Please try again." << endl;
        }
    } while(choice < 1 || choice > 3);
    if(choice == 1) StartRace();
    if(choice == 2) m_myPlayer.DisplayStatus();
    if(choice == 3) return false;
    return true;
}

int Race::RaceOptions() {
    int choice;
    do {
        cout << "What would you like to do?" << endl;
        cout << "1. Get Race Status" << endl;
        cout << "2. Try to Sprint (Speed)" << endl;
        cout << "3. Try to Dodge (Agility)" << endl;
        cout << "4. Try to Jump (Jump)" << endl;
        cin >> choice;
        if(choice < 1 || choice > 4) {
            cout << "Invalid selection. Please try again." << endl;
        }
    } while(choice < 1 || choice > 4);
    return choice;
}

void Race::ManageGame() {
    RaceTitle();
    GetRacerInfo();
    while(MainMenu()) { }
    cout << "Thanks for playing!" << endl;
}