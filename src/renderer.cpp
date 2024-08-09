#include <iostream>
#include <string>
#include "renderer.h"


// Renderer Constructor
/*************************************************************************************/
Renderer::Renderer(std::shared_ptr<Snake> snake, const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : m_snakeObj(snake),
      screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height)
 {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) 
  {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create game window
  sdlGameWindow = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED, screen_width,
                                   screen_height, SDL_WINDOW_SHOWN);  
  if (nullptr == sdlGameWindow) {
    std::cerr << "Game Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create game renderer
  sdlGameRenderer = SDL_CreateRenderer(sdlGameWindow, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdlGameRenderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

// Renderer Destructor
/*************************************************************************************/
Renderer::~Renderer() {
  SDL_DestroyRenderer(sdlGameRenderer);
  SDL_DestroyWindow(sdlGameWindow);
  SDL_Quit();
}

// Render Window
/*************************************************************************************/
void Renderer::Render(SDL_Point const &food, GameState const &gameState) {
  SDL_Rect block;

  if (gameState == GameState::Run)
  {
    block.w = screen_width / grid_width;
    block.h = screen_height / grid_height;
  
    // Clear game screen
    SDL_SetRenderDrawColor(sdlGameRenderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(sdlGameRenderer);

    // Render food
    SDL_SetRenderDrawColor(sdlGameRenderer, 0xFF, 0xCC, 0x00, 0xFF);
    block.x = food.x * block.w;
    block.y = food.y * block.h;
    SDL_RenderFillRect(sdlGameRenderer, &block);

    // Render snake's body
    SDL_SetRenderDrawColor(sdlGameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (SDL_Point const &point : m_snakeObj->body) {
      block.x = point.x * block.w;
      block.y = point.y * block.h;
      SDL_RenderFillRect(sdlGameRenderer, &block);
    }

    // Render snake's head
    block.x = static_cast<int>(m_snakeObj->head_x) * block.w;
    block.y = static_cast<int>(m_snakeObj->head_y) * block.h;
    if (m_snakeObj->alive) {
      SDL_SetRenderDrawColor(sdlGameRenderer, 0x00, 0x7A, 0xCC, 0xFF);
    } else {
      SDL_SetRenderDrawColor(sdlGameRenderer, 0xFF, 0x00, 0x00, 0xFF);
    }
    SDL_RenderFillRect(sdlGameRenderer, &block);

    // Update the game screen to reflect the new rendering
    SDL_RenderPresent(sdlGameRenderer);  
  }
  else if (gameState == GameState::Pause) 
  {

  }
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdlGameWindow, title.c_str());
}
