/**
 * Galaga Clone
 */

//
//  main.cpp
//  Galaga
//
//  Created by Elijah Harrison on 12/20/21.
//

#include "game.hpp"
#include "uiInteract.hpp"

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 400
#define FPS 60

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void update(const Interface *pUI, void *p) {
    Game *pGame = (Game*) p;

    pGame->update();
    pGame->handleInput(*pUI);
    pGame->display(*pUI);
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * the game and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv) {
    Vec2 topLeft(-SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    Vec2 bottomRight(SCREEN_WIDTH/2, -SCREEN_HEIGHT/2);

    Interface ui(argc, argv, "Asteroids", topLeft, bottomRight);
    Game game(topLeft, bottomRight, FPS);
    ui.run(update, &game);

    return 0;
}
