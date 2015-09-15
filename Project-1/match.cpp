#include "match.h"
#include <stdio.h>
#include <stdlib.h>

match::match()
{

    int target = 0;
    int shooter = 0;
    int time = 0;
    int hitNum = 0;
    teamA = new Team();
    teamB = new Team();


}
match::match(Team** teams){
    teamA = teams[0];
    teamB = teams[1];
}






void match::getMatchInfo(char* matchFile, char* outFile, char* vChoice){
    //open output stream
    ofstream output;
    output.open(outFile);

    //pulls the text file and creates a  stream for it
    ifstream newMatch;
    newMatch.open(matchFile);

    int numLines;
    newMatch>> numLines;


    //runs through each line to get the shooter and target and hit num
    for (int a = 0; a < numLines; a ++){

        newMatch >> shooter >> target >> time >> hitNum;

        int numPlayersTeamA = teamA->getNumPlayers();
        //goes through team A to see if the player was a target or a shooter
        for (int i = 0; i <numPlayersTeamA; i++){
            player** buffer = teamA->getTeamPlayers();
            if(buffer[i]->getID() == shooter){
                teamA->addHitsForMedVerbosity(buffer[i], hitNum);
                teamA->addTeamsScore(hitNum);
                for (int j = 0; j < teamB->getNumPlayers(); j++){
                    player** buffer2 = teamB->getTeamPlayers();
                    if (buffer2[j]->getID() == target){
                        buffer[i]->setTags(teamB->getNumPlayers());
                        buffer[i]->addTagForHighVerbo(shooter);
                    }
                }
            }

        }

        int numPlayersTeamB = teamB->getNumPlayers();
        //goes through each teamB to see if the player was a target or a shooter
        for (int i = 0; i <numPlayersTeamB; i++){
            player** buffer = teamB->getTeamPlayers();

            if(buffer[i]->getID() == shooter){
                teamB->addHitsForMedVerbosity(buffer[i], hitNum);
                teamB->addTeamsScore(hitNum);
                player** buffer2 = teamA->getTeamPlayers();
                for (int j = 0; j < teamA->getNumPlayers(); j++){

                    if (buffer2[j]->getID() == target){
                        buffer[i]->setTags(teamA->getNumPlayers());
                        buffer[i]->addTagForHighVerbo(target);
                    }
                }
            }

        }
    }
    if(strncmp(vChoice, "vlow", 4) == 0){

        lowVerbosity(output);
    }

    if(strncmp(vChoice, "vmed", 4) == 0){
         medVerbosity(output);
    }

    if(strncmp(vChoice, "vhigh", 4) == 0){
        highVerbosity(output);
    }

}
void match::lowVerbosity(ofstream& output){

    output<< "The score for " << (teamA->getTeamName())<< " is " << (teamA->getTeamsScore())<<endl;
    output<< "The score for " << (teamB->getTeamName())<< " is " << (teamB->getTeamsScore())<<endl;
    if(teamA->getTeamsScore() > teamB->getTeamsScore()){
        output<< "The winner is " << teamA->getTeamName() << endl;
    } else if (teamA->getTeamsScore() == teamB->getTeamsScore()){
        output<< "its a tie" <<endl;
    }else{
        output<< "The winner is " << teamB->getTeamName() << endl;
    }

    output.close();
}

void match::medVerbosity(ofstream& output){

    player** buffer = teamA->getTeamPlayers();
    int bestPlayerTeamA = 0;
    player** buffer2 = teamB->getTeamPlayers();
    int bestPlayerTeamB = 0;
    //output team a tags
    output << teamA->getTeamName() << endl;
    for(int i = 0; i < teamA->getNumPlayers(); i ++){
         output<< buffer[i]->getName() << " had a total of " << buffer[i]->getTotalTags() << " tags" << endl;
         if(buffer[bestPlayerTeamA]->getTotalPoints() < buffer[i]->getTotalPoints()){
             bestPlayerTeamA = i;
         }
    }
    //outputs team b tags
    output << teamB->getTeamName() << endl;
    for(int i = 0; i < teamB->getNumPlayers(); i ++){
         output<< buffer2[i]->getName() << " had a total of " << buffer2[i]->getTotalTags() << " tags"<< endl;

         if(buffer2[bestPlayerTeamB]->getTotalPoints() < buffer2[i]->getTotalPoints()){
             bestPlayerTeamB = i;
         }
    }

    output<< "The best player for the " <<teamA->getTeamName() << " is " << buffer[bestPlayerTeamA]->getName() << " with a score of "<< buffer[bestPlayerTeamA]->getTotalPoints()<<endl;
    output<< "The best player for the " <<teamB->getTeamName() << " is " << buffer2[bestPlayerTeamB]->getName() << " with a score of "<< buffer2[bestPlayerTeamB]->getTotalPoints()<<endl;
    lowVerbosity(output);


}
void match::highVerbosity(ofstream &output){


    player** taggersA = teamA->getTeamPlayers();
    player** taggersB = teamB->getTeamPlayers();

    for(int i = 0; i < teamA->getNumPlayers(); i++){
        int* taggersTag = taggersA[i]->getTags();
        for (int j = 0; j < teamB->getNumPlayers(); j ++){
            output<< taggersA[i]->getName() << " hit " << taggersB[j]->getName() <<  " " << taggersTag[j] << " times" <<endl;
        }
    }
    for(int i = 0; i < teamB->getNumPlayers(); i++){
        int* taggersTag = taggersB[i]->getTags();
        for (int j = 0; j < teamA->getNumPlayers(); j ++){
            output<< taggersB[i]->getName() << " hit " << taggersA[j]->getName() <<  " " << taggersTag[j] << " times" <<endl;
        }
    }
    lowVerbosity(output);

}

