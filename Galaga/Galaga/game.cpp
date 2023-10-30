//
//  game.cpp
//  Galaga
//
//  Created by Elijah Harrison on 12/20/21.
//

#include "game.hpp"
#include "vector.hpp"

void Game::populateEnemies() {
    int howManyEnemies = 9;
    
    for (int i = -howManyEnemies/2; i <= howManyEnemies/2; i++) {
        Enemy newEnemy(Vec2(i * 40, topLeft.getY() - 50));
        enemies.push_back(newEnemy);
    }
    
    for (int i = -howManyEnemies/2; i <= howManyEnemies/2; i++) {
        Enemy newEnemy(Vec2(i * 40, topLeft.getY() - 90));
        enemies.push_back(newEnemy);
    }
}
