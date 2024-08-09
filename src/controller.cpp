#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

// Change Snake Direction
/*************************************************************************************/
void Controller::ChangeDirection(Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (m_snakeObj->direction != opposite || m_snakeObj->size == 1) m_snakeObj->direction = input;
  return;
}

// Handle Player Input
/*************************************************************************************/
void Controller::HandleInput(GameState& gameState) const 
{
  SDL_Event e;
  static bool bMenuToggle = true;
  while (SDL_PollEvent(&e)) 
  {
    if (e.type == SDL_QUIT) 
    {
      gameState = GameState::Quit;
    } 
    else
    {
      if (e.type == SDL_KEYDOWN)
      {
        switch (e.key.keysym.sym) 
        {
          case SDLK_UP:
            ChangeDirection(Snake::Direction::kUp,
                            Snake::Direction::kDown);
            break;

          case SDLK_DOWN:
            ChangeDirection(Snake::Direction::kDown,
                            Snake::Direction::kUp);
            break;

          case SDLK_LEFT:
            ChangeDirection(Snake::Direction::kLeft,
                            Snake::Direction::kRight);
            break;

          case SDLK_RIGHT:
            ChangeDirection(Snake::Direction::kRight,
                            Snake::Direction::kLeft);
            break;

          case SDLK_ESCAPE:
            if (bMenuToggle == true)
            {
              gameState = GameState::Pause;
              bMenuToggle = false;
            }
            else        
            {
              gameState = GameState::Run;
              bMenuToggle = true;
            }
            break;
        }
      }
      else
      {
        /*
        * No Action is required
        */
      }
    }
  }
}