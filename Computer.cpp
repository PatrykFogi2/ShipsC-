#include "Computer.h"
#include <iostream>
#include <ctime>
using namespace std;

Computer::Computer(ShipBoard&Board) :Board(Board) {
  
   srand( time( NULL ) );
 
   this -> Action = Action; 
     this -> HitShip = HitShip;
  
  
   for (int row=0; row<height; row++) 
    {
      for (int column=0; column<width; column++)
        {
           ComputerBoard[row][column] = {false,false,false};
        }
    }

}


void Computer::ComputerDisplay()  {
  cout <<"  A   B   C   D   E   F   G   H   I   J"<<endl;
int i = 0;
 for(int row=0; row<height; row++)
    { cout << i ;
    i++;
        for(int column=0; column<width; column++)
        {
          if(ComputerBoard[row][column].hasShip == true)
            cout<< "[M";
          else
          cout <<"[.";
          if(ComputerBoard[row][column].hasShot == true)
            cout<< "B";
          else
          cout <<".]";
        //   if(ComputerBoard[row][column].hasShip ==1 && ComputerBoard[row][column].hasShot && ComputerCheckFieldsAround(row,column) == 8 )
        //   Zatopiony(row, column);
        }
        cout <<"\n" <<endl;
    }
    cout <<"--------------------------------------------- "<< endl;
}


void Computer::Shot(int row, int col) {
 int a = 0;

Board.SETSHOT(row, col);
if(Board.hasShip(row,col) == 1) { Action ++;
    // Board.SETSHOT(row, col);
    while (a == 0) {
        int x = Random() ; int y = Random(); 
        cout << x << y << endl;
        Board.SETSHOT(x, y);
        if(Board.hasShip(x,y) == 1) {
        a =0; Action++;}
        else 
        a++;
    } }
else



return;

}
    





int Computer::Random () const {
  int x = 0;
  x = (rand()%10) ;
  return x;
}


void Computer::GenerateShip(int TypeShip) {
    int row = Random(); int col = Random(); int kierunek =rand()%2 ; Direct turn;
     cout << row << col << kierunek << endl; 
 
    if(kierunek ==1 )
        turn = RIGHT;
    else 
        turn = DOWN;

    void(SetShip(row,col,TypeShip,turn));
}






int Computer::SetShip(int row, int col, int TypeShip, Direct kierunek) {
// pojedyczny
int g = 0;
if(TypeShip == 1 && ComputerCheckFieldsAround(row,col) == 8 ) {
    ComputerBoard[row][col].hasShip = 1;
    int g =1; return g; }
    
//podwojny
// if(TypeShip==2 && CheckFieldsAround(row,col) == 8 ) {
//     board[row][col].hasShip = 1;
    if(TypeShip==2 && ComputerCheckFieldsAround(row,col) == 8 && kierunek == RIGHT && ComputerCheckFieldsAround(row, col+1) == 8) {
    ComputerBoard[row][col].hasShip = 1;
    ComputerBoard[row][col+1].hasShip = 1;
    int g =1; return g; }
    
    if(TypeShip==2 && ComputerCheckFieldsAround(row,col) == 8 &&kierunek == DOWN && ComputerCheckFieldsAround(row+1, col) == 8) {
    ComputerBoard[row][col].hasShip = 1;
    ComputerBoard[row+1][col].hasShip = 1;
     int g =1; return g; }
    
// }
// else 
//     board[row][col].hasShip = 0;   

// if(TypeShip==3 && CheckFieldsAround(row,col) ==8  ) {
//     board[row][col].hasShip = 1;
   if(TypeShip==3 && ComputerCheckFieldsAround(row,col) ==8  && kierunek == RIGHT && ComputerCheckFieldsAround(row, col+1) == 8 && ComputerCheckFieldsAround(row, col+2)==8 ) {
   ComputerBoard[row][col].hasShip = 1;
    ComputerBoard[row][col+1].hasShip = 1;
    ComputerBoard[row][col+2].hasShip = 1;
     int g =1; return g; }
   if( TypeShip==3 && ComputerCheckFieldsAround(row,col) ==8 && kierunek == DOWN && ComputerCheckFieldsAround(row+1, col) == 8 && ComputerCheckFieldsAround(row+2, col)==8 ){
    ComputerBoard[row][col].hasShip = 1;   
   ComputerBoard[row+1][col].hasShip = 1;  
 ComputerBoard[row+2][col].hasShip = 1;
  int g =1; return g; } 





   if(TypeShip==4 && ComputerCheckFieldsAround(row,col) ==8  && kierunek == RIGHT && ComputerCheckFieldsAround(row, col+1) == 8 && ComputerCheckFieldsAround(row, col+2)==8 && ComputerCheckFieldsAround(row, col+3)==8 ) {
   ComputerBoard[row][col].hasShip = 1;
   ComputerBoard[row][col+1].hasShip = 1;
   ComputerBoard[row][col+2].hasShip = 1; 
   ComputerBoard[row][col+3].hasShip = 1;
    int g =1; return g;}
   if(TypeShip==4 && ComputerCheckFieldsAround(row,col) ==8  && kierunek == DOWN && ComputerCheckFieldsAround(row+1, col) == 8 && ComputerCheckFieldsAround(row+2, col)==8 && ComputerCheckFieldsAround(row+3, col)==8){
   ComputerBoard[row][col].hasShip = 1;
   ComputerBoard[row+1][col].hasShip = 1;  
 ComputerBoard[row+2][col].hasShip = 1;
  ComputerBoard[row+3][col].hasShip = 1; 
   int g =1; return g;} 
    

// if(TypeShip==5 && CheckFieldsAround(row,col) ==8  ) {
//     board[row][col].hasShip = 1;
   if(TypeShip==5 && ComputerCheckFieldsAround(row,col) ==8 && kierunek == RIGHT && ComputerCheckFieldsAround(row, col+1) == 8 && ComputerCheckFieldsAround(row, col+2)==8 && ComputerCheckFieldsAround(row, col+3)==8  && ComputerCheckFieldsAround(row, col+4)==8) {
 ComputerBoard[row][col].hasShip = 1;
   ComputerBoard[row][col+1].hasShip = 1;
  ComputerBoard[row][col+2].hasShip = 1; 
  ComputerBoard[row][col+3].hasShip = 1;
 ComputerBoard[row][col+4].hasShip = 1;
  int g =1; return g;}
   if(TypeShip==5 && ComputerCheckFieldsAround(row,col) ==8 && kierunek == DOWN && ComputerCheckFieldsAround(row+1, col) == 8 && ComputerCheckFieldsAround(row+2, col)==8 && ComputerCheckFieldsAround(row+3, col)==8 && ComputerCheckFieldsAround(row+4, col)==8) {
   ComputerBoard[row][col].hasShip = 1;
    ComputerBoard[row+1][col].hasShip = 1;  
    ComputerBoard[row+2][col].hasShip = 1;
   ComputerBoard[row+3][col].hasShip = 1;
   ComputerBoard[row+4][col].hasShip = 1; 
    int g =1; return g;} 
    return g;}






