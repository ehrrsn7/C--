//
//  ship.hpp
//  Galaga
//
//  Created by Elijah Harrison on 12/20/21.
//

#ifndef ship_hpp
#define ship_hpp

#include <iostream>

#include "uiDraw.hpp"

#include "gameobject.hpp"
#include "laser.hpp"

class Ship : public Gameobject {

private:
public:
    Ship() {
        name = "Ship";
        std::cout << name << " constructor called\n";
        angle = 50;
    }
    
    void update() {
        Gameobject::update();
    }
    
    void handleInput(const Interface & ui) {
        v.set(400 /*px/s*/ / 60 /*FPS*/ * (ui.getHeldKey(RIGHT) - ui.getHeldKey(LEFT)), 0);
    }
    
    void display(const Interface & ui) {
        drawShip(p, 0, 1, true);
    }
    
    void resetPosition(Vec2 br) {
        p.set(0 /*center x*/, br.getY() + 20);
    }
    
    void resetPosition() { resetPosition(Gameobject::screenBR); }
    
    Laser fireLaser() {
        return Laser(p, v);
    }
    
};

#endif /* ship_hpp */
