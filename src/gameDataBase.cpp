#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include "gameDataBase.hpp"

// Add a new score to the Map and save it to the file
/*************************************************************************************/
void GameDataBase::vidSavePlayer() {
    if (m_player.IsUpdated == true)
    {
        m_mapScore[m_player.strName] = m_player.u64Score; // Add or update the score
        SortAndTrimScores(); // Sort and keep only the top 10 scores
        SaveScores(); // Save updated scores to the file
        m_player.IsUpdated = false;
    }
    else
    {
        /*
        * Player is already saved
        * No Action is required
        */
    }
}

// Load scores from the file
/*************************************************************************************/
void GameDataBase::vidDisplayTopPlayers() const {
    // Open the file to read the scores
    std::ifstream infile(m_strFilename);
    if (!infile.is_open()) {
        std::cout << "Unable to open file: " << m_strFilename << "\n";
        return;
    }

    // Read the scores into a vector of pairs
    std::vector<std::pair<std::string, int>> scores;
    std::string name;
    int score;
    while (infile >> name >> score) {
        scores.emplace_back(name, score);
    }
    infile.close();

    // Sort the scores in descending order (just in case the file wasn't sorted)
    std::sort(scores.begin(), scores.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Display the top players
    std::cout << "------ Top Players ------\n";
    std::cout << std::left << std::setw(20) << "Player" << std::setw(10) << "Score" << "\n";
    std::cout << "-------------------------\n";

    for (const auto& entry : scores) {
        std::cout << std::left << std::setw(20) << entry.first << std::setw(10) << entry.second << "\n";
    }

    std::cout << "-------------------------\n";
}

// Save scores to the file
/*************************************************************************************/
void GameDataBase::SaveScores() const {
    // Open the existing file and read its contents into a map
    std::map<std::string, int> file_scores;
    std::ifstream infile(m_strFilename);
    if (infile.is_open()) {
        std::string name;
        int score;
        while (infile >> name >> score) {
            file_scores[name] = score;
        }
        infile.close();
    }

    // Merge current map scores with file scores
    for (const auto& entry : m_mapScore) {
        if (file_scores.find(entry.first) != file_scores.end()) {
            // If player is already in file, update only if the new score is higher
            if (entry.second > file_scores[entry.first]) {
                file_scores[entry.first] = entry.second;
            }
        } else {
            // If player is not in file, add them
            file_scores[entry.first] = entry.second;
        }
    }

    // Convert merged map to vector of pairs for sorting
    std::vector<std::pair<std::string, int>> all_scores(file_scores.begin(), file_scores.end());

    // Sort by score in descending order
    std::sort(all_scores.begin(), all_scores.end(),
              [](const auto& a, const auto& b) {
                  return a.second > b.second;
              });

    // Write only the top 10 scores back to the file
    std::ofstream outfile(m_strFilename);
    if (outfile.is_open()) {
        size_t count = 0;
        for (const auto& entry : all_scores) {
            if (count++ >= 10) break;
            outfile << entry.first << ' ' << entry.second << '\n';
        }
        outfile.close();
    } else {
        std::cout << "Can't open file to store player score: " << m_strFilename << "\n";
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
void GameDataBase::vidSetPlayerName(std::string name)
{ 
    m_player.strName = name; 
    m_player.IsUpdated = true; 
}

// Set Player Score
/*************************************************************************************/
void GameDataBase::vidSetPlayerScore(int score)
{ 
    m_player.u64Score = score; 
    m_player.IsUpdated = true; 
}

// Get player Name
/*************************************************************************************/
std::string GameDataBase::strGetPlayerName(){ return m_player.strName; }

// Get player Score
/*************************************************************************************/
unsigned int GameDataBase::u64GetPlayerScore(){ return m_player.u64Score; }