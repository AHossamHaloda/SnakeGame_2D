#include <iostream>
#include "gameManager.hpp"

int main() {

  /* Inistantize GameManager Object */
  GameManager gameManager;

  /* Run Game Init */
  gameManager.gameInit();

  /* Run Game MainFunction */
  gameManager.gameMainFunction();

  std::cout << "Game has terminated successfully!\n";
  // std::cout << "Score: " << game.GetScore() << "\n";
  // std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}