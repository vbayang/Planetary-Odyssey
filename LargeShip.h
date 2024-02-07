#ifndef LARGE_SHIP_H
#define LARGE_SHIP_H
#include "Ship.h"


class LargeShip: public Ship{
  public:
    LargeShip();
    LargeShip(int inCrew, int inFuel, int inMoney);
    ~LargeShip();
};
#endif
//constructors and destructor
LargeShip::LargeShip(){
  numCrew = 0;
  numFuel = 0;
  money = 0;
  maxCrew = 18;
  maxFuel = 45;
  shipType = "Large Ship";
  shipPrice = 120;
}
LargeShip::LargeShip(int inCrew, int inFuel, int inMoney){
  numCrew = inCrew;
  numFuel = inFuel;
  money = inMoney;
  maxCrew = 18;
  maxFuel = 45;
  shipType = "Large Ship";
  shipPrice = 120;
}
LargeShip::~LargeShip(){}