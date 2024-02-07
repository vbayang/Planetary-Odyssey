#include "RandomEvent.h"

RandomEvent::RandomEvent(){}

string RandomEvent::getResource(){return resource;}
bool RandomEvent::getCorrect(){return correct;}
int RandomEvent::getMult(){return mult;}
int RandomEvent::getCrew(){return crew;}
int RandomEvent::getFuel(){return fuel;}
int RandomEvent::getMoney(){return money;}
string RandomEvent::getRandomArt(){
  return R"(      _____
  ___/     \___
 `-._)     (_,-`
     \O _ O/
      \ - /
       `-(
     _/`U'\_
    (       )
   / /     \ \
   \ |     | /
    \|=====|/
     |_.^._|
     | | | |
     ( ) ( )
     |_| |_|
 _.-' _j L_ '-._
(___.'     '.___))";
}

void RandomEvent::printPrompt(){
  cout << "The crew notices a strange alien up ahead." << endl;
  cout << "Do they approach?" << endl;
  cout << "Type 0 to approach or 1 to ignore." << endl;
}