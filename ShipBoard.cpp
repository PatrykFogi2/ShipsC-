#include <iostream> 
#include "ShipBoard.h"
using namespace std;

ShipBoard::ShipBoard () {
  this -> width = width;
  this -> height = height;
     
     
     for (int row=0; row<height; row++) 
    {
      for (int column=0; column<width; column++)
        {
           board[row][column] = {false,false};
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



void ShipBoard::SetShip(int row, int col, enum Direct, int i) {

}
