#include "Ocean.h"
#include <iostream>
#include <string>
using namespace std;

Ocean::Ocean(int r){
  difficulty_ptr = nullptr;
  planetType = "Oceanic Planet";
  messageNum = r;
  art = R"(                                  '.    \   :   /    .'
                       __           '.   \  :  /   .'
                     /. _\            '.  \ : /  .'
                .--.|/_/__      -----____   _  _____-----
_______________''.--o/___  \_______________(_)___________
       ~        /.'o|_o  '.|  ~                   ~   ~
  ~        ~   |/    |_|  ~'      ~  ~     ~  ~
       ~       '  ~  |_|        ~       ~     ~  ~  ~
  ~   ~    ~     ~    |_|   ~    ~                  ~
             ~     ___|_||_____     ~   ~   ~    ~  ~
   ~    ~  ~   .'':. .|_| :. ..::''.
             /:.  .:::|_|.  .:.  :.:\   ~   ~  ~
  ~  ~  ~   :..:. .:. .::..:  .:  ..:.       ~   ~    ~
             \.: .:  :. .: ..:: .   /  ~   ~
    ~   ~  ~      ~    ~    ~         ~
    ~          ~      ~    ~    ~   ~     ~       ~
        ~  ~      ~            ~   ~                 ~
   ~         ~        ~    ~ ~                 ~)";
  setExplore(r);
}
Ocean::~Ocean(){
  if (difficulty_ptr != nullptr){
    delete difficulty_ptr;
    difficulty_ptr = nullptr;
  }
}


void Ocean::setExplore(int result){
  if (result == 0){ //win crew
    resource = "crew";
    mult = 1;
    message =
    "The crew's advanced technology kickstarted the planet's\ntechnological revolution and local alien scientists wished to explore\nwith the crew to further develop their planet.\n";
  }
  if (result == 1){ //win fuel
    resource = "fuel";
    mult = 1;
    message =
    "The crew discovered that when spooked,\n a native animal they were researching produced a substance that could be used as fuel.\n";
  }
  if (result == 2){ //win money
    resource = "money";
    mult = 1;
    message =
    "The crew followed a native animal to it's habit\nand found the wreckage of a previously sunken vessel.\n";
  }
  if (result == 3){ //lose crew
    resource = "crew";
    mult = -1;
    message =
    "The crew's vehicle ran into an object in the ocean causing a leak.\n";
  }
  if (result == 4){ //lose fuel
    resource = "fuel";
    mult = -1;
    message =
    "The liquid of the oceanic planet caused some of\nthe crew's vehicles to malfunction and were ultimately abandoned.\n";
  }
  if (result == 5){ //lose money
    resource = "money";
    mult = -1;
    message =
    "A local merchant convinced the crew they could eat\n a native plant to allow them to see clearly beneath the planets' ocean.\nThe plant was a scam.\n";
  }
  return message;
}