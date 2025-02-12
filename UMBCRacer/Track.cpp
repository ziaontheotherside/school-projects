/* File:      track.cpp
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
#include "Track.h"
using namespace std;

Track::Track() {
    m_length = 4;
    m_track[NUM_RACERS];
    ResetLocation();
}

void Track::SetLength(int length) {
    m_length = length;
}

void Track:: PopulateObstacles (){
    for (int i = 0; i < m_length; i++)
        m_obstacle[i] = rand() % 3;
}

void Track::GetStatus() {
    for (int i = 0; i < NUM_RACERS; i++)
    {
        if(i == 0) { cout << "You are "; }
        else { cout << "Player " << i << " is "; }
        cout << "on a " << ConvertObstacle(i) << " obstacle in (obstacle " << m_track[i]+1 << " of " << m_length << ")" << endl;
    }
}

int Track::CheckWin() {
    for(int i = 0; i < NUM_RACERS; i++) {
        if(m_track[i] >= m_length) { return i; }
    }
    return -1; //No Winner
}

int Track::GetObstacle(int location) {
    return m_obstacle[location];
}

void Track::IncrementLocation(int player) {
    m_track[player]++;
}

void Track::ResetLocation() {
    for(int i = 0; i < NUM_RACERS; i++) {
        m_track[i] = 0;
    }
}

string Track::ConvertObstacle(int player) {
    return OBSTACLE_TYPE[m_obstacle[m_track[player]]];
}