#include <iostream>
#include "SDL.h"
#include "game.h"
#include "gameState.hpp"

// Game Constructor
/*************************************************************************************/
Game::Game(std::shared_ptr<Snake> snake, std::size_t grid_width, std::size_t grid_height)
    : m_snakeObj(snake),
      engine(dev()),
      m_grid_width(grid_width),
      m_grid_height(grid_height),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

// Update Food Location in the Grid
/*************************************************************************************/
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

// Update Game (Snake Location, Snake Speed, Snake Size, Food)
/*************************************************************************************/
void Game::Update(GameState &gameState) {
  if (!m_snakeObj->alive)
  {
    gameState = GameState::End;
  } 
  else
  { 
    m_snakeObj->Update();

    int new_x = static_cast<int>(m_snakeObj->head_x);
    int new_y = static_cast<int>(m_snakeObj->head_y);

    // Check if there's food over here
    if (m_foodObj.x == new_x && m_foodObj.y == new_y) 
    {
      score++;
      PlaceFood();
      // Grow snake and increase speed.
      m_snakeObj->GrowBody();
      m_snakeObj->speed += 0.02;
    }
  }
}

// Return Player Score
/*************************************************************************************/
int Game::GetScore() const { return score; }

// Return Snake Size
/*************************************************************************************/
int Game::GetSize() const { return m_snakeObj->size; }

// Return Food Obj
/*************************************************************************************/
SDL_Point Game::GetFood() const { return m_foodObj; }

// Reset Game Parameters
/*************************************************************************************/
void Game::Reset()
{
  score = 0;
  random_w = std::uniform_int_distribution<int>(0, static_cast<int>(m_grid_width - 1));
  random_h = std::uniform_int_distribution<int>(0, static_cast<int>(m_grid_height - 1));
}


