#ifndef SHIPB_H__
#define SHIPB_H__



enum GameState {FINISHED_WIN, FINISHED_LOSS, RUNNING};
enum ShotDirect {UP,DOWN,RIGHT,LEFT};

struct Field {
bool hasShip;
bool hasShot;
// bool isRevealed;

};



class ShipBoard {
int width = 10;
int height = 10;




public:
  ShipBoard();

GameState state;
Field board[10][10];
bool hasShip;
bool hasShot;
bool isRevealed;
void Shot() const;
void display() const;
void generate();
void CheckFieldsAround();
GameState getGameState() const;
char getFieldInfo(int row, int col) const;
int getBoardWidth() const;
int getBoardHeight() const;
void Random(); 





};







#endif
