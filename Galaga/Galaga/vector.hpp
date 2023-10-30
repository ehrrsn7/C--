//
//  vector.hpp
//  Galaga
//
//  Created by Elijah Harrison on 12/20/21.
//

#ifndef vector_hpp
#define vector_hpp

#include <stdio.h>
#include <string>

class Vec2 {
private:
    float x;
    float y;
public:
    Vec2() : x(0.0), y(0.0) { }
    Vec2(float x_init, float y_init) : x(x_init), y(y_init) { }
    Vec2(const Vec2 & rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
    }
    
    // getters
    Vec2 get() const { return Vec2(x,y); }
    
    float getX() const { return x; }
    float getY() const { return y; }
    
    // setters
    void set(Vec2 v) {
        this->x = v.x;
        this->y = v.y;
    }

    void set(float x, float y) { set(Vec2(x,y)); }
    
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }

    // adder
    void add(Vec2 v) {
        this->x += v.x;
        this->y += v.y;
    }
    
    void add(float x, float y) { add(Vec2(x,y)); }
    
    // "check" constructor
    Vec2(bool check) : x(0.0), y(0.0) {}
    
    // debug
    void print() { printf("Vec2(%d, %d) ", (int)x, (int)y); }
    
    void print(std::string optional) { printf("%s ", optional.c_str()); }
    
    void println() { printf("Vec2(%d, %d)\n", (int)x, (int)y); }
    
    void println(std::string optional) {
        printf("%s", optional.c_str());
        print();
    }
    
    // operators
    Vec2 operator * (float rhs) { return Vec2(x * rhs, y * rhs); }
    Vec2 operator * (int rhs)   { return Vec2(x * rhs, y * rhs); }
    
};

#endif /* vector_hpp */
