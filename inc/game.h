#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::shared_ptr<Snake> snake, std::size_t grid_width, std::size_t grid_height);

  void Update();
  int GetScore() const;
  int GetSize() const;
  SDL_Point GetFood() const;

 private:
  std::shared_ptr<Snake> m_snakeObj;
  
  SDL_Point m_foodObj;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();

};

#endif