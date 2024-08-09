#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include "gameDataBase.hpp"

// Add a new score
/*************************************************************************************/
void GameDataBase::AddScore(const std::string& name, int score) {
    m_mapScore[name] = score; // Add or update the score
    SortAndTrimScores(); // Sort and keep only the top 10 scores
    SaveScores(); // Save updated scores to the file
}

// Load scores from the file
/*************************************************************************************/
void GameDataBase::LoadScores() {
    std::ifstream file(m_strFilename);
    if (file.is_open()) {
        std::string name;
        int score;
        while (file >> name >> score) {
            m_mapScore[name] = score;
        }
        file.close();
        SortAndTrimScores(); // Ensure scores are sorted and trimmed after loading
    }
}

// Save scores to the file
/*************************************************************************************/
void GameDataBase::SaveScores() const {
    std::ofstream file(m_strFilename);
    if (file.is_open()) {
        size_t count = 0;
        for (const auto& entry : m_mapScore) {
            if (count++ >= 10) break;  // Only write top 10 scores
            file << entry.first << ' ' << entry.second << '\n';
        }
        file.close();
    }
}

// Display top scores
/*************************************************************************************/
void GameDataBase::DisplayScores() const {
    std::cout << "Top Scores:\n";
    for (const auto& entry : m_mapScore) {
        std::cout << entry.first << ": " << entry.second << '\n';
    }
}

// Sort scores and keep only the top 10
/*************************************************************************************/
void GameDataBase::SortAndTrimScores() {
    // Convert map to vector of pairs for sorting
    std::vector<std::pair<std::string, int>> sorted_scores(m_mapScore.begin(), m_mapScore.end());

    // Sort by score in descending order
    std::sort(sorted_scores.begin(), sorted_scores.end(),
              [](const auto& a, const auto& b) {
                  return a.second > b.second;
              });

    // Keep only the top 10 scores
    m_mapScore.clear();
    size_t count = 0;
    for (const auto& entry : sorted_scores) {
        if (count++ >= Max_NUMBER_PLAYERS) break;
        m_mapScore[entry.first] = entry.second;
    }
}

// Set Player Name
/*************************************************************************************/
void GameDataBase::vidSetPlayerName(std::string name){ m_player.name = name; }

// Set Player Score
/*************************************************************************************/
void GameDataBase::vidSetPlayerScore(int score){ m_player.score = score; }

// Get player Name
/*************************************************************************************/
std::string GameDataBase::strGetPlayerName(){ return m_player.name; }

// Get player Score
/*************************************************************************************/
unsigned int GameDataBase::u64GetPlayerScore(){ return m_player.score; }