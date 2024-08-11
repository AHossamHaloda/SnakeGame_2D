#ifndef GAME_DATA_BASE_H
#define GAME_DATA_BASE_H

#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <mutex>
#include "gameDataBaseCfg.h"

class GameDataBase {
public:
    // GameData Base Constructor
    GameDataBase();

    // GameData Base Destructor
    ~GameDataBase(){}

    // Update Data Base
    void vidUpdateDataBase();

    // Set Player Info
    void vidSetPlayerInfo(std::string name, unsigned int score);

    // Load scores from the file
    void vidDisplayTopPlayers() const;

    // A struct represent the Player info
    struct Player{
        std::string strName;
        unsigned int u64Score;
        bool IsUpdated; 
    };


private:    // private methodes
    // Add a new score
    void vidSavePlayer();
    
    // Sort the map and limit it to max. number of players to be stored
    void SortAndTrimScores();

    // Save scores to the file
    void SaveScores() const;

private:    // private members
    // Member variable holds the path of the external file
    const std::string m_strFilename{FILE_TOP_SCORES};

    // Map to hold the players and their scores
    std::map<std::string, int> m_mapScore;

    // Player Struct to handle new players data
    Player m_player; 

    // Mutex variable used to protect Player Struct
    mutable std::mutex m_playerMutex;
    
    // Mutex variable used to protect Player Struct
    mutable std::mutex m_fileMutex;
    

};


#endif