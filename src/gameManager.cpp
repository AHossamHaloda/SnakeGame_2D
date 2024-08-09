
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "gameManager.hpp"



// GameManager Constructor
/*************************************************************************************/
GameManager::GameManager() 
: m_enuGameState(GameState::Undefined),
  m_gameDataBaseObj(),
  m_snakeObj(std::make_shared<Snake>(m_u16GridWidth, m_u16GridHeight)),
  m_controllerObj (Controller(m_snakeObj)),
  m_gameObj(Game(m_snakeObj, m_u16GridWidth, m_u16GridHeight)),
  m_renderObj(Renderer(m_snakeObj, m_u16ScreenWidth, m_u16ScreenHeight, m_u16GridWidth, m_u16GridHeight))
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


  while (m_enuGameState != GameState::Quit) 
  {

    if (m_enuGameState == GameState::Run)
    {
      // Capture Current time - Start of Frame/Loop 
      frame_start = SDL_GetTicks();

      /* Lunch Threads: Input, Update, Render - the main game loop. */
      // std::thread inputThread([this]() { gameHandleInput(); });
      // Join threads to wait for their completion
      // inputThread.join();

      // Handle Input 
      m_controllerObj.HandleInput(m_enuGameState);

      // Update Game 
      m_gameObj.Update();
      
      // Render Game 
      m_renderObj.Render(m_gameObj.GetFood(), m_enuGameState);

      // Capture Current time - End of Frame/Loop 
      frame_end = SDL_GetTicks();
      frame_duration = frame_end - frame_start;
      // Keep track of how long each loop through the input/update/render cycle
      frame_count++;

      //TESTING
      // std::this_thread::sleep_for(std::chrono::milliseconds(1));
      // std::cout<<"title_timestamp = "<<title_timestamp<<"   FStart = "<<frame_start<<"   FEnd = "<<frame_end<<"\n\n";
      // if (frame_end <= frame_start)
      // {
      //   std::cout<<"title_timestamp = "<<title_timestamp<<"   FStart = "<<frame_start<<"   FEnd = "<<frame_end<<"\n\n";
      // }

      // After every second, update the window title.
      if (frame_end - title_timestamp >= 1000) 
      {
        // m_ptrRender->UpdateWindowTitle(m_ptrGame->GetScore(), frame_count);
        m_renderObj.UpdateWindowTitle(m_gameObj.GetScore(), frame_count);
        
        frame_count = 0;
        title_timestamp = frame_end;
      }

      // If the time for this frame is too small (i.e. frame_duration is
      // smaller than the target ms_per_frame), delay the loop to
      // achieve the correct frame rate.
      if (frame_duration < m_u16MsPerFrame) 
      {
        SDL_Delay(m_u16MsPerFrame - frame_duration);
      }
      else
      {
        // return;
      }
    }
    else if(m_enuGameState == GameState::Pause)
    {

      m_controllerObj.HandleInput(m_enuGameState);
    }
  }
  
  /* Input, Update, Render - the main game loop. */
}


/*************************************************************************************/
void GameManager::startNewGame()
{ 
  std::string playerName;
  std::cout<<"Please Eneter Your Name\n\n";
  std::cin>>playerName;
  m_gameDataBaseObj.vidSetPlayerName(playerName);
  m_enuGameState = GameState::Run;
}

/*************************************************************************************/
void GameManager::displayTopScore()
{
}

/*************************************************************************************/
void GameManager::quitGame()
{
  m_enuGameState = GameState::Quit;
}

    
/*************************************************************************************/
// void GameManager::gameHandleInput()
// {
//   m_controllerObj.HandleInput(m_bRunning);
// }