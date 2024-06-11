#include "raylib.h"
#include <stdio.h> 
#include <vector>
#include <stddef.h>
#include <stdlib.h>



void FireProjectile(std::vector<Rectangle>& projectiles, const Rectangle& shooter)
{
    Rectangle projectile = { shooter.x + shooter.width / 2 - 5, shooter.y - 10, 10, 10 };
    projectiles.push_back(projectile);
}

//create enemy
void CreateEnemy(std::vector<Rectangle>& rectangles, const float screenWidth, const float screenHeight)
{
    Rectangle enemy = { GetRandomValue(0, screenWidth - 50), 0, 50, 50 };
    rectangles.push_back(enemy);
}

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
        //DrawText(FormatText("Score: %i", score), 10, 10, 20, WHITE);
        
        //create enemy
        if (GetRandomValue(0, 100) < 2) CreateEnemy(rectangles, screenWidth, screenHeight);

        //draw enemy
        for (size_t i = 0; i < rectangles.size(); i++)
        {
            rectangles[i].y += 5;
            DrawRectangleRec(rectangles[i], BLUE);
            if (rectangles[i].y > screenHeight)
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
            //wait for 3 seconds
            for (int i = 0; i < 180; i++)
            {
                if (IsKeyPressed(KEY_ENTER)) break;
                BeginDrawing();
                EndDrawing();
            }
            break;
        }
    }
    
    CloseWindow();

    return 0;
}