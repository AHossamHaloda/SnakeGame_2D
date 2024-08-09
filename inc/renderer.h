#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "gameState.hpp"

class Renderer {
 public:
  Renderer(std::shared_ptr<Snake> snake, const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(SDL_Point const &food, GameState const &gameState);
  void UpdateWindowTitle(int score, int fps);

 private:
  // shared pointer of Type Snake to hold snake obj
  std::shared_ptr<Snake> m_snakeObj;

  // Game Window
  SDL_Window *sdlGameWindow;
  SDL_Renderer *sdlGameRenderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif