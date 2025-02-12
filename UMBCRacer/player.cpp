/* File:      player.cpp
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
#include "Player.h"
using namespace std;

Player:: Player(){
    m_name = "Beannie";
    m_stat[0] = 1;
    m_stat[1] = 1;
    m_stat[2] = 1;
    m_races = 0;
    m_wins  = 0;
    m_falls = 0;
};

Player::Player(string name){
    m_name = name;
    m_stat[0] = 1;
    m_stat[1] =1;
    m_stat[2] =1;
    m_races =0;
    m_wins = 0;
    m_falls =0;
};

string Player::GetName(){
    return m_name;
};

void Player::SetName(string name){
m_name = name;
};

int Player::GetSpeed(){
    return m_stat[0];
};

int Player::GetAgility(){
    return m_stat[1];
};

int Player::GetJump(){
    return m_stat[2];
};

int Player::GetRaces(){
    return m_races;
};

int Player::GetFalls(){
    return m_falls;
};

void Player::SetRaces(int races){
    m_races = races;
};

void Player::SetFalls(int falls){
    m_falls = falls;
};

void Player::DisplayStatus() {
    cout << "*****  THE MIGHTY RACER " << m_name << "**********" << endl;
    cout << "Races: " << m_races << endl;
    cout << "Wins: " << m_wins << endl;
    cout << "Falls: " << m_falls << endl;
    cout << endl;
    cout << "Stats" << endl;
    cout << "Speed: " << m_stat[0] << endl;
    cout << "Agility: " << m_stat[1] << endl;
    cout << "Jump: " << m_stat[2] << endl;
}

void Player::IncreaseStat() {
    int stat_choice;
    do {
        cout << "Which stat do you want to increase?" << endl;
        cout << "1 is speed, 2 is agility, 3 is jump!" << endl;
        cin >> stat_choice;
        if (stat_choice >= 1 && stat_choice <= 3 && m_stat[stat_choice - 1] < 10) {
            m_stat[stat_choice - 1]++;
        } else {
            cout << "Invalid choice, please try again" << endl;
        }
    } while(stat_choice < 1 || stat_choice > 3 || m_stat[stat_choice-1] >= 10);
}

int Player::GetStat(int stat){
    return m_stat[stat];
}

void Player::IncreaseWins(){
    m_wins = m_wins + 1;
}