//////////////////////////////////////////////////////////////////////////////////////////




   int Computer::ComputerCheckFieldsAround(int row, int col) {
  int i = 0;
  
  if(IsInside(row,col)== 0)
    return -1;
  
  if(ComputerBoard[row][col].hasShip ==1) 
    return -1;

  if(ComputerBoard[row][col].BookSpace == 1)
    return -1; 

   else
    {
      if( ComputerBoard[row-1][col-1].BookSpace == 0 && ComputerBoard[row-1][col-1].hasShip==0)
       i++;
      if(ComputerBoard[row-1][col].BookSpace == 0 && ComputerBoard[row-1][col].hasShip==0)
        i++;
      if( ComputerBoard[row-1][col+1].BookSpace == 0 && ComputerBoard[row-1][col+1].hasShip==0)
        i++;
      if( ComputerBoard[row][col+1].BookSpace == 0 && ComputerBoard[row][col+1].hasShip==0)
        i++;
      if(  ComputerBoard[row][col-1].BookSpace == 0 && ComputerBoard[row][col-1].hasShip==0 )
       i++;
      if(  ComputerBoard[row+1][col].BookSpace == 0 && ComputerBoard[row+1][col].hasShip==0)
        i++;
      if(  ComputerBoard[row+1][col+1].BookSpace == 0 && ComputerBoard[row+1][col+1].hasShip==0)
        i++;
      if( ComputerBoard[row+1][col-1].BookSpace == 0 && ComputerBoard[row+1][col-1].hasShip==0)
        i++;
    }
    return i; 
}


bool Computer::IsInside(int row, int col) {
    if(row>=height || col>=width || row<0 || col <0)
    return false;
  return true;
}


bool Computer::GetShot(int row, int col) {

  if(ComputerBoard[row][col].hasShip ==1 && ComputerBoard[row][col].hasShot == 0  ) {
      HitShip ++;
      ComputerBoard[row][col].hasShot = 1 ;
      cout <<HitShip << endl;
      return 1;
  }
    ComputerBoard[row][col].hasShot = 1 ;
    return 0;

}




GameState Computer::getGameState() const {
    if(HitShip == 20)
     return FINISHED_WIN;
    if(Action == 20)
     return FINISHED_LOSS;
    return RUNNING;
}


void Computer::Zatopiony (int row, int col) {
    
        ComputerBoard[row+1][col+1].isRevealed = 1;
        ComputerBoard[row-1][col-1].isRevealed = 1;
        ComputerBoard[row+1][col].isRevealed = 1;
        ComputerBoard[row-1][col].isRevealed = 1;
        ComputerBoard[row][col+1].isRevealed = 1;
        ComputerBoard[row][col-1].isRevealed = 1;
        ComputerBoard[row-1][col+1].isRevealed = 1;
        ComputerBoard[row+1][col-1].isRevealed = 1;  }


     


bool Computer::hasShip(int row, int col) {
  if(ComputerBoard[row][col].hasShip==1)
    return 1; 
  return 0;
}
bool  Computer::hasShot(int row, int col) {
   if(ComputerBoard[row][col].hasShot==1)
    return 1; 
  return 0;
}