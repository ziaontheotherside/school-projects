/* File:      proj4.cpp
Author:       Zia Animashaun
Date:         11/17/2022
Section:      Section 25
E-mail:       fanimas1@umbc.edu
Description:  For this project, we are going to build a replica of Blizzard's Starcraft.
*/

#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  if( argc != 2) {
    cout << "This requires a map file to be loaded." << endl;
    cout << "Usage: ./proj4 proj4_map1.txt" << endl;
  }

  cout << "Loading file: " << argv[1] << endl << endl;

  string mapName = argv[1];
  srand (time(NULL));
  Game g(mapName);
  g.StartGame();
  return 0;
}
