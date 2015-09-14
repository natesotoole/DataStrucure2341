#include "team.h"

Team::Team()
{

}

Team::Team(char teamLetter){
    teamID = teamLetter;

}

void Team::addTeam(char* teamFile){

       ifstream newTeam;
       newTeam.open(teamFile);

        //gets team and number of players and creates a player array of it.
        newTeam.getline(teamName, size);
        newTeam >> numPlayers;
        teamPlayers = new player*[numPlayers];


        //gets each player and the players id number and than sends to player.
        for(int i = 0; i < numPlayers; i++)
        {
            newTeam >> playerID;
            getline(newTeam, playerName);

            teamPlayers[i]->addPlayer(playerID, playerName);
        }

        newTeam.close();

}

