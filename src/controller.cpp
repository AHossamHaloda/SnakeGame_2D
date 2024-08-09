#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (m_snakeObj->direction != opposite || m_snakeObj->size == 1) m_snakeObj->direction = input;
  return;
}

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
      if ((gameState == GameState::Run) && (e.type == SDL_KEYDOWN))
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
      else if ((gameState == GameState::Pause) && (e.type == SDL_KEYDOWN))
      {
        // at this point the hidden menu option should appear with an identifer(cursuer for example on the current option Resume, TopScores, Quit)
        switch (e.key.keysym.sym) 
        {
          case SDLK_UP:
          // should move the identifer up(if the identifer on the first option then it should point to the last)
            break;

          case SDLK_DOWN:
          // should move the identifer down(if the identifer on the last option then it should point to the first)
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
    }
  }
}