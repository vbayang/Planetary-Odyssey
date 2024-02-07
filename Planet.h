#ifndef PLANET_H
#define PLANET_H
#include "Easy.h"
#include "Medium.h"
#include "Hard.h"
#include <string>
#include <ctime>

class Planet{
  public:
    Planet();
    Planet(Planet& p); //copy constructor
    virtual ~Planet(); 
    Planet& operator=(const Planet& p); //overloaded =
    
    void setDifficulty(int); //initializes pointer
    string getDifficulty();
    
    int getCrew();
    int getFuel();
    int getMoney();
    int getAtmosphere();
    string getPlanetType();
    string getMessage();
    
    int getMult();
    string getResource();
    int getMessageNum();
    string getPlanetArt();

  protected:
    Difficulty * difficulty_ptr;
    string message;
    int messageNum; //used for saved files
    int mult; //-1 or 1 if losing or gaining a resource
    string resource;
    string planetType; 
    string art; 
};
#endif