#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <memory>
#include "gameState.hpp"
#include "snake.h"

class Controller {
 public:
 // Controller Constructor 
 Controller(std::shared_ptr<Snake> snake)
 : m_snakeObj(snake){

 }
 // Controller Destructor
 ~Controller()
 {
   //  std::cout<<"Controller Destructor\n";
 }

  void HandleInput(GameState& gameState) const;

 private:
 std::shared_ptr<Snake> m_snakeObj;    

  void ChangeDirection(Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif