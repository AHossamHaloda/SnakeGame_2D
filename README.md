# Snake Game Project

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="../images/snake_game.gif"/>

--- 

## Game Overview
In this game, you control a snake navigating through a 2D grid by moving it up, down, left, and right using the arrow keys.

**<u>Starting the Game</u>**
AT the Beginning the game asks u to select the mode
- **Start a new Game**
- **Check Top Scores**
- **QUIT**

By choosing **Start a new Game**
Enter your name to begin playing.
Your score will be recorded and stored if it surpasses the previous highest scores.

**<u>Controls</u>**
**Arrow Up Key:** Move the snake upwards.
**Arrow Down Key:** Move the snake downwards.
**Arrow Left Key:** Move the snake to the left.
**Arrow Right Key:** Move the snake to the right.
**Esc Key:** Pause or resume the game.

**<u>Scoring</u>**
The game keeps track of scores, and only scores higher than existing top scores will be saved.

Max number of top scores is configurable through **Max_NUMBER_PLAYERS** in `gameDataBaseCfg.h`

---

## Project Dependencies
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

---

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

---

## Project New Features

**New Design:**

- **Code Restructure**: The code has been restructured for better organization by separating source files from header files and moving `main.cpp` to the parent directory for improved project organization.
  
- **GameManager Class**: Introduced a new class, `GameManager`, which centralizes all project control. The Game Super Loop now runs in the `GameManager`, which interacts with all game objects. This design allows each object to focus on a single task, minimizing dependencies between objects. The `Snake` object is shared among all game objects using a `std::shared_ptr`, achieving dependency injection to reduce coupling, enhance design flexibility, and improve memory management.

- **Dependency Injection**: Utilized the `Snake` object via a shared pointer in the `GameManager` class, passing it to other game objects. This approach reduces coupling and enhances flexibility in design changes.

- **State Machine Integration**: Integrated a state machine in the Game Super Loop using two enums to represent the game menu options and the current game state.

- **Configurable Game Settings**: All game settings are configured through preprocessor macros in configurable files `gameManagerCfg.h` and `gameDataBaseCfg.h` and assigned to `const` variables at compile/run time.

**New Features**

- **Menu Options**: Added a menu that allows players to start a new game, view top players, or quit the game.

- **GameDataBase Class**: Introduced a new class, `GameDataBase`, to manage storing player scores and names in an external file `GameTopscore.txt`.

- **Pause/Resume Functionality**: Implemented a new feature using the `Esc` key to allow players to pause and resume the game.

- **Reset Game Mechanism**: Integrated a reset game mechanism within the state machine, enabling players to start a new game without restarting the program from scratch.


---


## CC Attribution-ShareAlike 4.0 International

Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

---