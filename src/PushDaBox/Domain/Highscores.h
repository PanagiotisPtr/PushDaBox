#ifndef PUSHDABOX_DOMAIN_HIGHSCORES_H
#define PUSHDABOX_DOMAIN_HIGHSCORES_H

#include <string>
#include <fstream>
#include <sstream>
#include <map>

#include "../../JsonLib/JsonLib.h"

namespace PushDaBox {

class Highscores {
public:
    Highscores(std::string highscoreFileLocation)
    : highscoreFile(highscoreFileLocation) {
        this->readHighscores();
    }

    std::multimap<int, std::string> getHighscores() {
        this->readHighscores();
        return highscores;
    }

    void addHighscore(std::string name, int score) {
        this->readHighscores();
        this->highscores.insert({score, name});
        this->saveHighscores();
    }
private:
    std::string highscoreFile;
    std::multimap<int, std::string> highscores;

    void readHighscores() {
        JsonLib::JsonObject highscoreData;
        std::string str;
        {
            std::ifstream f(this->highscoreFile);
            std::stringstream ss;
            ss << f.rdbuf();
            str = ss.str();
            f.close();
        }
        str.erase(remove_if(std::begin(str), std::end(str), isspace), std::end(str));

        size_t pos = 0;
        highscoreData.deserialise(str, pos);

        size_t scoreIdx = 1;
        std::string scoreIdxStr;
        this->highscores.clear();
        while (true) {
            try {
                size_t score;
                std::string name;
                std::stringstream ss;

                ss << scoreIdx++;
                ss >> scoreIdxStr;
                ss.clear();

                ss << highscoreData[scoreIdxStr]["name"].getValue() << " ";
                ss << highscoreData[scoreIdxStr]["score"].getValue();

                ss >> name;
                ss >> score;

                this->highscores.insert({score, name});
            } catch (const std::exception& e) {
                break;
            }
        }
    }

    void saveHighscores() {
        JsonLib::JsonObject highscoreData;
        int count = 1;
        for (auto p : this->highscores) {
            std::stringstream pos;
            pos << count;
            JsonLib::JsonObject score;
            score.addValue("name", p.second);
            score.addValue("score", p.first);
            highscoreData.addValue(pos.str(), score);
            count++;
        }
        std::ofstream f;
        f.open(this->highscoreFile, std::ofstream::out | std::ofstream::trunc);
        f << highscoreData.serialise();
        f.close();
    }
};

} // namespace PushDaBox

#endif