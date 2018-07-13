/*////////////////////////////////////////////////////
//                                                  //
//  Description : Number Assumption Game            //
//  Category    : game, OOP, modular programming    //
//  Author      : Saiful Islam Rasel                //
//                                                  //
////////////////////////////////////////////////////*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

class PlayerInterface{
protected:
    string name;
    int score;
public:
    PlayerInterface(){
        score = 0;
    }
    void setName(){
        getline(cin,name);
    }
    string getName(){
        return Name;
    }
    int getScore(){
        return score;
    }
    void incrementScore(){
        score++;
    }
};

class RandomNumberGenarator{
    int randomNumber;
public:
    RandomNumberGenarator(){
        randomNumber = 0;
    }
    RandomNumberGenarator(time_t t){
        srand(time(&t));
        randomNumber = (rand()%6)+1;
    }
    void setRandomNumber(time_t t){
        srand(time(&t));
        randomNumber = (rand()%6)+1;
    }
    int getRandomNumber(){
        return randomNumber;
    }
};

void scoreUpdating(PlayerInterface &player,RandomNumberGenarator randomNumber,int assumptionNumber){
    if(assumptionNumber==randomNumber.getRandomNumber()){
        player.incrementScore();
    }
}

int WinCheck(PlayerInterface player1,PlayerInterface player2){
    if(player1.getScore()==10) return 1;
    else if(player2.getScore()==10) return 2;
    else return 0;
}

void display(){

}
