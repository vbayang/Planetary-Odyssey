#include "Ship.h"

Ship::Ship(){}
Ship::~Ship(){}

//getter functions
int Ship::getNumCrew(){return numCrew;}
int Ship::getNumFuel(){return numFuel;}
int Ship::getMoney(){return money;}
int Ship::getMaxFuel(){return maxFuel;}
int Ship::getMaxCrew(){return maxCrew;}
string Ship::getShipType(){return shipType;}
int Ship::getShipPrice(){return shipPrice;}
int Ship::getCrewPrice(){return crewPrice;}
int Ship::getFuelPrice(){return fuelPrice;}

//setter functions
void Ship::setMoney(int multiplier, int moneyChange){
  money += (moneyChange*multiplier);
}
void Ship::setNumFuel(int multiplier, int fuelChange){
  numFuel += (fuelChange*multiplier);
}
void Ship::setNumCrew(int multiplier, int crewChange){
  numCrew += (crewChange*multiplier);
}
void Ship::crewIsMax(){
  numCrew = maxCrew;
}
void Ship::fuelIsMax(){
  numFuel = maxFuel;
}
void Ship::moneyIsZero(){
  money = 0;
}


void Ship::printStats(){
  cout << "Your Ship Statistics:" << endl;
  cout << "Ship Type........" << shipType << endl;
  cout << "Crew............." << numCrew << "/" << maxCrew << endl;
  cout << "Fuel............." << numFuel << "/" << maxFuel << endl;
  cout << "Money............$" << money  << endl;
}