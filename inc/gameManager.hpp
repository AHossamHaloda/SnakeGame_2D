
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <iostream>
#include <string>
#include <vector>

#include "gameManagerCfg.h"
#include "snake.h"
#include "controller.h"
#include "game.h"
#include "renderer.h"

class GameManager {

public:

// GameManager Constructor
GameManager();

// GameManager Destructor
~GameManager(){
    std::cout<<"GameManager Destructor\n";
}

// Enum Class Represent Game Menu Options 
enum class GameMenuOption
{
    NotSelected = 0,  // Default state when no option is selected
    StartNewGame,
    CheckTopScores,
    QuitGame,
    MenuOptionCount
};

// Game Init
void gameInit();

// Game Main 
void gameMainFunction();


private:

void startGameMenu();

void startNewGame();

void displayTopScore();

void quitGame();


private:
std::shared_ptr<Snake> m_snakeObj;
Controller m_controllerObj;
Game m_gameObj;
Renderer m_renderObj;

GameMenuOption m_enuGameMenuOption; // Represent Game Menu Options


/* Game Settings Parameters */
static constexpr uint16_t m_u16FramesPerSecond{GAME_FPS};
static constexpr uint16_t m_u16MsPerFrame{GAME_MS_PER_FRAME};
static constexpr uint16_t m_u16ScreenWidth{GAME_SCREEN_WIDTH};
static constexpr uint16_t m_u16ScreenHeight{GAME_SCREEN_HEIGHT};
static constexpr uint16_t m_u16GridWidth{GAME_GRID_WIDTH};
static constexpr uint16_t m_u16GridHeight{GAME_GRID_HEIGHT};

};

#endif