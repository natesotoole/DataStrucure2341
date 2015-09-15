#ifndef MATCH_H
#define MATCH_H

#include <iostream>
#include <string>
#include <fstream>
#include "player.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include "team.h"


using namespace std;

class match
{
public:
    match();

    match(Team**);

    void getMatchInfo(char*, char*, char*);

    void lowVerbosity(ofstream &output);

    void medVerbosity(ofstream &output);

    void highVerbosity(ofstream &output);

    char numSpots;

    int target;
    int shooter;
    int time;
    int hitNum;
    Team* teamA;
    Team* teamB;
private:

};

#endif // MATCH_H
