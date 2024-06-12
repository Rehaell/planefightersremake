#include "raylib.h"
#include <stdio.h> 
#include <vector>
#include <stddef.h>
#include <stdlib.h>
#include "functions.h"
#include <cmath>
#include "raymath.h"



int main()
{

    //score
    int score = 0;
    bool gameover = false;

    InitWindow(0, 0, "Plane Fighters Remake!");
    SetWindowState(FLAG_FULLSCREEN_MODE);

    const float screenWidth = GetScreenWidth();
    const float screenHeight = GetScreenHeight();

    SetTargetFPS(60);

    std::vector<Rectangle> rectangles;


    std::vector<Rectangle> projectiles;
    Rectangle square = { screenWidth / 2 - 50, screenHeight-50, 50, 50 };
    
    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT) && square.x + square.width < screenWidth) square.x += 10;
        if (IsKeyDown(KEY_LEFT) && square.x > 0) square.x -= 10;
        if (IsKeyDown(KEY_DOWN) && square.y + square.height < screenHeight) square.y += 5;
        if (IsKeyDown(KEY_UP) && square.y > 0) square.y -= 10;
        if (IsKeyPressed(KEY_SPACE)) FireProjectile(projectiles, square);
        
        for (size_t i = 0; i < projectiles.size(); i++)
        {
            projectiles[i].y -= 20;
            
            if (projectiles[i].y + projectiles[i].height < 0)
            {
                projectiles.erase(projectiles.begin() + i);
                i--;
            }
        }
        
        DrawFPS(screenWidth - 80, 10);

        BeginDrawing();
        
        ClearBackground(BLACK);
        
        DrawRectangleRec(square, GRAY);

        //draw score
        DrawText(TextFormat("Score: %i", score), 10, 10, 20, WHITE);
        
        //create enemy
        if (GetRandomValue(0, 100) < 2) CreateEnemy(rectangles, screenWidth, screenHeight);

        //draw enemy
        for (size_t i = 0; i < rectangles.size(); i++)
        {
            rectangles[i].y += 5;
            
            // move the enemy towards the player direction once and keep it moving that direction
            Vector2 direction = { square.x - rectangles[i].x, square.y - rectangles[i].y };
            direction = Vector2Normalize(direction);
            // if enemy is below the player, dont move it towards the player
            if (rectangles[i].y > square.y)
            {
                rectangles[i].x += 0;
                 //increase speed
                rectangles[i].y += 10;
            }
            else rectangles[i].x += direction.x * 5;

            

            DrawRectangleRec(rectangles[i], BLUE);
            if (rectangles[i].y > screenHeight || rectangles[i].x > screenWidth || rectangles[i].x < 0)
            {
                rectangles.erase(rectangles.begin() + i);
                i--;
            }
        }

        
        for (const auto& projectile : projectiles)
        {
            DrawRectangleRec(projectile, RED);
        }
        

        // collision detection
        for (size_t i = 0; i < rectangles.size(); i++)
        {
            for (size_t j = 0; j < projectiles.size(); j++)
            {
                if (CheckCollisionRecs(rectangles[i], projectiles[j]))
                {
                    rectangles.erase(rectangles.begin() + i);
                    projectiles.erase(projectiles.begin() + j);
                    i--;
                    //add score
                    score += 10;
                    break;
                }
            }
            // collision detection with player
            if (CheckCollisionRecs(rectangles[i], square))
            {
                rectangles.erase(rectangles.begin() + i);
                i--;
                gameover = true;
                break;  

                
            }
        }


        EndDrawing();
        //game over
        if (gameover)
        {
            DrawText("Game Over", screenWidth / 2 - 50, screenHeight / 2, 20, WHITE);
            break;
        }
    }
    
    CloseWindow();

    return 0;
}