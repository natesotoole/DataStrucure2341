#include <iostream>
#include <fstream>
#include "match.h"
#include "player.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <team.h>

using namespace std;

int main(int argc, char* argv[])
{
    Team* teamA = new Team('A');
    Team* teamB = new Team('B');

    match* match1 = new match();

    teamA->addTeam(argv[1]);
    teamB->addTeam(argv[2]);
    match1->getMatchInfo(argv[3]);




}
