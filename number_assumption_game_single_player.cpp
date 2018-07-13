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
        cout<< "Enter player Name: ";
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
protected:
    int randomNumber;
public:
    RandomNumberGenarator(){
        randomNumber = 0;
    }
    void setRandomNumber(time_t t){
        srand(time(&t));
        randomNumber = (rand()%6)+1;
    }
    int getRandomNumber(){
        return randomNumber;
    }
};

class DefaultPlayer:public PlayerInterface,public RandomNumberGenarator{
public:
    void displayGuessingNumber(){
        cout<< "Default player Input: "<<randomNumber<<endl;
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

void display(PlayerInterface player,DefaultPlayer player1){
    for(int i=0;i<20;i++){
        cout<< "/";
    }
    cout<<endl;
    cout<< "//   "<< player.getName()<< "Score is : "<<player.getScore();
    cout << "\t" << player1.getName()<< "Score is : "<<player1.getScore()<< "   //";
    cout<<endl;
    for(int i=0;i<20;i++){
        cout<< "/";
    }
}

int main(){
    PlayerInterface player;
    DefaultPlayer pcPlayer;
    player.setName();
    pcPlayer.setName();
    while(1){
        display(player)
    }
    return 0;
}
