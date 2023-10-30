//
//  laser.hpp
//  Galaga
//
//  Created by Elijah Harrison on 12/20/21.
//

#ifndef laser_hpp
#define laser_hpp

#define LASER_SPEED 1000 // px/s

#include "uiDraw.hpp"
#include "uiInteract.hpp"

#include "gameobject.hpp"
#include "vector.hpp"

class Laser : public Gameobject {

private:
    
public:
    
    Laser(Vec2 shipP, Vec2 shipV) {
        name = "laser";
        std::cout << name << " constructor called\n";
        radius = 2;
        p.set(shipP);
        v.set(0, shipV.getY());
        v.add(0, LASER_SPEED/(float)Gameobject::FPS);
        // deathTimer = .2; // s // set death timer to enable it (pt. 1)
    }
    
    void update() {
        Gameobject::update();
        
        if (p.getY() > Gameobject::screenTL.getY()) {
            std::cout << "laser has left the screen\n";
            alive = false;
        }
        // if (deathTimer <= 0) alive = false; // enable death timer
    }
    
    void handleInput(const Interface & ui) { }
    
    void display(const Interface & ui) { drawDot(p); }

};

#endif /* laser_hpp */
