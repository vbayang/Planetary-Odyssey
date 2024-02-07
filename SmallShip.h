#ifndef SMALL_SHIP_H
#define SMALL_SHIP_H
#include "Ship.h"

class SmallShip:public Ship{
  public: 
    SmallShip();
    SmallShip(int inCrew, int inFuel, int inMoney);
    ~SmallShip();
};
#endif

//constructors and destructor
SmallShip::SmallShip(){
  numCrew = 0;
  numFuel = 0;
  money = 0;
  maxCrew = 12;
  maxFuel = 35;
  shipType = "Small Ship";
  shipPrice = 50;
}
SmallShip::SmallShip(int inCrew, int inFuel, int inMoney){
  numCrew = inCrew;
  numFuel = inFuel;
  money = inMoney;
  maxCrew = 12;
  maxFuel = 35;
  shipType = "Small Ship";
  shipPrice = 50;
}
SmallShip::~SmallShip(){}