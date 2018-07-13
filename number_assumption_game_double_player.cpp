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

void scoreUpdating(PlayerInterface &player,RandomNumberGenarator randomNumber,int assumptionNumber){
    if(assumptionNumber==randomNumber.getRandomNumber()){
        cout << "Answer is right"<<endl;
        player.incrementScore();
    }
    else cout << "Answer is Wrong"<<endl;
}

bool guessNumberValidityCheck(int guessNumber){
    if(guessNumber>0 and guessNumber<=6) return true;
    else return false;
}

int WinCheck(PlayerInterface player1,PlayerInterface player2){
    if(player1.getScore()==5) return 1;
    else if(player2.getScore()==5) return 2;
    else return 0;
}

void display(PlayerInterface player,PlayerInterface player1){
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
    cout<< "\t\t..... Get 5 points to win .....\n"<<endl;
}

int main(){

    PlayerInterface player1,player2;
    RandomNumberGenarator randomNumber;
    time_t t;
    int guessNumber1,guessNumber2; /// for validity check

    cout<< "Enter first player name: ";
    player1.setName();
    cout<< "Enter Second player name: ";
    player2.setName();

    while(1){
        display(player1,player2);
        randomNumber.setRandomNumber(t);
        while(1){
            cout<< "First player term: "<<endl;
            cout<< "Please Guess the number (Between 1-6 ) : ";
            cin>>guessNumber1;
            if(guessNumberValidityCheck(guessNumber1)) {
                break;
            }
            else cout<< "Please try again"<<endl;
        }
        while(1){
            cout<< "Second player term: "<<endl;
            cout<< "Please Guess the number (Between 1-6 ) : ";
            cin>>guessNumber2;
            if(guessNumberValidityCheck(guessNumber2)) {
                clear_screen();
                break;
            }
            else cout<< "Please try again"<<endl;
        }

        cout<< "First player ";
        scoreUpdating(player1,randomNumber,guessNumber1);
        cout<< "Second player ";
        scoreUpdating(player2,randomNumber,guessNumber2);

        int temp = WinCheck(player1,player2);
        if(temp==1){
            display(player1,player2);
            cout<< "Congratulation "<<player1.getName()<< " You Win"<<endl;
            break;
        }
        else if(temp==2){
            display(player1,player2);
            cout<< "Congratulation "<<player2.getName()<< " You Win"<<endl;
            break;
        }
    }
    return 0;
}
