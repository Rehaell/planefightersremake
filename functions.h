//functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <raylib.h>
#include <vector>

void FireProjectile(std::vector<Rectangle>& projectiles, const Rectangle& shooter);
void CreateEnemy(std::vector<Rectangle>& rectangles, const float screenWidth, const float screenHeight);

void FireEnemyProjectile(std::vector<Rectangle>& projectiles, const Rectangle& shooter);

#endif // FUNCTIONS_H