#ifndef SFMLSHIPS_H__
#define SFMLSHIPS_H__
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Computer.h"





using namespace sf;

class MSSFMLView
{
	
   ShipBoard &Board;
Computer &AI;


  
     RectangleShape zakryte;
     RectangleShape odkryte;
     RectangleShape strzal;
    Font font;
    Text txt;
    Text tekst;
 
    
     RectangleShape linia_poz;
     RectangleShape linia_pion;
   
       RectangleShape linia_poz2;
     RectangleShape linia_pion2;
     
public:
	//  MSSFMLView(ShipBoard &plansza, Computer &AI);
    MSSFMLView(ShipBoard &gracz, Computer&komp);
	void draw (sf::RenderWindow & win);
};





#endif
