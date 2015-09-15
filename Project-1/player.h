#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class player
{
public:
    player();
    player(int, string, int players);
    int getID();
    void addTag(int);
    int getTotalTags();
    int getTotalPoints();
    void setTags(int);
    void addTagForHighVerbo(int);
    int getTargetId();
    int* getTags();

    int numPlayers;
    string getName();
    string name;
    int id;
    int totalPoints;
    int totalTags;
    int* tags;

};

#endif // TEAM_H
