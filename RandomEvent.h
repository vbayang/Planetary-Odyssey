#ifndef RANDOM_EVENT_H
#define RANDOM_EVENT_H
#include <iostream>
#include <string>
using namespace std;

class RandomEvent{
  public:
    RandomEvent();
    
    //getter functions
    string getResource(); 
    bool getCorrect(); //true = interacted, false = ignored
    int getMult();
    int getCrew();
    int getFuel();
    int getMoney();
    string getRandomArt();
    void printPrompt();
    virtual void printGoodEnding() = 0;
    virtual void printBadEnding() = 0;
    
  protected:
    string art;
    string resource; //always printEnding before getting resource
    bool correct;
    int mult;
    
    //all random events reward/harm the same amount
    int crew = 2;
    int fuel = 4;
    int money = 20;
};
#endif