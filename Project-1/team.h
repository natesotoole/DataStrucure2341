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
    int getNumPlayers();
    player** getTeamPlayers();
    void addTeamsScore(int);
    int getTeamsScore();
    string getTeamName();

    void addHitsForMedVerbosity(player *, int);

    string teamName;
    int numPlayers;
    int playerID;
    string playerName;
    char teamID;
    player** teamPlayers;
    const long size = 256;
    int score;
    int** hits;




};

#endif // TEAM_H
