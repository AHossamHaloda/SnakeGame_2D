#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  
  // Game Constructor
  Game(std::shared_ptr<Snake> snake, std::size_t grid_width, std::size_t grid_height);

  // Game Destructor
  ~Game()
  {
    // std::cout<<"Game Destructor\n";
  }

  void Update(GameState &gameState);

  void Reset();

  int GetScore() const;
  
  int GetSize() const;
  
  SDL_Point GetFood() const;

 private:
  std::shared_ptr<Snake> m_snakeObj;
  std::size_t m_grid_width;
  std::size_t m_grid_height;

  
  SDL_Point m_foodObj;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();

};

#endif