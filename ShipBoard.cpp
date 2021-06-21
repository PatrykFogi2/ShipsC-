#include <iostream> 
#include "ShipBoard.h"
using namespace std;

ShipBoard::ShipBoard () {
  this -> width = width;
  this -> height = height;
     //liczba pól statkow = 36
    //  this -> Action = Action; 
    //  this -> HitShip = HitShip;
     for (int row=0; row<height; row++) 
    {
      for (int column=0; column<width; column++)
        {
           board[row][column] = {false,false,false};
        }
    }
 
}





void ShipBoard::display () const {

cout <<"  A   B   C   D   E   F   G   H   I   J"<<endl;
int i = 0;
 for(int row=0; row<height; row++)
    { cout << i ;
    i++;
        for(int column=0; column<width; column++)
        {
          if(board[row][column].hasShip == true)
            cout<< "[M";
          else
          cout <<"[.";
          if(board[row][column].hasShot == true)
            cout<< "B";
          else
          cout <<".]";
       
        }
        cout <<"\n" <<endl;
    }
    cout <<"--------------------------------------------- "<< endl;
}





int ShipBoard::getBoardWidth() const {
  return width;
}

int ShipBoard::getBoardHeight() const {
  return height;
}

bool ShipBoard::IsInside(int row, int col) {
    if(row>=height || col>=width || row<0 || col <0)
    return false;
  return true;
}


bool ShipBoard::hasShip(int row, int col) {
  if(board[row][col].hasShip==1)
    return 1; 
  return 0;
}
bool ShipBoard::hasShot(int row, int col) {
   if(board[row][col].hasShot==1)
    return 1; 
  return 0;
}


bool ShipBoard::BookSpace(int row, int col) {
    if(board[row][col].BookSpace == 1)
    return 1;
    return 0;
}



void ShipBoard::SetShip(int row, int col, int TypeShip,Direct kierunek) {

int a = 0;
 
if (IsInside(row, col) == 1 && kierunek ==DOWN ) {



while ( a < TypeShip) {
 
    board[row+a][col].hasShip = 1;
    a++;
    // Action ++; 
    }


}

if (IsInside(row, col) == 1 && kierunek ==RIGHT ) {



while ( a < TypeShip) {
    board[row][col+a].hasShip = 1;
    a++; 
    // Action ++;
    }


}

return;
}






void ShipBoard::Shot(int row, int col)  {
    if(board[row][col].hasShot == 0)
        board[row][col].hasShot = true;
    else 
    cout <<"Juz strzelales" << endl;
    return; 
}

char ShipBoard::getFieldInfo(int row, int col) const {
   
    
   
    if(board[row][col].hasShip == 1 )
            return 'S' ;
    if(board[row][col].hasShot == 1 ) 
            return 'F'; 
    if(board[row][col].hasShot == 1 && board[row][col].hasShip == 1) 
            return 'T';
     return' ';       
                


}


// bool ShipBoard::Sunk(int row,int col) {
    
// }

// GameState ShipBoard::getGameState() const {
//     if(Action == 36)
//     return FINISHED_WIN;
//     else 
//     return RUNNING;
// }


int ShipBoard::UstawStatki(int row, int col, int TypeShip, Direct kierunek) {
// pojedyczny 
int g =0;
if(TypeShip == 1 && CheckFieldsAround(row,col) == 8 ) {
    board[row][col].hasShip = 1; 
    g=1; return g; }
    
//podwojny

    if(TypeShip==2 && CheckFieldsAround(row,col) == 8 && kierunek == RIGHT && CheckFieldsAround(row, col+1) == 8) {
    board[row][col].hasShip = 1;
    board[row][col+1].hasShip = 1; 
    g=1;  return g;}
    
    if(TypeShip==2 && CheckFieldsAround(row,col) == 8 &&kierunek == DOWN && CheckFieldsAround(row+1, col) == 8) {
    board[row][col].hasShip = 1;
    board[row+1][col].hasShip = 1; 
    g=1;  return g;}
    

   if(TypeShip==3 && CheckFieldsAround(row,col) ==8  && kierunek == RIGHT && CheckFieldsAround(row, col+1) == 8 && CheckFieldsAround(row, col+2)==8 ) {
   board[row][col].hasShip = 1;
    board[row][col+1].hasShip = 1;
    board[row][col+2].hasShip = 1; 
    g=1;  return g;}
   if( TypeShip==3 && CheckFieldsAround(row,col) ==8 && kierunek == DOWN && CheckFieldsAround(row+1, col) == 8 && CheckFieldsAround(row+2, col)==8 ){
    board[row][col].hasShip = 1;   
    board[row+1][col].hasShip = 1;  
    board[row+2][col].hasShip = 1;
    g=1; return g; } 





   if(TypeShip==4 && CheckFieldsAround(row,col) ==8  && kierunek == RIGHT && CheckFieldsAround(row, col+1) == 8 && CheckFieldsAround(row, col+2)==8 && CheckFieldsAround(row, col+3)==8 ) {
    board[row][col].hasShip = 1;
    board[row][col+1].hasShip = 1;
    board[row][col+2].hasShip = 1; 
    board[row][col+3].hasShip = 1;
    g=1; return g;}
   if(TypeShip==4 && CheckFieldsAround(row,col) ==8  && kierunek == DOWN && CheckFieldsAround(row+1, col) == 8 && CheckFieldsAround(row+2, col)==8 && CheckFieldsAround(row+3, col)==8){
    board[row][col].hasShip = 1;
    board[row+1][col].hasShip = 1;  
    board[row+2][col].hasShip = 1;
    board[row+3][col].hasShip = 1;
    g=1; return g; } 
    


   if(TypeShip==5 && CheckFieldsAround(row,col) ==8 && kierunek == RIGHT && CheckFieldsAround(row, col+1) == 8 && CheckFieldsAround(row, col+2)==8 && CheckFieldsAround(row, col+3)==8  && CheckFieldsAround(row, col+4)==8) {
    board[row][col].hasShip = 1;
    board[row][col+1].hasShip = 1;
    board[row][col+2].hasShip = 1; 
    board[row][col+3].hasShip = 1;
    board[row][col+4].hasShip = 1;
    
    g=1;
    
    return g;}
   if(TypeShip==5 && CheckFieldsAround(row,col) ==8 && kierunek == DOWN && CheckFieldsAround(row+1, col) == 8 && CheckFieldsAround(row+2, col)==8 && CheckFieldsAround(row+3, col)==8 && CheckFieldsAround(row+4, col)==8) {
    board[row][col].hasShip = 1;
    board[row+1][col].hasShip = 1;  
    board[row+2][col].hasShip = 1;
    board[row+3][col].hasShip = 1;
    board[row+4][col].hasShip = 1; 
    g=1;
    

    return g;} 



  return g;

}

void ShipBoard::SETSHOT(int row, int col) {
    board[row][col].hasShot =1 ;
}


int ShipBoard::CheckFieldsAround(int row, int col)  
{
  int i = 0;
  
  if(IsInside(row,col)== 0)
    return -1;
  
  if(board[row][col].hasShip ==1) 
    return -1;

  if(board[row][col].BookSpace == 1)
    return -1; 

   else
    {
      if( board[row-1][col-1].BookSpace == 0 && board[row-1][col-1].hasShip==0)
       i++;
      if(board[row-1][col].BookSpace == 0 && board[row-1][col].hasShip==0)
        i++;
      if( board[row-1][col+1].BookSpace == 0 && board[row-1][col+1].hasShip==0)
        i++;
      if( board[row][col+1].BookSpace == 0 && board[row][col+1].hasShip==0)
        i++;
      if(  board[row][col-1].BookSpace == 0 && board[row][col-1].hasShip==0 )
       i++;
      if(  board[row+1][col].BookSpace == 0 && board[row+1][col].hasShip==0)
        i++;
      if(  board[row+1][col+1].BookSpace == 0 && board[row+1][col+1].hasShip==0)
        i++;
      if( board[row+1][col-1].BookSpace == 0 && board[row+1][col-1].hasShip==0)
        i++;
    }
    return i; 
}





