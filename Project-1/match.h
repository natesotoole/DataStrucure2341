#ifndef MATCH_H
#define MATCH_H

#include <iostream>
#include <string>
#include <fstream>
#include "player.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>


using namespace std;

class match
{
public:
    match();
    match(int);
    void getMatchInfo(char*);
    void setHits();



    char* spotPoints;
    char numSpots;
    string* hitsName;
    int target;
    int shooter;
    int time;
    int hitNum;

};

#endif // MATCH_H
