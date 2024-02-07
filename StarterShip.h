#ifndef STARTER_SHIP_H
#define STARTER_SHIP_H
#include "Ship.h"

class StarterShip:public Ship{
  public:
    StarterShip();
    StarterShip(int inCrew, int inFuel, int inMoney);
    ~StarterShip();
};
#endif

//constructor and destructor
StarterShip::StarterShip(){
  numCrew = 7;
  numFuel = 25;
  money = 75;
  maxCrew = 10;
  maxFuel = 30;
  shipType = "Starter Ship";
}
StarterShip::StarterShip(int inCrew, int inFuel, int inMoney){
  numCrew = inCrew;
  numFuel = inFuel;
  money = inMoney;
  maxCrew = 10;
  maxFuel = 30;
  shipType = "Starter Ship";
}
StarterShip::~StarterShip(){}