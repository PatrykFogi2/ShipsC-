#include <iostream>
#include "ShipBoard.h"
#include "Computer.h"
#include "SetShips.h"
using namespace std;
int main() {
  std::cout << "Hello World!\n";
 ShipBoard plansza;

 Computer Testowy(plansza);
 SetShips gierka(plansza,Testowy);
 gierka.Play();
//  Testowy.ComputerDisplay();
//  Testowy.GenerateShip(2); 
//   Testowy.GenerateShip(3); 
//  Testowy.GenerateShip(4); 
//  Testowy.ComputerDisplay();



}


