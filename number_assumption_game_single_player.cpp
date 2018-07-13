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
        return name;
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
    void setName(){
        name = "Pc_Player";
    }
};

void scoreUpdating(PlayerInterface &player,RandomNumberGenarator randomNumber,int assumptionNumber){
    if(assumptionNumber==randomNumber.getRandomNumber()){
        cout<< "Your answer is right"<<endl;
        player.incrementScore();
    }
    else cout<< "Your answer is wrong"<<endl;
}

void scoreUpdating(DefaultPlayer &player,RandomNumberGenarator randomNumber,int assumptionNumber){
    if(assumptionNumber==randomNumber.getRandomNumber()){
        cout<< "Pc Player answer is right"<<endl;
        player.incrementScore();
    }
    else cout<< "Pc Player answer is wrong"<<endl;
}

bool guessNumberValidityCheck(int guessNumber){
    if(guessNumber>0 and guessNumber<=6) return true;
    else return false;
}

int WinCheck(PlayerInterface player1,DefaultPlayer player2){
    if(player1.getScore()==5) return 1;
    else if(player2.getScore()==5) return 2;
    else return 0;
}

void display(PlayerInterface player,DefaultPlayer player1){
    cout<<endl;
    for(int i=0;i<70;i++){
        cout<< "/";
    }
    cout<<endl;
    cout<< player.getName()<< " Score is : "<<player.getScore();
    cout << "\t\t" << player1.getName()<< " Score is : "<<player1.getScore()<< endl;
    for(int i=0;i<70;i++){
        cout<< "/";
    }
    cout<<endl<<endl;
}

void clear_screen(){
    system("@cls||clear");
    cout<< "\t\t.....Game Is On....."<<endl;
}

int main(){

    PlayerInterface player;
    DefaultPlayer pcPlayer;
    RandomNumberGenarator randomNumber;
    time_t t;
    int guessNumber; /// for validity check

    player.setName();
    pcPlayer.setName();

    while(1){
        display(player,pcPlayer);
        randomNumber.setRandomNumber(t);
        while(1){
            cout<< "Please Guess the number (Between 1-6 ) : ";
            cin>>guessNumber;
            if(guessNumberValidityCheck(guessNumber)) {
                clear_screen();
                break;
            }
            else cout<< "Please try again"<<endl;
        }
        scoreUpdating(player,randomNumber,guessNumber);
        pcPlayer.setRandomNumber(t);
        pcPlayer.displayGuessingNumber();
        scoreUpdating(pcPlayer,randomNumber,pcPlayer.getRandomNumber());
        int temp = WinCheck(player,pcPlayer);
        if(temp==1){
            display(player,pcPlayer);
            cout<< "Congratulation "<<player.getName()<< " You Win"<<endl;
            break;
        }
        else if(temp==2){
            display(player,pcPlayer);
            cout<< "Ops Sorry "<<player.getName()<< " You Lose"<<endl;
            break;
        }
    }
    return 0;
}
