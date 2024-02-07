#ifndef SHIP_H
#define SHIP_H
#include <iostream>
#include <string>
using namespace std;

class Ship{
  public:
    Ship();
    Ship(int inCrew, int inFuel, int inMoney);
    ~Ship();
    
    //setter functions
    void setMoney(int multiplier, int moneyChange); 
    void setNumFuel(int multiplier, int fuelChange);
    void setNumCrew(int multiplier, int crewChange);
    void crewIsMax();
    void fuelIsMax();
    void moneyIsZero();
    //getter functions
    int getNumCrew();
    int getNumFuel();
    int getMoney();
    int getMaxFuel(); 
    int getMaxCrew(); 
    int getShipPrice();
    string getShipType();
    int getCrewPrice();
    int getFuelPrice();
    //print all info
    void printStats();
    
  protected:
    int numCrew = 0;
    int numFuel = 0;
    int money = 0;
    int maxCrew = 0;
    int maxFuel = 0;
    string shipType = "Ship";
    int shipPrice = 0;
    int crewPrice = 3;   //price to purchase crew in shop
    int fuelPrice = 3;  //price to purchase fuel in shop
};
#endif