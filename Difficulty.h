#ifndef DIFFICULTY_H
#define DIFFICULTY_H
#include <iostream>
using namespace std;

class Difficulty{
  public:
    Difficulty();
    Difficulty(int, int, int, int);
    int getAtmosphere();
    int getCrew();
    int getFuel();
    int getMoney();
    virtual string getDifficulty() = 0;
  protected:
    int crew;
    int fuel;
    int money;
    int atmosphere; 

//how much fuel to get through the atmosphere
};
#endif