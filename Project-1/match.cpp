#include "match.h"
#include <stdio.h>
#include <stdlib.h>

match::match()
{
    numSpots = 4;
    spotPoints = new char[numSpots];
    hitsName = new string[numSpots];
    int target = 0;
    int shooter = 0;
    int time = 0;
    int hitNum = 0;
}
match::match(int totalSpots){
    numSpots = totalSpots;
    spotPoints = new char[numSpots];
    hitsName = new string[numSpots];
}

void match::setHits(){
    spotPoints[1] = 5;
    spotPoints[2] = 8;
    spotPoints[3] = 10;
    spotPoints[4] = 15;
    hitsName[1] = "back";
    hitsName[2] = "chest";
    hitsName[3] = "shoulder";
    hitsName[4] = "laser gun";
}




void match::getMatchInfo(char* matchFile){

/*
    for (int a = 0; a < numLines; a ++){
            string line;
            getline(input, line);
                char* hitLine = new char[line.length()];
                for (int i=0;i<=line.length();i++){
                    hitLine[i]= line[i];

                }
                for (int i=0;i<=line.size();i++){
                    int numSpaces = 0;
                    if (hitLine[i] == ' '){
                        numSpaces ++;
                    }else{
                        char numChar = hitLine[i];
                        if (numSpaces == 0){
                            shooter = atoi(&numChar);
                        }
                        else if(numSpaces == 1){
                            target = atoi(&numChar);
                        }
                        else if (numSpaces == 2){
                            time = (pow(10, i) * atoi(&hitLine[i])) + time;
                        }else{
                            hitNum = atoi(&numChar);
                        }
                    }
                }

                cout<< shooter <<endl;
                cout<< target<< endl;
                cout<< time <<endl;
                cout<< hitNum<<endl;



        }
        */
}

