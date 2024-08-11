#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

// Encum Class represent the game states
enum class GameState {
    Undefined = 0,  // Init State
    Run,            // Game is Running
    Pause,          // Game is Paused
    End,            // Game is Ended
    Quit,           // Game Exit
    GameStateCount
};

#endif // GAME_STATE_HPP