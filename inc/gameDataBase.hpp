#ifndef GAME_DATA_BASE_H
#define GAME_DATA_BASE_H

#include <map>
#include <string>
#include <fstream>
#include <vector>
#include "gameDataBaseCfg.h"

class GameDataBase {
public:
    GameDataBase(){}
    
    // Set Player Name
    void vidSetPlayerName(std::string name);

    // Set Player Score
    void vidSetPlayerScore(int score);

    // Get player Name
    std::string strGetPlayerName();

    // Get player Score
    unsigned int u64GetPlayerScore();

    // Add a new score
    void AddScore(const std::string& name, int score);

    // Load scores from the file
    void LoadScores();

    // Save scores to the file
    void SaveScores() const;

    // Display top scores
    void DisplayScores() const;

    struct Player{
        std::string name;
        unsigned int score;
    };

private:
    const std::string m_strFilename{FILE_TOP_SCORES};
    
    std::map<std::string, int> m_mapScore;

    Player m_player; 
    
    void SortAndTrimScores();

};


#endif