
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <thread>

#include "gameManagerCfg.h"
#include "gameDataBase.hpp"
#include "snake.h"
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "gameState.hpp"

class GameManager {

public:

// GameManager Constructor
GameManager();

// GameManager Destructor
~GameManager();

// Enum Class Represent Game Menu Options 
enum class GameMenuOption
{
    Undefined = 0,  // Default state when no option is selected
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

void quitGame();

void resetGame();

/* Game Data Base Handling */
void threadUpdateDataBase();
void displayEndGameInfo();
void vidDisplayTopScores();
void updateDataBase();


private:

/* Game Objects */
GameDataBase m_gameDataBaseObj;
std::shared_ptr<Snake> m_snakeObj;
Controller m_controllerObj;
Game m_gameObj;
Renderer m_renderObj;

/* Thread for EndGame Handling */
std::thread m_threadDataBase; 

/* Game Status */
GameState m_enuGameState;
GameMenuOption m_enuGameMenuOption; // Represent Game Menu Options

/* Player Info */
std::string m_strPlayerName;
unsigned int m_u64PlayerScore;

/* Game Settings Parameters */
static constexpr uint16_t m_u16FramesPerSecond{GAME_FPS};
static constexpr uint16_t m_u16MsPerFrame{GAME_MS_PER_FRAME};
static constexpr uint16_t m_u16ScreenWidth{GAME_SCREEN_WIDTH};
static constexpr uint16_t m_u16ScreenHeight{GAME_SCREEN_HEIGHT};
static constexpr uint16_t m_u16GridWidth{GAME_GRID_WIDTH};
static constexpr uint16_t m_u16GridHeight{GAME_GRID_HEIGHT};

};

#endif