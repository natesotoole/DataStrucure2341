#include "team.h"
#include <iostream>
Team::Team()
{
    score = 0;
}

Team::Team(char teamLetter){
    teamID = teamLetter;
    score = 0;

}

//runs through the team file and gets the name and id for each player
void Team::addTeam(char* teamFile){

       ifstream newTeam;
       newTeam.open(teamFile);
       if (!newTeam){
           cout<<"unable to open"<<endl;
       }

        //gets team and number of players and creates a player array of it.
        getline(newTeam, teamName);
       //newTeam >> teamName;
        //cout << teamName <<endl;
        newTeam >> numPlayers;
        teamPlayers = new player*[numPlayers];


        //gets each player and the players id number and than sends to player.
        for(int i = 0; i < numPlayers; i++)
        {
            newTeam >> playerID;
            getline(newTeam, playerName);

            teamPlayers[i] = new player(playerID, playerName, numPlayers);

        }

        newTeam.close();

}


//gets total players on team
int Team::getNumPlayers(){
    return numPlayers;
}

//get the team players
player** Team::getTeamPlayers(){
    return teamPlayers;
}

// adds the score for the team to see the winner
void Team::addTeamsScore(int point){

        //Shot in the Back
        if(point == 1)
        {
            score += 5;
        }

        //Shot in the Chest
        if(point == 2)
        {
            score += 8;
        }

        //Shot in the Shoulder
        if(point == 3)
        {
            score += 10;
        }

        //Shot in the Laser Gun
        if(point == 4)
        {
            score += 15;
        }




}

//add hits for med verbosity
void Team::addHitsForMedVerbosity(player* tagger, int hitNum){
    //Shot in the Back
    if(hitNum == 1)
    {
        tagger->addTag(5);
    }

    //Shot in the Chest
    if(hitNum == 2)
    {
        tagger->addTag(8);
    }

    //Shot in the Shoulder
    if(hitNum == 3)
    {
        tagger->addTag(10);
    }

    //Shot in the Laser Gun
    if(hitNum == 4)
    {
        tagger->addTag(15);
    }


}


    /*if (shooter <= numPlayers){

    }else{

    }
    */




//gets total score for the tema
int Team::getTeamsScore(){
    return score;
}

//gets teams name
string Team::getTeamName(){
    return teamName;
}


