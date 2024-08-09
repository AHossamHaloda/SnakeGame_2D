#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::shared_ptr<Snake> snake, std::size_t grid_width, std::size_t grid_height)
    : m_snakeObj(snake),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!m_snakeObj->SnakeCell(x, y)) {
      m_foodObj.x = x;
      m_foodObj.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!m_snakeObj->alive) return;

  m_snakeObj->Update();

  int new_x = static_cast<int>(m_snakeObj->head_x);
  int new_y = static_cast<int>(m_snakeObj->head_y);

  // Check if there's food over here
  if (m_foodObj.x == new_x && m_foodObj.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    m_snakeObj->GrowBody();
    m_snakeObj->speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return m_snakeObj->size; }
SDL_Point Game::GetFood() const { return m_foodObj; }

