#ifndef OCEAN_H
#define OCEAN_H
#include <iostream>
#include <string>
using namespace std;

#include "Planet.h"

class Ocean: public Planet{
  public:
    Ocean(int);
    ~Ocean();
    void setExplore(int);
  private:
};
#endif