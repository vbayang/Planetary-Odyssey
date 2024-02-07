#ifndef EASY_H
#define EASY_H
#include "Difficulty.h"

class Easy: public Difficulty{
  public:
    Easy(int _crew = 1, int _fuel = 3, int _money = 10, int _atmosphere = 2)
    :Difficulty(_crew, _fuel, _money, _atmosphere){
    }

    string getDifficulty() {return "Easy";}
};
#endif