//
//  level.hpp
//  Asteroids
//
//  Created by Elijah Harrison on 11/7/20.
//

#pragma once

#include <iostream>

#ifdef __APPLE__
#include "physicsFormulas.hpp"
#endif
#ifdef _WIN32
#include "physics-components/physicsFormulas.hpp"
#endif

#ifdef __APPLE__
#include "vector.hpp"
#endif
#ifdef _WIN32
#include "physics-components/vector.hpp"
#endif

class Level {

private:
    int level;
    Position position;

public:
    Level() {
        std::cout << "Level constructor called." << std::endl;
        level = 1;
    }
    
    void set(Position p) { position.set(p); }
    
    void display() {
        // TODO: not displaying properly.
        std::string levelText = "Level: ";
        levelText += std::to_string(level);
        drawText(position, levelText.c_str());
    }
    
    void next() { level += 1; }
    void reset() { level = 1; }
};
