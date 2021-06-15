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





