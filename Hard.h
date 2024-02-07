#ifndef HARD_H
#define HARD_H
#include "Difficulty.h"

class Hard: public Difficulty{
  public:
    Hard(int _crew = 3, int _fuel = 7, int _money = 30, int _atmosphere = 6)
    :Difficulty(_crew, _fuel, _money, _atmosphere){
    }

    string getDifficulty() {return "Hard";}
};
#endif