#include "Tundra.h"
#include <iostream>
#include <string>
using namespace std;

Tundra::Tundra(int r){
  difficulty_ptr = nullptr;
  planetType = "Tundra Planet";
  messageNum = r;

  art = R"(         *           *    .,- - _ - ,._.. . .. .,- - _ - , .
 *     *      *                (    (        _ .    (    (
                  *      ` ;      ) '-`-,,'---'`-'``'`-)'  ,
                     *     ;   ;;    /\/ | |   ,;   ;;    /
 *     *                    |  ;`,  ,  ` `,'/\/  |  ;`,  ,`
             *              ; |  | |      |,  `  ; |  | |
   *             *      *   ; ;  `,'             ; ;  `,'
                             |;   |               |;   |
*       *                    ||                   ||
               *       *      `                    `
                    *
  *     ,.  *             *
      \('')      *    *                                     *
    * (;  .)  *           *     *                 *        **
--...-(|___)---..-.-..-.**-*--.***-'.*-.*-.-..-..***.-...-***)";
  setExplore(r);
}
Tundra::~Tundra(){
  if (difficulty_ptr != nullptr){
    delete difficulty_ptr;
    difficulty_ptr = nullptr;
  }
}

void Tundra::setExplore(int result){
  if (result == 0){ //win crew
    resource = "crew";
    mult = 1;
    message =
    "The crew decided to enjoy the constant snow on the planet and made snowmen.\nTurns out thats how residents of the planet are born\nand the crew brought the aliens back to their ship.\n";
  }
  if (result == 1){ //win fuel
    resource = "fuel";
    mult = 1;
    message =
    "The crew picked up a signal in the frozen wasteland and followed it\nto an old exploration outpost that still contained resources.\n";
  }
  if (result == 2){ //win money
    resource = "money";
    mult = 1;
    message =
    "The crew kills a cryptid monster that had been terrorizing the local village.\nThe village elders offered reward for the beast’s defeat.\n";
  }
  if (result == 3){ //lose crew
    resource = "crew";
    mult = -1;
    message =
    "The light reflecting off the snow and ice of the planet\nblinded some crew members making them unable to continue the journey.\n";
  }
  if (result == 4){ //lose fuel
    resource = "fuel";
    mult = -1;
    message =
    "While exploring, the fuel containers got too cold causing some fuel to freeze.\n";
  }
  if (result == 5){ //lose money
    resource = "money";
    mult = -1;
    message =
    "While exploring an ice cavern, the crew got spooked by their reflections\nand ran off without grabbing all their supply bags.\n";
  }
  return message;
}