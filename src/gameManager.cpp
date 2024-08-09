
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "gameManager.hpp"



// GameManager Constructor
/*************************************************************************************/
GameManager::GameManager() 
: m_snakeObj(std::make_shared<Snake>(m_u16GridWidth, m_u16GridHeight)),
  m_controllerObj(),
  m_gameObj(Game(m_u16GridWidth, m_u16GridHeight)),
  m_renderObj(Renderer(m_u16ScreenWidth, m_u16ScreenHeight, m_u16GridWidth, m_u16GridHeight))
{
    std::cout<<"GameManager Constructor\n";
}

/*************************************************************************************/
void GameManager::gameInit()
{
  std::cout<<"~~~~~ Welcome to Snake_2D game ~~~~~\n";
  /* Start Game Menu */
  startGameMenu();
}

/*************************************************************************************/
void GameManager::startGameMenu()
{
    uint16_t key_pressed;

    std::cout << " 1. Start New Game\n";
    std::cout << " 2. Check Top Scores\n";
    std::cout << " 3. QUIT\n";

    while ( (!(std::cin >> key_pressed)) || (key_pressed < 1) || (key_pressed > 3) )
    {
      // clear the error state of std::cin if exist
      std::cin.clear();
      
      // Discard the remaning characters in the input buffer if exist
      std::cin.ignore();

      // Ask user to try again:
      std::cout << "INVALID Choice. Please Try Again !\n\n";
    }

    switch (key_pressed)
    {
    case 1:
        m_enuGameMenuOption = GameMenuOption::StartNewGame;
        break;  

    case 2:
        m_enuGameMenuOption = GameMenuOption::CheckTopScores;
        break;

    case 3:
        m_enuGameMenuOption = GameMenuOption::QuitGame;
        break;

    Default:
        std::cout<<"Unexpected Value in GameMenuOption";
        break;
    }
}

/*************************************************************************************/
void GameManager::gameMainFunction()
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;

  switch (m_enuGameMenuOption)
  {
    case GameMenuOption::StartNewGame:
    startNewGame();
    break;

    case GameMenuOption::CheckTopScores:
    displayTopScore();
    break;

    case GameMenuOption::QuitGame:
    quitGame();
    break;
  }
}


/*************************************************************************************/
void GameManager::startNewGame()
{ 
  m_gameObj.Run(m_controllerObj, m_renderObj, m_u16MsPerFrame);
}

/*************************************************************************************/
void GameManager::displayTopScore()
{
}

/*************************************************************************************/
void GameManager::quitGame()
{
}
