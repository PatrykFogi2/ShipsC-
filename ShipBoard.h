#ifndef SHIPB_H__
#define SHIPB_H__



enum GameState {FINISHED_WIN, FINISHED_LOSS, RUNNING};
enum Direct {UP,DOWN,RIGHT,LEFT};

struct Field {
bool hasShip;
bool hasShot;
bool BookSpace;
// bool isRevealed;

};



class ShipBoard {
int width = 10;
int height = 10;
// int Action = 0;
// int HitShip = 0;


public:
  ShipBoard();
  virtual ~ShipBoard(){}
Direct direct;
GameState state;
Field board[12][12];
bool hasShip(int row, int col); // jest
bool hasShot(int row, int col); // jest
bool BookSpace(int row,int col);
void Direction();
void Shot(int row, int col) ; // jest
void display() const; // jest
void SetShip(int row, int col, int TypeShip, Direct kierunek);
int CheckFieldsAround(int row, int col) ;

char getFieldInfo(int row, int col) const; // jest
int getBoardWidth() const;  // jest
int getBoardHeight() const;  // jest
void Random(); 
bool IsInside(int row, int col); // jest
bool Sunk(int row,int col);
int UstawStatki(int row, int col, int TypeShip, Direct kierunek);
void SETSHOT (int row, int col);



};







#endif
