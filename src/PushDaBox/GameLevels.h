#ifndef PUSHDABOX_GAMELEVELS_H
#define PUSHDABOX_GAMELEVELS_H

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <streambuf>

#include "../JsonLib/JsonLib.h"

namespace PushDaBox {

struct Level {
    std::string map;
    size_t width;
    size_t height;

    Level(size_t w, size_t h, std::string m)
    : width(w), height(h), map(m) {}
};

class GameLevels {
public:
    GameLevels(const std::string filename) {
        std::string str;
        {
            std::ifstream f(filename);
            std::stringstream ss;
            ss << f.rdbuf();
            str = ss.str();
        }
        str.erase(remove_if(std::begin(str), std::end(str), isspace), std::end(str));

        size_t pos = 0;
        json.deserialise(str, pos);

        size_t levelIndex = 1;
        std::string levelIndexStr;
        while (true) {
            try {
                size_t width,height;
                std::string map;
                std::stringstream ss;

                ss << levelIndex++;
                ss >> levelIndexStr;
                ss.clear();

                ss << json[levelIndexStr]["width"].getValue() << " ";
                ss << json[levelIndexStr]["height"].getValue() << " ";
                ss << json[levelIndexStr]["map"].getValue();

                ss >> width;
                ss >> height;
                ss >> map;

                levels.push_back({width, height, map});
                std::cout << "Level: " << levelIndexStr << std::endl;
                std::cout << "Width: " << levels.back().width << std::endl;
                std::cout << "Height: " << levels.back().height << std::endl;
                std::cout << "Map: " << levels.back().map << std::endl << std::endl;
            } catch (const std::exception& e) {
                break;
            }
        }
    }
private:
    JsonLib::JsonObject json;
    std::vector<Level> levels;
};

} // namespace PushDaBox

#endif