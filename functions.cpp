#include "functions.h"

/**
 * @brief Fires a projectile from the given shooter position.
 * 
 * This function creates a new projectile rectangle and adds it to the vector of projectiles.
 * The projectile is positioned just above the shooter's position.
 * 
 * @param projectiles The vector of projectiles to add the new projectile to.
 * @param shooter The rectangle representing the shooter's position.
 */
void FireProjectile(std::vector<Rectangle>& projectiles, const Rectangle& shooter)
{
    Rectangle projectile = { shooter.x + shooter.width / 2 - 5, shooter.y - 10, 10, 10 };
    projectiles.push_back(projectile);
}

/**
 * @brief Creates a new enemy and adds it to the vector of rectangles.
 *
 * This function creates a new enemy rectangle with a random x-coordinate within the screen width
 * and a y-coordinate of 0. The enemy rectangle has a width and height of 50 units. The newly created
 * enemy rectangle is then added to the vector of rectangles.
 *
 * @param rectangles The vector of rectangles to which the new enemy rectangle will be added.
 * @param screenWidth The width of the screen.
 * @param screenHeight The height of the screen.
 */
void CreateEnemy(std::vector<Rectangle>& rectangles, const float screenWidth, const float screenHeight)
{
    Rectangle enemy = { GetRandomValue(0, screenWidth - 50), 0, 50, 50 };
    rectangles.push_back(enemy);
}

/**
 * @brief Fires a projectile from the given shooter position.
 *
 * This function creates a new projectile rectangle and adds it to the vector of projectiles.
 * The projectile is positioned just below the shooter's position.
 *
 * @param projectiles The vector of projectiles to add the new projectile to.
 * @param shooter The rectangle representing the shooter's position.
 */
void FireEnemyProjectile(std::vector<Rectangle>& projectiles, const Rectangle& shooter)
{
    Rectangle projectile = { shooter.x + shooter.width / 2 - 5, shooter.y + 10, 10, 10 };
    projectiles.push_back(projectile);
}

