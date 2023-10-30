//
//  gameobject.hpp
//  Galaga
//
//  Created by Elijah Harrison on 12/20/21.
//

#ifndef gameobject_hpp
#define gameobject_hpp

#include <iostream>
#include <string>
#include <math.h>

#include "uiInteract.hpp"
#include "uiDraw.hpp"
#include "vector.hpp"

class Gameobject {

protected:
    std::string name;
    Vec2 p; // position
    Vec2 v; // velocity
    float radius;
    float angle;
    float da; // change in angle
    float deathTimer;
    int scoreAmount;
    bool alive;
    
    static Vec2 screenBR;
    static Vec2 screenTL;
    static int FPS;
    
    // in .cpp file
    void updateOrientationAngle();
    
public:
    Gameobject() {
        name = "* Game object";
        radius = 10; // pixels
        angle = 0.0; // radians (0 is up)
        da = 0.0; // radians/second
        deathTimer = 0.0; // seconds
        scoreAmount = 0.0; // pts
        alive = true; // if false, Game() instance will clear it
    }
    
    void update() {
        // quick exit
        if (!alive) return;
        
        // debug
        
        // update position
        p.add(v);
        
        // update orientation angle
        updateOrientationAngle();
        
        // death timer
        if (deathTimer > 0) deathTimer -= 1.0/(float)FPS;
        // std::cout << deathTimer << std::endl;
    }
    
    // polymorphism
    virtual void display(const Interface & ui) { }
    virtual void handleInput(const Interface & ui) { }
    
    // getters
    Vec2 getPosition()      const { return p; }
    Vec2 getVelocity()      const { return v; }
    float getRadius()       const { return radius; }
    float getAngleRadians() const { return angle; }
    int getScoreAmount()    const { return scoreAmount; }
    bool isAlive()          const { return alive; }
    string getName()        const { return name; }
    
    Vec2 forward() const {
        return Vec2(cos(angle+(M_PI/2)), sin(angle+(M_PI/2)));
    }
    
    // setters
    void setPosition(Vec2 p)            { this->p = p; }
    void setVelocity(Vec2 v)            { this->v = v; }
    void setRadius(float radius)        { this->radius = radius; }
    void setAngleRadians(float angle)   { this->angle = angle; }
    void setAngularVelocity(float da)   { this->da = da; }
    void setAlive(bool alive)           { this->alive = alive; }
    
    static void setScreenVars(Vec2 tl, Vec2 br);
    static void setFPS(float fps);
    
};

#endif /* gameobject_hpp */
