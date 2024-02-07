#ifndef STRANGER_INTERACT_GOOD_H
#define STRANGER_INTERACT_GOOD_H
#include "RandomEvent.h"

class StrangerInteractGood: public RandomEvent{
  public:
    StrangerInteractGood();
    void printGoodEnding();
    void printBadEnding();
};
#endif

StrangerInteractGood::StrangerInteractGood(){
  correct = true; //interacting with the stranger is good
  resource = "potato";
}
void StrangerInteractGood::printGoodEnding(){
  resource = "money";
  mult = 1;
  cout << "The crew approaches the stranger who trades them money for stories of their travel." << endl;
}
void StrangerInteractGood::printBadEnding(){
  resource = "crew";
  mult = -1;
  cout << "The crew weren't notified of an impending dangerous storm." << endl;
}


