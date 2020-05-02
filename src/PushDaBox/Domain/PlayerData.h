#ifndef PUSHDABOX_DOMAIN_PLAYERDATA_H
#define PUSHDABOX_DOMAIN_PLAYERDATA_H

#include <string>
#include <fstream>
#include <sstream>

#include "../../JsonLib/JsonLib.h"

namespace PushDaBox {

class PlayerData {
public:
    PlayerData(std::string playerDataFileLocation)
    : playerDataFile(playerDataFileLocation) {
        this->readPlayerData();
    }

    std::string getPlayerName() { this->readPlayerData(); return this->playerName; }

    int getPlayerScore() { this->readPlayerData(); return this->playerScore; }

    int getPlayerLevel() { this->readPlayerData(); return this->playerLevel; }

    int getPlayerLives() { this->readPlayerData(); return this->playerLives; }

    void setPlayerName(std::string newName) {
        this->playerName = newName;
        this->savePlayerData();
    }

    void setPlayerScore(int newScore) {
        this->playerScore = newScore;
        this->savePlayerData();
    }

    void setPlayerLevel(int newLevel) {
        this->playerLevel = newLevel;
        this->savePlayerData();
    }

    void setPlayerLives(int newLives) {
        this->playerLives = newLives;
        this->savePlayerData();
    }

private:
    std::string playerDataFile;
    std::string playerName;
    int playerScore;
    int playerLevel;
    int playerLives;

    void readPlayerData() {
        JsonLib::JsonObject playerData;
        std::string str;
        {
            std::ifstream f(this->playerDataFile);
            std::stringstream ss;
            ss << f.rdbuf();
            str = ss.str();
            f.close();
        }
        str.erase(remove_if(std::begin(str), std::end(str), isspace), std::end(str));

        size_t pos = 0;
        playerData.deserialise(str, pos);

        this->playerName = playerData["player"]["name"].getValue();
        this->playerScore = std::stoi(playerData["progress"]["score"].getValue());
        this->playerLevel = std::stoi(playerData["progress"]["level"].getValue());
        this->playerLives = std::stoi(playerData["progress"]["lives"].getValue());
    }

    void savePlayerData() {
        JsonLib::JsonObject playerData;
        JsonLib::JsonObject progress;
        JsonLib::JsonObject player;

        player.addValue("name", this->playerName);
        progress.addValue("level", this->playerLevel);
        progress.addValue("score", this->playerScore);
        progress.addValue("lives", this->playerLives);
        playerData.addValue("player", player);
        playerData.addValue("progress", progress);

        std::ofstream f;
        f.open(this->playerDataFile, std::ofstream::out | std::ofstream::trunc);
        f << playerData.serialise();
        f.close();
    }
};

} // namespace PushDaBox

#endif