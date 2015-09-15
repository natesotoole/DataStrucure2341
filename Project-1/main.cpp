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
    // creates the team objects
    Team** teams = new Team*[2];
    teams[0] = new Team('A');
    teams[1] = new Team('B');

    //creates match object
    match* match1 = new match(teams);

    //sends the arguements
    teams[0]->addTeam(argv[1]);
    teams[1]->addTeam(argv[2]);

    //gets match hits and outputs it to the text file
    match1->getMatchInfo(argv[3], argv[4], argv[5]);




}
