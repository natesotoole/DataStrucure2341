#include "player.h"

player::player()
{
    totalPoints = 0;
    totalTags = 0;
    numPlayers = 0;
}


player::player(int playerId, string playerName, int players){
    id = playerId;
    name = playerName;
    totalTags = 0;
    totalPoints = 0;
    numPlayers = players;

}

//gets player id
int player::getID(){
    return id;
}

// adds tag when player gets a hit
void player::addTag(int pointScore){
    totalTags += 1;
    totalPoints += pointScore;
}
//gets players name
string player::getName(){
    return name;
}
//gets total points for the player
int player::getTotalPoints(){
    return totalPoints;
}
//gets total tags for the player
int player::getTotalTags(){
    return totalTags;
}
// sets tags for high verbosity
void player::setTags(int otherTeamPlayers){
    tags = new int[otherTeamPlayers + 1];


}
//adds tags for high verbosity
void player::addTagForHighVerbo(int target){
    tags[target-1] += 1;
}
//gets tags for high verbosity
int* player::getTags(){
    return tags;
}
