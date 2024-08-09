#ifndef GAME_DATA_BASE_H
#define GAME_DATA_BASE_H

#include <map>
#include <string>
#include <fstream>
#include <vector>
#include "gameDataBaseCfg.h"

class GameDataBase {
public:
    GameDataBase()
    :   m_player{"", 0, false} {}
    
    // Set Player Name
    void vidSetPlayerName(std::string name);

    // Set Player Score
    void vidSetPlayerScore(int score);

    // Get player Name
    std::string strGetPlayerName();

    // Get player Score
    unsigned int u64GetPlayerScore();

    // Add a new score
    void vidSavePlayer();

    // Load scores from the file
    void vidDisplayTopPlayers() const;

    // A struct represent the Player info
    struct Player{
        std::string strName;
        unsigned int u64Score;
        bool IsUpdated = true; 
    };

private:
    const std::string m_strFilename{FILE_TOP_SCORES};
    
    std::map<std::string, int> m_mapScore;

    Player m_player; 
    
    // Sort the map and limit it to max. number of players to be stored
    void SortAndTrimScores();

    // Save scores to the file
    void SaveScores() const;

};


#endif