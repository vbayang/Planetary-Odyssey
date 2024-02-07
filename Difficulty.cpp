#include "Difficulty.h"

Difficulty::Difficulty(){
}
Difficulty::Difficulty(int c, int f, int m, int a){
  crew = c;
  fuel = f;
  money = m;
  atmosphere = a;
}
int Difficulty::getAtmosphere(){return atmosphere;}
int Difficulty::getCrew(){return crew;}
int Difficulty::getFuel(){return fuel;}
int Difficulty::getMoney(){return money;}