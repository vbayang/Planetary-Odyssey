#include "StarterShip.h"
#include "SmallShip.h"
#include "MediumShip.h"
#include "LargeShip.h"

#include "Rocky.h"
#include "Gas.h"
#include "Ocean.h"
#include "Tundra.h"

#include "StrangerInteractGood.h"
#include "StrangerInteractBad.h"

#include <fstream>
#include <ctime>

void printWelcome(){
  cout << R"(o               .        ___---___                    .
       .              .--\        --.     .     .         .
                    ./.;_.\     __/~ \.
                   /;  / `-'  __\    . \
 .        .       / ,--'     / .   .;   \        |
                 | .|       /       __   |      -O-       .
                |__/    __ |  . ;   \ | . |      |
                |      /  \\_    . ;| \___|
   .    o       |      \  .~\\___,--'     |           .
                 |     | . ; ~~~~\_    __|
    |             \    \   .  .  ; \  /_/   .
   -O-        .    \   /         . |  ~/                  .
    |    .          ~\ \   .      /  /~          o     |
  .                   ~--___ ; ___--~                 -O-
                 .          ---         .              |)" << endl;
  cout << "Wecolme to Planetary Odessey!" << endl;
  cout << "Challenge yourself to explore a number of planets" << endl;
  cout << "before running out of crew or fuel." << endl;
  cout << "Each planet you explore will impact your resource level." << endl;
  cout << "There is a mysterious stranger you will encounter" << endl;
  cout << "on your journey who may help or harm you." << endl;
  cout << "Good luck and happy travels!" << endl;
  cout << endl;
  cout << "Type 1 to start a new game, Type 2 to load a saved game" << endl;
}
void printLineBreak(){
  cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:." << endl;
}

Planet* createPlanets(int size){
  //create planets array
  Planet* p = new Planet [size];
  int ptype;
  int explr;
  int dif;
  for (int i = 0; i < size; i++){
    //randomize planet's type
    ptype = rand() % 4; //gives 0, 1, 2, 3
    explr = rand() % 6;
    if (ptype == 0) {p[i] = Rocky(explr);}
    if (ptype == 1){p[i] = Ocean(explr);}
    if (ptype == 2){p[i] = Gas(explr);}
    if (ptype == 3){p[i] = Tundra(explr);}
  
    //randomize planet's difficulty
    dif = rand() % 3; //gives 0,1,2
    p[i].setDifficulty(dif);
  }
  return p;
}

//output planet type and difficulty and remove fuel to enter
void visitPlanet(int& planetsVisited, int maxPlanets, Ship* ship, Planet* planets){
      cout << "Planet " << planetsVisited << "/" << maxPlanets << " is a(n) " << planets[planetsVisited-1].getDifficulty() << " " << planets[planetsVisited-1].getPlanetType() << endl;
      cout << "Visiting this planet costs " << planets[planetsVisited-1].getAtmosphere() << " fuel." << endl;
      ship->setNumFuel(-1, planets[planetsVisited-1].getAtmosphere());
}

//explore event message and change resources
void exploreEvent(int planetNum, Ship* ship, Planet* planets){
  cout << planets[planetNum-1].getMessage();

  //resource is fuel
  if (planets[planetNum-1].getResource() == "crew"){
    ship->setNumCrew(planets[planetNum-1].getMult(), planets[planetNum-1].getCrew());
    //if losing a resource
    if(planets[planetNum-1].getMult() == -1){
      cout << "You lost " << planets[planetNum-1].getCrew() << " "<< planets[planetNum-1].getResource() << "."<< endl;
    }
    //if gaining a resource
    if(planets[planetNum-1].getMult() == 1){
      cout << "You gain " << planets[planetNum-1].getCrew() << " " << planets[planetNum-1].getResource() << "."<< endl;
    }
  }
  if (planets[planetNum-1].getResource() == "fuel"){
    ship->setNumFuel(planets[planetNum-1].getMult(), planets[planetNum-1].getFuel());
    if(planets[planetNum-1].getMult() == -1){
      cout << "You lost " << planets[planetNum-1].getFuel() << " "<< planets[planetNum-1].getResource() << "."<< endl;
    }
    if(planets[planetNum-1].getMult() == 1){
      cout << "You gain " << planets[planetNum-1].getFuel() << " " << planets[planetNum-1].getResource() << "."<< endl;
    }
  }
  if (planets[planetNum-1].getResource() == "money"){
    ship->setMoney(planets[planetNum-1].getMult(), planets[planetNum-1].getMoney());
    if(planets[planetNum-1].getMult() == -1){
      cout << "You lost " << planets[planetNum-1].getMoney() << " "<< planets[planetNum-1].getResource() << "."<< endl;
    }
    if(planets[planetNum-1].getMult() == 1){
      cout << "You gain " << planets[planetNum-1].getMoney() << " " << planets[planetNum-1].getResource() << "."<< endl;
    }
  }   
}

//check if resources are maxed or zero
void checkMax(Ship* ship){
  //check crew
  if(ship->getNumCrew() > ship->getMaxCrew()){
    ship->crewIsMax();
    cout << "You have reached max crew." << endl;
  }
  //check fuel
  if(ship->getNumFuel() > ship->getMaxFuel()){
    ship->fuelIsMax();
    cout << "You have reached max fuel." << endl;
  }
}
bool checkZero(Ship* ship){
  if (ship->getNumCrew() <= 0 || ship->getNumFuel() <= 0){
    return true;
  }
  return false;
}

//creating random event and changing resources
void randomEvent(Ship* ship){
  RandomEvent* event;
  
  //create random event
  int r = rand()%2;
  int response;
  if (r == 0){
    event = new StrangerInteractGood();
  }
  else{
    event = new StrangerInteractBad();
  }

  //print prompt
  cout << event->getRandomArt() << endl;
  event->printPrompt();
  //EXCEPTION
  cin >> response;

  //interacted = (true/0), ignored = (false/1)
  bool answer;
  if(response == 0){
    answer = true;
  }
  if(response == 1){
    answer = false;
  }

  //print appropriate ending
  printLineBreak();
  if(answer == event->getCorrect()){
    event->printGoodEnding();
  }
  else if(answer != event->getCorrect()){
    event->printBadEnding();
  }

  //change appropriate resource
  if (event->getResource() == "crew"){ 
    ship->setNumCrew(event->getMult(), event->getCrew());
    if(event->getMult() == -1){
      cout << "You lost " << event->getCrew() << " "<< event->getResource() << "." << endl;
    }
    if(event->getMult() == 1){
      cout << "You gain " << event->getCrew() << " " << event->getResource() << "." << endl;
    }
  }
  if (event->getResource() == "fuel"){
    ship->setNumFuel(event->getMult(), event->getFuel());
    if(event->getMult() == -1){
      cout << "You lost " << event->getFuel() << " "<< event->getResource() << "." << endl;
    }
    if(event->getMult() == 1){
      cout << "You gain " << event->getFuel() << " " << event->getResource() << "." << endl;
    }
  }
  if (event->getResource() == "money"){
    ship->setMoney(event->getMult(), event->getMoney());
    if(event->getMult() == -1){
      cout << "You lost " << event->getMoney() << " "<< event->getResource() << "." << endl;
    }
    if(event->getMult() == 1){
      cout << "You gain " << event->getMoney() << " " << event->getResource() << "." << endl;
    }
  } 
  
  delete event;
  event = nullptr;
}

//making purchases
Ship* shop(int _response, Ship* ship, bool& enoughMoney){
  int amount;
  //"Type 1: Buy more Crew"
  if (_response == 1){
    cout << "How many crew do you want to buy?" << endl;
    //EXCEPTION (has to be positive and an int)
    cin >> amount;
    
    if(amount+ship->getNumCrew() > ship->getMaxCrew()){
      cout << "You cannot make that purchase." << endl;
      return ship;
    }
    if(amount*ship->getCrewPrice() > ship->getMoney()){
      enoughMoney = false;
      return ship;
    }
    ship->setNumCrew(1, amount);
    ship->setMoney(-1, amount*ship->getCrewPrice());
  }
    
  //"Type 2: Buy more Fuel"
  else if (_response == 2){
    cout << "How much fuel do you want to buy?" << endl;
    //EXCEPTION (has to be positive and an int)
    cin >> amount;
    if(amount+ship->getNumCrew() > ship->getMaxFuel()){
      cout << "You cannot make that purchase." << endl;
      return ship;
    }
    if(amount*ship->getFuelPrice() > ship->getMoney()){
      enoughMoney = false;
      return ship;
    }
    ship->setNumFuel(1, amount);
    ship->setMoney(-1, amount*ship->getFuelPrice());
  }
  return ship;
}
Ship* upgrade(Ship* ship, bool& enoughMoney){
  //starter -> small
  if(ship->getShipType() == "Starter Ship"){
    SmallShip temp;
    if(ship->getMoney() < temp.getShipPrice()){
      enoughMoney = false;
      return ship;
    }
    ship->setMoney(-1, temp.getShipPrice());
    ship = new SmallShip(ship->getNumCrew(), ship->getNumFuel(), ship->getMoney());
  }
  //small -> medium
  else if(ship->getShipType() == "Small Ship"){
    MediumShip temp;
    if(ship->getMoney() < temp.getShipPrice()){
      enoughMoney = false;
      return ship;
    }
    ship->setMoney(-1, temp.getShipPrice());
    ship = new MediumShip(ship->getNumCrew(), ship->getNumFuel(), ship->getMoney());
  }
  //medium -> large
  else if(ship->getShipType() == "Medium Ship"){
    LargeShip temp;
    if(ship->getMoney() < temp.getShipPrice()){
      enoughMoney = false;
      return ship;
    }
    ship->setMoney(-1, temp.getShipPrice());
    ship = new LargeShip(ship->getNumCrew(), ship->getNumFuel(), ship->getMoney());
  }
  //already large
  else if(ship->getShipType() == "Large Ship"){
    cout << "Your ship is fully upgraded." << endl;
  }
  return ship;
}
void printShipPrices(){
  Ship * ship;
  ship = new SmallShip();
  cout << "(" << ship->getShipType() << ": $" << ship->getShipPrice() << "  ";
  ship = new MediumShip();
  cout << ship->getShipType() << ": $" << ship->getShipPrice() << "  ";
  ship = new LargeShip();
  cout << ship->getShipType() << ": $" << ship->getShipPrice() << ")" << endl;
  delete ship;
}

//loading
int difficultyNum(string word){
  if (word == "Easy"){return 0;}
  if(word == "Medium"){return 1;}
  if(word == "Hard"){return 2;}
}
int getPlanetNum(string type){
  if (type == "Rocky Planet") {return 0;}
  else if (type == "Oceanic Planet") {return 1;}
  else if (type == "Gaseous Planet") {return 2;}
  else if (type == "Tundra Planet") {return 3;} 
}

//final output
void countTotals(Planet* planet, int size, int& totalRocky, int& totalOcean, int& totalGas, int& totalTundra){
  string type;
  for (int i = 0; i < size; i++){
    type = planet[i].getPlanetType();
    if (type == "Rocky Planet"){
      totalRocky++;
    }
    else if (type == "Oceanic Planet"){
      totalOcean++;
    }
    else if (type == "Gaseous Planet"){
      totalGas++;
    }
    else if (type == "Tundra Planet"){
      totalTundra++;
    }
  }
}
void printSummary(Ship * ship, int planets, int challenged, int rocky, int ocean, int gas, int tundra){
  cout << "Planets explored:  " << planets << "/" << challenged << endl;
  cout << "Rocky............" << rocky << endl;
  cout << "Oceanic.........." << ocean << endl;
  cout << "Gaseous.........." << gas << endl;
  cout << "Tundra..........." << tundra << endl;
  cout << endl;
  ship->printStats();
}
void printSummaryArt(){
  cout << R"(                    ___..__              _..----....____
                __,'       ``--..__    .'    ,-._    _.-'
           ..--;'                  ``--._   (,;') _,'
        _;'                             \`-._`-','
  _..-''                                 -.._'-:
,'         ,---'`````````------...____..;--' ;__\-.
 `._                                    ____    |  |`
    `--.._                            ,'`````.  ;  ;`
          ``.._          __________   `.      \'__/`
               `-:._____/______/___/____`.     \  `
                              |       `._ `.    \
                              `._________`-.`.   `.___
                                              `------'`)" << endl;
}


