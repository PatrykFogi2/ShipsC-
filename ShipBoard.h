#ifdef SHIPBOARd_H__
#define SHIPBOARd_H__
#include <iostream>
using namespace std;


enum Gamestate {FINISHED_WIN, FINISHED_LOSS, RUNNING}
enum ShotDirect {UP,DOWN,RIGHT,LEFT};

struct Field {
bool hasShip
bool hasShot
bool isRevealed

};



class ShipBoard {





public:

ShipBoard();
int width = 10;
int height = 10;
Gamestate state;
FieldBoard[10][10];
bool hasShip;
bool hasShot;
bool isRevealed;
void Shot() const;
void display() const;
void generate();
void CheckFieldsAround;
GameState getGameState() const;
char getFieldInfo(int row, int col) const;
int getBoardWidth const;
int getBoardHeight;
void Random; 





};







#endif
