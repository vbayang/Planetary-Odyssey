#include "Gas.h"
#include <iostream>
#include <string>
using namespace std;

Gas::Gas(int r){
  difficulty_ptr = nullptr;
  planetType = "Gaseous Planet";
  messageNum = r;
  art = R"(                     (`  ).      ( )          _
          .')       (     ).    (_.'      .:(`  )`.
         (_  )     _(       '`.          :(   .    )
    ._         .=(`(      .   )     .--  `.  (    ) )
 .+(`  )      ((    (..__.:'-'   .+(   )   ` _`  ) )
 (     `))    `(       ) )       (   .  )     (   )  ._
(   ( )  ))     ` __.:'   )     (   (   ))     `-'.-(`  )
 `- __.:' )  ( )       --'       `- __.'         :(      ))
         '  (_.'    _     .')                    `(    )  ))
  .=(`)         .:(`  )`.(_  )       ._            ` __.:'
 ((    `))__   :(   .    )        .+(`  )
 `(       ) )  `.  (    ) )       (     `))
   ` __.:'   )   ` _`  ) )       (   ( )  ))
          --'       (   )         `- __.:' )
                     `-'.               .-')";
  setExplore(r);
}
Gas::~Gas(){
  if (difficulty_ptr != nullptr){
    delete difficulty_ptr;
    difficulty_ptr = nullptr;
  }
}


void Gas::setExplore(int result){
  if (result == 0){ //win crew
    resource = "crew";
    mult = 1;
    message =
    "The crew discovered an outlaw was using the planet's thick gas to\nescape detection and subjugate a local town. After getting rid of the ruffian,\nthe crew was approached by thankful villagers who offered their services.\n";
  }
  if (result == 1){ //win fuel
    resource = "fuel";
    mult = 1;
    message =
    "Local aliens believed the crew to be divine beings fortold\nin their planet's folklore and offered fuel to assist the crew's pilgrimage.\n";
  }
  if (result == 2){ //win money
    resource = "money";
    mult = 1;
    message = 
    "While testing the properties of the planet's gas,\nthe crew discovered it can turn silver into gold.\n";
  }
  if (result == 3){ //lose crew
    resource = "crew";
    mult = -1;
    message =
    "The thick cover of the gaseous planet disguised a dropoff into a crater.";
  }
  if (result == 4){ //lose fuel
    resource = "fuel";
    mult = -1;
    message =
    "While running ship tests, the planet's gas fogged up the crews goggles\nand caused them to trip and spill some fuel supplies.\n";
  }
  if (result == 5){ //lose money
    resource = "money";
    mult = -1;
    message =
    "The crew forgot to check their masks before exploring.\nThe gas gave the crew hallucinations and caused them to misplace their money.\n";
  }
  return message;
}