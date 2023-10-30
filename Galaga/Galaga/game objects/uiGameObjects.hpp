//
//  uiGameObjects.hpp
//  Galaga
//
//  Created by Elijah Harrison on 12/20/21.
//

#ifndef uiGameObjects_hpp
#define uiGameObjects_hpp

#include <iostream>

#include "uiDraw.hpp"
#include "vector.hpp"

class Level {

private:
    int level;
    Vec2 position;
    
public:
    Level() {
        std::cout << "Level constructor called." << std::endl;
        level = 1;
    }
    
    void setPosition(Vec2 & tl, Vec2 & br) {
        position.set(tl);
        position.add(15, -15);
    }
    
    void display() {
        std::string levelText = "Level: ";
        levelText += std::to_string(level);
        drawText(position, levelText.c_str());
    }
    
    void next() { level++; }
    void reset() { level = 1; }
};

class Score {

private:
    int score;
    Vec2 position;
    
public:
    Score() {
        std::cout << "Score constructor called." << std::endl;
        score = 1;
    }
    
    void setPosition(Vec2 & tl, Vec2 & br) {
        position.setX(br.getX());
        position.setY(tl.getY());
        position.add(-65, -15);
    }
    
    void display() {
        std::string levelText = "Score: ";
        levelText += std::to_string(score);
        drawText(position, levelText.c_str());
    }
};

#endif /* uiGameObjects_hpp */
