#include "SFML/Graphics.hpp"

#include "SFML/Window.hpp"

#include "ShipBoard.h"

#include "SFMLSHIP.h"

#include "Computer.h"

#include "SetShips.h"

#include <iostream>

using namespace std;
// to powinno być w osobnych plikach !

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Grafika w C++/SFML");
  window.setVerticalSyncEnabled(false);
  window.setFramerateLimit(1);

  ShipBoard plansza;
  Computer AI(plansza);
  SetShips Gierka(plansza, AI);
  MSSFMLView view(plansza, AI);

  Gierka.Playerplay();
  Gierka.ComputerPlay();

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // window.clear();
    while (AI.getGameState() == RUNNING) {
      view.draw(window);
      window.display();

      if (AI.getGameState() == FINISHED_WIN) {
        cout << "Wygrales" << endl;
      }

      if (AI.getGameState() == FINISHED_LOSS) {
        cout << "Przegrales" << endl;
      }

      int i = 0;

      while (i == 0) {
        int row;
        int col;
        cout << "Podaj koordynaty do strzału" << endl;
        cin >> row >> col;

        if (AI.GetShot(row, col) == 0) {
          cout << " Pudło" << endl;
          cout << "Plansza Komputer" << endl;

          i = 1;
        } else {
          cout << "Trafiony" << endl;
          cout << "Plansza Komputer" << endl;

          if (AI.getGameState() == FINISHED_WIN) {
            cout << "Wygrales" << endl;
            i = 0;
          }

          if (AI.getGameState() == FINISHED_LOSS) {
            cout << "Przegrales" << endl;
            i = 0;
          }
        }
        view.draw(window);
        window.display();

      }
      AI.Shot(AI.Random(), AI.Random());
      view.draw(window);
      window.display();
      window.clear();
    }

    return 0;
  }
}