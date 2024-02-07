#ifndef STRANGER_INTERACT_BAD_H
#define STRANGER_INTERACT_BAD_H
#include "RandomEvent.h"

class StrangerInteractBad: public RandomEvent{
  public:
    StrangerInteractBad();
    void printGoodEnding();
    void printBadEnding();
};
#endif

StrangerInteractBad::StrangerInteractBad(){
  correct = false; //ignoreing stranger is the right choice
  resource = "potato";
}

void StrangerInteractBad::printGoodEnding(){
  resource = "fuel";
  mult = 1;
  cout << "The crew takes a detour around the alien in their path and finds abandoned fuel cans." << endl;
}
void StrangerInteractBad::printBadEnding(){
  resource = "money";
  mult = -1;
  cout << "The crew is conned by the stranger and robbed." << endl;
}
