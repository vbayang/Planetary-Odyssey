#ifndef TUNDRA_H
#define TUNDRA_H
#include <iostream>
#include <string>
using namespace std;

#include "Planet.h"

class Tundra: public Planet{
  public:
    Tundra(int);
    ~Tundra();
    void setExplore(int);
  private:
};
#endif