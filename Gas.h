#ifndef GAS_H
#define GAS_H
#include <iostream>
#include <string>
using namespace std;

#include "Planet.h"

class Gas: public Planet{
  public:
    Gas(int);
    ~Gas();
    void setExplore(int);
  private:
};
#endif