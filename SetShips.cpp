#include "SetShips.h"

#include <iostream>

using namespace std;

SetShips::SetShips(ShipBoard & gracz, Computer & komp): Board(gracz), AI(komp) {

}

void SetShips::Playerplay() {
  int row, col;
  int x;
  int i = 4;
  int z = 1;

  Direct kierunek;
  cout << "Zaczynamy od rozłożenia statków na planszy - podajemy cyfry" << endl;
  Board.display();

  while (i != 0) {

    for (int j = 0; j < z; j++) {
      cout << i << "  Masztowiec: Pierwsze pole rzad, drugie kolumna, trzecie kierunek ( 0 - dol 1 prawo)" << endl;
      cin >> row >> col >> x;

      if (x == 0)
        kierunek = DOWN;
      else {
        kierunek = RIGHT;
      }

      if (Board.UstawStatki(row, col, i, kierunek) == 0) {
        j--;
      }
      Board.display();
    }
    i--;
    z++;
  }

}

void SetShips::ComputerPlay() {

  int row, col;
  int x;
  int i = 4;
  int z = 1;
  Direct kierunek;
  while (i != 0) {

    for (int j = 0; j < z; j++) {

      int row = AI.Random();
      int col = AI.Random();
      int x = rand() % 2;

      if (x == 0)
        kierunek = DOWN;
      else {
        kierunek = RIGHT;
      }

      if (AI.SetShip(row, col, i, kierunek) == 0) {
        j--;
      }
      // AI.ComputerDisplay();
    }
    i--;
    z++;

  }
  AI.ComputerDisplay();
}

void SetShips::Play() {

  ComputerPlay();
  Playerplay();
  int row;
  int col;
  cout << "Rozpoczynamy rozgrywke" << endl;

  while (AI.getGameState() == RUNNING) {
    int i = 0;
    AI.Shot(AI.Random(), AI.Random());

    if (AI.getGameState() == FINISHED_WIN) {
      cout << "Wygrales" << endl;
      return;
    }

    if (AI.getGameState() == FINISHED_LOSS) {
      cout << "Przegrales" << endl;
      return;
    }

    Board.display();
    while (i == 0) {
      cout << "Podaj koordynaty do strzału" << endl;
      cin >> row >> col;
      //  AI.GetShot(row,col);
      if (AI.GetShot(row, col) == 0) {
        cout << " Pudło" << endl;
        cout << "Plansza Komputer" << endl;
        AI.ComputerDisplay();
        i = 1;
      } else {
        cout << "Trafiony" << endl;
        cout << "Plansza Komputer" << endl;
        AI.ComputerDisplay();
      }

      if (AI.getGameState() == FINISHED_WIN) {
        cout << "Wygrales" << endl;
        return;
      }

      if (AI.getGameState() == FINISHED_LOSS) {
        cout << "Przegrales" << endl;
        return;
      }

    }

  }
}