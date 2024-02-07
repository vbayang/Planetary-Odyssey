#ifndef MEDIUM_SHIP_H
#define MEDIUM_SHIP_H
#include "Ship.h"

class MediumShip:public Ship{
  public:
    MediumShip();
    MediumShip(int inCrew, int inFuel, int inMoney);
    ~MediumShip();
  private:
}; 
#endif

//constructors
MediumShip::MediumShip(){
  numCrew = 0;
  numFuel = 0;
  money = 0;
  maxCrew = 15;
  maxFuel = 40;
  shipType = "Medium Ship";
  shipPrice = 70;
}
MediumShip::MediumShip(int inCrew, int inFuel, int inMoney){
  numCrew = inCrew;
  numFuel = inFuel;
  money = inMoney;
  maxCrew = 15;
  maxFuel = 40;
  shipType = "Medium Ship";
  shipPrice = 70;
}
MediumShip::~MediumShip(){}