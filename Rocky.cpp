#include "Rocky.h"
#include <iostream>
#include <string>
using namespace std;

Rocky::Rocky(int r){
  difficulty_ptr = nullptr;
  planetType = "Rocky Planet";
  messageNum = r;
  art = R"(              / \                 _
             /   \              _/ \
         .--'\/\_ \            /    \       ___
       _/ ^      \/\ __        /\/\  /\  __/   \
      /    .'   _/  /  \     /    \/  \/ .`'\_/\
     / :' __  ^/  ^/    `--./.'  ^  `-.\ _    _:\ _
    /\  _/  \-' __/.' ^ _   \_   .'\   _/ \ .  __/ \
  /\  \/   ' \ / -.   _/ \ -. `_/   \ /    `._// \  \
 /  ` / .- .--'    . /    `--./ .-'  `-.  `___/\_ \  `.
/    .'\  '-. `-.   /  .-'   / .   .'  __^/  \\ \\/\'  \
   _/   \"""""""""""""""""""""""""""""/    .'   _/  /
 ./ .-'  \"".-.""""""""""""""""""""""/ :' __  ^/  ^/  \
 / .   .'_\/   \_""""""""""""""""""""/  _/  \_' __/.'  \
     _/ /\_      `--."""".'\""""""./..\/ .-  \`. -.     `-.
   // .-  \`  .-'    `._/   \""""// . / /   --/\   .  .'   \
_//  //_ -- \    .' ^./ .-'  `-./  / / /    \/`-.   /     _
.. //      ` \       / .   .'   \)";
  setExplore(r);
}
Rocky::~Rocky(){
  if (difficulty_ptr != nullptr){
    delete difficulty_ptr;
    difficulty_ptr = nullptr;
  }
}

void Rocky::setExplore(int result){
  //win crew
  if (result == 0){
    resource = "crew";
    mult = 1;
    message = 
    "The crew happened upon a rockslide and heard shouts for help.\nAfter rescuing the buried aliens, they decided to join your crew in thanks.\n";
  }
  
  if (result == 1){ //win fuel
    resource = "fuel";
    mult = 1;
    message = 
    "The crew noticed that the planet's structure was similar to their home planet.\nBecause of this, the crew was able to extract fuel from the planet's natural resources.\n";
  }
  if (result == 2){ //win money
    resource = "money";
    mult = 1;
    message = 
    "The crew found a cave and while exploring discovered a unique and valuable gemstone.\n";
  }
  if (result == 3){ //lose crew
    resource = "crew";
    mult = -1;
    message = 
    "While exploring a cliffside, some crew members\nlost balance and fell into the canyon below.\n";
  }
  if (result == 4){ //lose fuel
    resource = "fuel";
    mult = -1;
    message = 
    "The rocky terrain of the planet was more hazardous than previously anticipated\n and the crew had to navigate more slowly. As a result,\nmore fuel was needed to drive the exploration vehicles.\n";
  }
  if (result == 5){ //lose money
    resource = "money";
    mult = -1;
    message =
    "The crew accidentally wandered outside of their\nexploration zone and into territory claimed by local aliens.\nThe crew were forced to pay a fine for tresspassing.\n";
  }
    
  return message;
}
