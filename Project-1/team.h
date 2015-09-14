#ifndef TEAM_H
#define TEAM_H
#include "player.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


class Team
{
public:
    Team();
    Team(char);
    void addTeam(char* teamFile);
    string teamName;
    int numPlayers;
    int playerID;
    string playerName;
    char teamID;
    player** teamPlayers;const int size = 256;




};

#endif // TEAM_H
