#include "Planet.h"
#include "Easy.h"
#include "Medium.h"
#include "Hard.h"
#include <ctime>

Planet::Planet(){}

Planet::~Planet(){
  if (difficulty_ptr != nullptr){
    delete difficulty_ptr;
  }
  difficulty_ptr = nullptr;
}
Planet::Planet(Planet& p){
  //how to copy constructor (ie Class item1 = item2)
  //1. copy non-pointer variables
  //2. create new_pointer
  //3. copy into new_pointer 
   
  message = p.message; 
  planetType = p.planetType;
  mult = p.mult;
  resource = p.resource;
  messageNum = p.messageNum;
  art = p.art;
  
  if(p.difficulty_ptr == nullptr){
    difficulty_ptr = nullptr;
    return;
  }

  difficulty_ptr = p.difficulty_ptr;
}
Planet& Planet::operator=(const Planet& p){
   //how to overload assignment operator (ie item1 = item2)
   //1. check new item is different from old item
   //2. copy non-pointer variables
   //3. check null & release old_pointer
   //4. create new_pointer
   //5. copy into new_pointer
  
  message = p.message;
  planetType = p.planetType;
  mult = p.mult;
  resource = p.resource;
  messageNum = p.messageNum;
  art = p.art;
  
  if(p.difficulty_ptr == nullptr){
    difficulty_ptr = nullptr;
    return *this;
  }

  if(difficulty_ptr != nullptr){
    delete difficulty_ptr;
  }

  difficulty_ptr = p.difficulty_ptr;
  
  
  return *this;
}
void Planet::setDifficulty(int temp){  
  if (temp == 0){
    difficulty_ptr = new Easy();
  }
  if (temp == 1){
    difficulty_ptr = new Medium();
  }
  if (temp == 2){
    difficulty_ptr = new Hard();
  }
}

string Planet::getPlanetType(){return planetType;}
string Planet::getDifficulty(){
  return difficulty_ptr->getDifficulty();
}
int Planet::getCrew(){
  return difficulty_ptr->getCrew();
}
int Planet::getFuel(){
  return difficulty_ptr->getFuel();
}
int Planet::getMoney(){
  return difficulty_ptr->getMoney();
}
int Planet::getAtmosphere(){
  return difficulty_ptr->getAtmosphere();
}
string Planet::getMessage(){
  return message;
}
int Planet::getMessageNum(){
  return messageNum;
}
string Planet::getPlanetArt(){
  return art;
}

int Planet::getMult(){
  return mult;
}
string Planet::getResource(){
  return resource;
}

