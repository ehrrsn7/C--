//
//  enemy.hpp
//  Galaga
//
//  Created by Elijah Harrison on 3/21/22.
//

#ifndef enemy_hpp
#define enemy_hpp

#include "gameobject.hpp"

class Enemy : public Gameobject {
    
private:
public:
    Enemy() {
        name = "Enemy";
        radius = 10; // pixels
        angle = 0.0; // radians (0 is up)
        da = 0.0; // radians/second
        deathTimer = 0.0; // seconds
        scoreAmount = 0.0; // pts
        alive = true; // if false, Game() instance will clear it
    }
    
    // Enemy(Vec2 pInit) : p(pInit) { } // idk why this doesn't work (TODO)
    Enemy(Vec2 pInit) { setPosition(pInit); }
    
    // override update
    void update() {
        
    }
    
    // override display
    void display(const Interface & ui) {
        drawCircle(p, radius);
    }
    
    // override display
    void handleInput(const Interface & ui) {
        
    }
    
};

#endif /* enemy_hpp */
