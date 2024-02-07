#ifndef ROCKY_H
#define ROCKY_H
#include <iostream>
#include <string>
using namespace std;

#include "Planet.h"

class Rocky: public Planet{
  public:
    Rocky(int);
    ~Rocky();
    void setExplore(int);
  private:
};
#endif
