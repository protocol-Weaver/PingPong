#include <raylib.h>
#include <iostream>
#include <string>
#include <string.h>
const int screenWidth = 800;
const int screenHeight = 450;
float deltaTime =0;
float lastFrame =0;

void processInput(float& bar1, float& bar2)
{
    // float currentFrame = GetTime();
    // deltaTime = currentFrame - lastFrame;
    // lastFrame = currentFrame;

    if((IsKeyDown(KEY_W) )&& bar1 > 5)
        bar1 -= 10;
    if((IsKeyDown(KEY_S))&& bar1 < screenHeight - screenHeight/5)
        bar1 += 10;
    
    if((IsKeyDown(KEY_UP))&& bar2 > 5)
        bar2 -= 10;
    if((IsKeyDown(KEY_DOWN))&& bar2 < screenHeight - screenHeight/5)
        bar2 += 10;
        
    
}


int main(void)
{
    
    int Score1 = 0, Score2 = 0;
    
    InitWindow(screenWidth, screenHeight, "Ping Pong Game");
    float bar1 = 10;
    float bar2 = 10;
    Vector2 ballPosition = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    float ballRadius = 12;
    Vector2 ballSpeed = { 6.0f, 5.0f };
    Rectangle boxA = {screenWidth/(20),bar1,15,screenHeight/5};
    Rectangle ball = {ballPosition.x,ballPosition.y,25,25};
    Rectangle boxB = {screenWidth/1.1,bar2,15,screenHeight/5};


    SetTargetFPS(60);               
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        processInput(bar1,bar2);
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        boxA.y = bar1;
        boxB.y = bar2;
        ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;

        ball.x = ballPosition.x-12;
        ball.y = ballPosition.y-12;
        bool collisionA = CheckCollisionRecs(ball,boxA);
        bool collisionB = CheckCollisionRecs(ball,boxB);

        // Check walls collision for bouncing
        if ((ballPosition.x >= (GetScreenWidth() - ballRadius)) || (ballPosition.x <= ballRadius)){ 
            
            if(ballPosition.x > screenWidth-ballRadius)
            {
                Score2++;
            }
            else 
            {
                Score1++;
            }
            ballPosition.x = screenWidth/2;
            ballPosition.y = screenHeight/2;
            ballSpeed.x *= -1;
        }
        if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius)) ballSpeed.y *= -1.0f;
        if(collisionA|| collisionB){
            ballSpeed.x *= -1.0f;
            ballSpeed.y *= -1.0f;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            std::string txt = std::to_string(Score1) ;
            const char* text = txt.c_str();
            std::string txt2 = std::to_string(Score2) ;
            const char* text2 = txt2.c_str();
            ClearBackground(RAYWHITE);
            DrawText(text2,5,5,40, LIGHTGRAY);
            DrawText(text,screenWidth-25,5,40, LIGHTGRAY);
            DrawRectangleRec(boxA,SKYBLUE);
            DrawRectangleRec(boxB,SKYBLUE);
            DrawCircleV(ballPosition,ballRadius,MAROON);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}