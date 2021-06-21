#include <iostream>
#include "SFMLSHIP.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ShipBoard.h"
#include "Computer.h"
using namespace sf;
using namespace std;

MSSFMLView::MSSFMLView(ShipBoard &gracz, Computer &komp) :Board(gracz),AI( komp){

      zakryte = RectangleShape(Vector2f(30,30));
    zakryte.setFillColor(Color(128,0,0));
    linia_poz = RectangleShape(Vector2f(30,1));
    linia_poz.setFillColor(Color(128,0,0));
    
    strzal = RectangleShape(Vector2f(30,30));
    strzal.setFillColor(Color(0,255,0));


    linia_pion = RectangleShape(Vector2f(1,30));
    linia_pion.setFillColor(Color(128,0,0));
    odkryte = RectangleShape(Vector2f(30,30));
     odkryte.setFillColor(Color(135,120,135));


    linia_poz2 = RectangleShape(Vector2f(30,1));
    linia_poz2.setFillColor(Color(128,0,0));
    
    linia_pion2 = RectangleShape(Vector2f(1,30));
    linia_pion2.setFillColor(Color(128,0,0));
}





void MSSFMLView::draw (sf::RenderWindow &win) {
    

    int wysokosc = 600;
  int szerokosc =800;
  int height = Board.getBoardHeight();
  int width = Board.getBoardWidth();
  
  
   for (int row=0; row < height; row++) {
      for(int col =0; col<width; col++) {
  int a,b; 
    // a = szerokosc/2 + col * 30 - (height*30/2) ;
    // b = wysokosc/2 + row * 30 - (width*30/2);
      a = szerokosc/10 + col * 30 ;
      b = wysokosc/10 + row * 30 ;
         //player
            odkryte.setPosition(a,b);
            win.draw(odkryte);
            linia_pion.setPosition(a,b); 
           linia_poz.setPosition(a,b); 
           win.draw(linia_pion);
           win.draw(linia_poz);
            //AI
             odkryte.setPosition(a+360,b);
            win.draw(odkryte);
            linia_pion2.setPosition(a+360,b); 
           linia_poz2.setPosition(a+360,b); 
           linia_pion2.setFillColor(Color(0,0,255));
           linia_poz2.setFillColor(Color(0,0,255));
           win.draw(linia_pion2);
           win.draw(linia_poz2);

    if(Board.hasShip(row,col) == 1) {
        zakryte.setPosition(a,b);
        win.draw(zakryte);
    }

   

if( AI.hasShip( row, col) == 1 ) {
      zakryte.setPosition(a+360,b);
        win.draw(zakryte); }


if(Board.hasShot(row,col) == 1) {
        strzal.setPosition(a,b);
        win.draw(strzal);
    }


    if(AI.hasShot(row,col) == 1) {
        strzal.setPosition(a+360,b);
        win.draw(strzal);
    }


    if(Board.hasShip(row,col) == 1 && Board.hasShot(row,col) ==1 ) {
        strzal.setPosition(a,b);
        win.draw(strzal);
    }


    if( AI.hasShip( row, col) == 1 && AI.hasShot( row,col) == 1 ) {
      strzal.setPosition(a+360,b);
        win.draw(strzal); }




 
  

} } 






// if (AI.getGameState() == FINISHED_WIN ) {
//   cout << "Wygrales" << endl; 
//   return;}

// if(AI.getGameState() == FINISHED_LOSS) {
//   cout << "Przegrales" << endl; 
//   return;} 

// int i = 0;

//  while(i == 0 ) {
//      int row; int col;
//  cout <<"Podaj koordynaty do strzału" << endl; 
//  cin >> row >> col ;
// //  AI.GetShot(row,col);
//  if (AI.GetShot(row,col) == 0) {
//  cout <<" Pudło" << endl;
//  cout <<"Plansza Komputer" << endl;
// //  AI.ComputerDisplay();
//  i =1; }
//  else {  
//  cout << "Trafiony" << endl;
// cout <<"Plansza Komputer" << endl;
// // AI.ComputerDisplay(); }

// if (AI.getGameState() == FINISHED_WIN ) {
//   cout << "Wygrales" << endl; 
//   return;}

// if(AI.getGameState() == FINISHED_LOSS) {
//   cout << "Przegrales" << endl; 
//   return;}
//  }

  }