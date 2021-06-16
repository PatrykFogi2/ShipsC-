#ifndef SHIPB_H__
#define SHIPB_H__



enum GameState {FINISHED_WIN, FINISHED_LOSS, RUNNING};
enum Direct {UP,DOWN,RIGHT,LEFT};

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
bool hasShip(int row, int col);
bool hasShot(int row, int col);

void Shot(int row, int col) const;
void display() const; // jest
void SetShip(int row, int col, enum Direct,int i);
void CheckFieldsAround(int row, int col);
GameState getGameState() const;
char getFieldInfo(int row, int col) const;
int getBoardWidth() const;  // jest
int getBoardHeight() const;  // jest
void Random(); 
bool IsInside(int row, int col); // jest





};







#endif
