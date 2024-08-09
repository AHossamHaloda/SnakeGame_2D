#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include <memory>
#include "gameState.hpp"

class Controller {
 public:
 // Controller Constructor 
 Controller(std::shared_ptr<Snake> snake)
 : m_snakeObj(snake){

 }

  void HandleInput(GameState& gameState) const;

 private:
 std::shared_ptr<Snake> m_snakeObj;    

  void ChangeDirection(Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif