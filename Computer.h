#ifndef COMPUTER_H__    
#define COMPUTER_H__  
#include "ShipBoard.h"



class Computer  {
ShipBoard &Board;
int height = Board.getBoardHeight();
 int width = Board.getBoardWidth(); 
 int Action = 0;
int HitShip = 0;
public:
  Computer(ShipBoard &board);
  Field ComputerBoard[12][12];
void ComputerDisplay() ; //dziala
void Shot(int row, int col) ; //dziala
int Random() const; //dziala
void GenerateShip(int TypeShip);
int SetShip(int row, int col, int TypeShip, Direct kierunek);
int ComputerCheckFieldsAround(int row, int col) ; 
bool IsInside(int row, int col); //dziala
bool GetShot(int row, int col);
GameState getGameState() const; // jest
void Zatopiony (int row, int col);
bool hasShot(int row,int col);
bool hasShip(int row,int col);
};





#endif