int main(){
  int response; //used for menus
  int challengeNum = 0; //number of planets want to challenge
  int totalRocky = 0;
  int totalOcean = 0;
  int totalGas = 0;
  int totalTundra = 0;
  string ending; //says win lose or saving based on player choice
  
  int planetsVisited = 0;
  int randomPlanet; //planet where random event happens
  
  bool enoughMoney = true; //used when making purchases
  
  ifstream inFS; 
  string filename;
  ofstream outFS;
  
  Ship* ship_ptr = nullptr;
  Planet * planets_ptr = nullptr;
  
  srand(time(NULL));

  
  printWelcome();
  //EXCEPTION
  cin >> response;

  //newgame or save
  if(response == 1) {
    goto newGame;
  }
  else if(response == 2){
    goto loadGame;
  }

  newGame:
    //set number of planets to explore
    cout << "How many planets would you like to challenge?" << endl;
    //EXCEPTION (has to be positive number and an int)
    cin >> challengeNum;
    while(challengeNum <= 0){
      cout << "Please state a positive number of planets to challenge." << endl;
      cin >> challengeNum;
    }

    //create planets array, starter ship, planet number for random event
    planets_ptr = createPlanets(challengeNum);
    ship_ptr = new StarterShip();
    randomPlanet = rand()%challengeNum + 1;

    //output starting stats
    printLineBreak();
    cout << "New game created." << endl;
    ship_ptr->printStats();
    goto game;
  
  loadGame:
    cout << "What is the name of your save file?" << endl;
    cin >> filename;
    inFS.open(filename);
    if (!inFS.is_open()) {
      cout << "File not found." << endl;
      return 1;
    }
    inFS.exceptions(ifstream::failbit | ifstream::badbit);
    try{
      string tempType;
      int tempCrew;
      int tempFuel;
      int tempMoney;
      int randomEventNum;
      
      inFS >> planetsVisited;
      inFS >> challengeNum;
      inFS >> randomEventNum;
      randomPlanet = randomEventNum;
      
      inFS.ignore();

      //ship information
      getline(inFS, tempType);
      inFS >> tempCrew;
      inFS >> tempFuel;
      inFS >> tempMoney;
      inFS.ignore();
        
      //set ship
      if(tempType == "Starter Ship"){
        ship_ptr = new StarterShip(tempCrew, tempFuel, tempMoney);
      }
      else if(tempType == "Small Ship"){
        ship_ptr = new SmallShip(tempCrew, tempFuel, tempMoney);
      }
      else if(tempType == "Medium Ship"){
        ship_ptr = new MediumShip(tempCrew, tempFuel, tempMoney);
      }
      else if(tempType == "Large Ship"){
        ship_ptr = new LargeShip(tempCrew, tempFuel, tempMoney);
      }

      planets_ptr = new Planet [challengeNum];
      string ptype;
      int difNum; //easy = 0, medium = 1, large = 2 using setDifficutly()
      int messageNum; //used for planet constructor
      int typeNum; //rocky = 0, ocean = 1, gas = 2, tundra = 3
      for(int k = 0; k < challengeNum; k++){
        getline(inFS, ptype);
        inFS >> difNum;
        inFS >> messageNum;
        inFS.ignore();
        
        typeNum = getPlanetNum(ptype);
        if(typeNum == 0){planets_ptr[k] = Rocky(messageNum);}
        else if(typeNum == 1){planets_ptr[k] = Ocean(messageNum);}
        else if(typeNum == 2){planets_ptr[k] = Gas(messageNum);}
        else if(typeNum == 3){planets_ptr[k] = Tundra(messageNum);}
        planets_ptr[k].setDifficulty(difNum);
      }
    }
    catch(ifstream::failure &e){
      cout << "Failure to read file. Issue: " << e.what() << endl;
      return 1;
    }
    goto game;
  
  menu:
    printLineBreak();
    cout << "Would you like to:" << endl;
    cout << "Type 1: Explore the Next Planet" << endl;
    cout << "Type 2: Make a Purchase" << endl;
    cout << "Type 3: Save Game Progress" << endl;
    cin >> response;
    //EXCEPTION
    if(response == 1){
      goto game;
    }
    else if(response == 2){
      goto shop;
    }
    else if(response == 3){
      goto save;
    }

  game:
    //visit planet
    printLineBreak();
    planetsVisited++;
    cout << planets_ptr[planetsVisited-1].getPlanetArt() << endl;
    visitPlanet(planetsVisited, challengeNum, ship_ptr, planets_ptr);
    //check extreme
    if(checkZero(ship_ptr) == true){
        ending = "You lost the game D:";
        goto end;
    }
    
    //explore event
    exploreEvent(planetsVisited, ship_ptr, planets_ptr);
    //check for extremes
    if(planets_ptr[planetsVisited-1].getMult() == 1){
      checkMax(ship_ptr);
    }
    if(planets_ptr[planetsVisited-1].getMult() == -1){
      if(ship_ptr->getMoney() < 0){
        ship_ptr->moneyIsZero();
      }
      if(checkZero(ship_ptr) == true){
        ending = "You lost the game D:";
        goto end;
      }
    }
    //ship stats
    ship_ptr->printStats();

    //check if random event should happen and check extremes
    if(randomPlanet == planetsVisited){
      printLineBreak();
      randomEvent(ship_ptr);
      checkMax(ship_ptr);
      if(ship_ptr->getMoney() < 0){
        ship_ptr->moneyIsZero();
      }
      if(checkZero(ship_ptr) == true){
        ending = "You lost the game D:";
        goto end;
      }
    }
  
    //check if won the game
    if(planetsVisited == challengeNum){
      ending = "You won the game :D";
      goto end;
    }
    goto menu;
      
  shop:
    printLineBreak();
    cout << "Welcome to the Shop!" << endl;
    cout << "Type 1: Buy more Crew for $";
    cout << ship_ptr->getCrewPrice() << " each" << endl;
    cout << "Type 2: Buy more Fuel for $" ;
    cout << ship_ptr->getFuelPrice() << " each" << endl;
    cout << "Type 3: Upgrade Ship ";
    printShipPrices();

    //EXCEPTION
    cin >> response;
  
    if(response == 3){
      ship_ptr = upgrade(ship_ptr, enoughMoney);
    }
    else{
      ship_ptr = shop(response, ship_ptr, enoughMoney);
    }

    if(enoughMoney == false){
      cout << "You do not have enough money for that purchase." << endl;
      enoughMoney = true;
      goto menu;
    }

    ship_ptr->printStats();
    goto menu;
  
  save:
    outFS.open("output.txt");
    /*  SAVE FILE FORMAT
    planets visited
    challenged planets
    random event planet number
    ship type (string)
    num crew
    num fuel
    money
    planet type (string)
    difficulty num (easy = 0, medium = 1, hard = 2)
    message num
    ...
      */
    outFS << planetsVisited << endl;
    outFS << challengeNum << endl;
    outFS << randomPlanet << endl;
    outFS << ship_ptr->getShipType() << endl;
    outFS << ship_ptr->getNumCrew() << endl;
    outFS << ship_ptr->getNumFuel() << endl;
    outFS << ship_ptr->getMoney() << endl;
    for(int j = 0; j < challengeNum; j++){
      outFS << planets_ptr[j].getPlanetType() << endl;
      outFS << difficultyNum(planets_ptr[j].getDifficulty()) << endl;
      outFS << planets_ptr[j].getMessageNum() << endl;
    }
    
    outFS.close();
    countTotals(planets_ptr, planetsVisited, totalRocky, totalOcean,  totalGas, totalTundra);
    ending = "Your progress has been saved!";
    goto summary;
  
  
  end: 
    countTotals(planets_ptr, planetsVisited, totalRocky, totalOcean,  totalGas, totalTundra);
    goto summary;

  summary:
    printLineBreak();
    printSummaryArt();
    cout << ending << endl << endl;
    printSummary(ship_ptr, planetsVisited, challengeNum, totalRocky, totalOcean, totalGas, totalTundra);
    
    if (ship_ptr != nullptr){
      delete ship_ptr;
    }
    if(planets_ptr != nullptr) {
      delete [] planets_ptr;
    }
}
