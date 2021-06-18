#include <iostream>
#include "ShipBoard.h"
using namespace std;
int main() {
  std::cout << "Hello World!\n";
 ShipBoard plansza;
 plansza.display();
 
//  plansza.UstawStatki(0, 0, 2, DOWN);
 //  plansza.UstawStatki(1, 1, 2, RIGHT);
    plansza.UstawStatki(8, 0, 2, RIGHT);
    plansza.UstawStatki(2, 0, 5, DOWN);
    
 plansza.display();
cout << plansza.CheckFieldsAround(0, 1);

  
//   cout << plansza.getBoardWidth();
//   cout << plansza.getBoardHeight();



}


