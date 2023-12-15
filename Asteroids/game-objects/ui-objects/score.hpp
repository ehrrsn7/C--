//
//  score.hpp
//  Asteroids
//
//  Created by Elijah Harrison on 11/7/20.
//

#pragma once

#include <iostream>
#include <string>

#ifdef __APPLE__
#include "uiDraw.hpp"
#endif
#ifdef _WIN32
#include "ui/uiDraw.hpp"
#endif

#ifdef __APPLE__
#include "vector.hpp"
#endif
#ifdef _WIN32
#include "physics-components/vector.hpp"
#endif

class Score {

private:
    int score;
    Position position;

public:
    Score() {
        std::cout << "Score constructor called." << std::endl;
        score = 0;
    }
    
    void set(Position p) { position.set(p); }
    
    void display() {
        std::string scoreText = "Score: ";
        scoreText += std::to_string(score);
        drawText(position, scoreText.c_str());
    }
    
    void add(int dPoints) { score += dPoints; }    
    void reset() { score = 0; }
};
