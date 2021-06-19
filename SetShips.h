#ifndef SETSHIPS_H__
#define SETSHIPS_H__
#include "Computer.h"
#include "ShipBoard.h"

class SetShips {
ShipBoard &Board;
Computer &AI;


public:
SetShips(ShipBoard &gracz, Computer&komp);

void ComputerPlay();
void Playerplay();
void Play();

};


#endif