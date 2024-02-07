#ifndef MEDIUM_H
#define MEDIUM_H
#include "Difficulty.h"

class Medium: public Difficulty{
  public:
    Medium(int _crew = 2, int _fuel = 5, int _money = 20, int _atmosphere = 4)
    :Difficulty(_crew, _fuel, _money, _atmosphere){
    }

    string getDifficulty() {return "Medium";}
};
#endif