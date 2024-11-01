#include <raylib.h>
#include <iostream>
#include "Background.h"
#include "Player.h"
#include "Terrain.h"
#include "Button.h"
using namespace std;
int main()
{
    const int screenWidth = 1800;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "GAME");
    SetExitKey(KEY_NULL);
    Background Bg;
    Texture2D menubg=LoadTexture("game_background_1/game_background_1.png");
    Texture2D textwall=LoadTexture("Blue_buttons/blue button.png");
    Texture2D heart=LoadTexture("Tiles/hud_heartFull.png");
    Player player;
    float score=0;
    float elapsedtime=0;
    string scorestr;
    bool paused=true;
    bool options=false;
    Button play_button({screenWidth/2-300,screenHeight/2-240,600.0f,160.0f});
    Button options_button({screenWidth/2-300,screenHeight/2-80,600.0f,160.0f});
    Button quit_button({screenWidth/2-300,screenHeight/2+80,600.0f,160.0f});
    play_button.LoadPlayButton();
    quit_button.LoadQuitButton();
    options_button.LoadOptionsButton();
    Bg.LoadBackground1(); 
    Terrain boxes[15];
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        if(IsKeyPressed(KEY_ESCAPE))
            {
                paused^=1;
                if(options)
                {
                    play_button.hitbox.x+=400;
                    options_button.hitbox.x+=400;
                    quit_button.hitbox.x+=400;
                    options=false;
                }
            }
        if(!paused)
        {
            elapsedtime+=GetFrameTime();
            player.UpdateData(boxes,15);
            score+=GetFrameTime()*elapsedtime*(1+player.sprinting);
            scorestr=to_string((int)score);
            if(score>10200)
            {
                paused^=1;
            }
        }
        BeginDrawing();
        if(!paused)
        {
            ClearBackground(RAYWHITE);       
            Bg.UpdateBackground();
            for(int i=0 ;i<5 ;i++)
                boxes[i].Update(&player);
            if(IsKeyPressed(KEY_ENTER))
            {
                Bg.LoadNextBackground();
            }
            player.animate();
            DrawText(scorestr.c_str(),screenWidth/15,40,150,RAYWHITE);
        }
        else
        {
            ClearBackground(RAYWHITE);
            DrawTexture(menubg,0,0,RAYWHITE);
            if(score>10000)
            {
                DrawText("CONGRATULATIONS YOU GOT 10 000 POINTS",50,100,75,WHITE);
                DrawText("THANK YOU FOR PLAYING MY GAME",215,screenHeight-200,75,WHITE);
                DrawTexturePro(heart,{0,0,53,45},{screenWidth/2-170,screenHeight-125,106,90},{0,0},0.0f,RAYWHITE);
                DrawTexturePro(heart,{0,0,53,45},{screenWidth/2-55,screenHeight-125,106,90},{0,0},0.0f,RAYWHITE);
                DrawTexturePro(heart,{0,0,53,45},{screenWidth/2+60,screenHeight-125,106,90},{0,0},0.0f,RAYWHITE);
            }
            else
            {
                DrawText("GET 10 000 POINTS",530,100,75,WHITE);
            }
            if(play_button.Update())
            {
                paused^=1;
                if(options)
                {
                    play_button.hitbox.x+=400;
                    options_button.hitbox.x+=400;
                    quit_button.hitbox.x+=400;
                    options=false;
                }
            }
            if(quit_button.Update())
                break;
            if(options_button.Update())
            {
                if(!options)
                {
                    play_button.hitbox.x-=400;
                    options_button.hitbox.x-=400;
                    quit_button.hitbox.x-=400;
                    options=true;
                }
                else
                {
                    play_button.hitbox.x+=400;
                    options_button.hitbox.x+=400;
                    quit_button.hitbox.x+=400;
                    options=false;
                }

            }
            if(options)
            {
                DrawTexturePro(textwall,{0.0f,0.0f,300.0f,80.0f},{screenWidth-800,screenHeight/2-240,600.0f,160.0f},{0,0},0.0f,RAYWHITE);
                DrawTexturePro(textwall,{0.0f,0.0f,300.0f,80.0f},{screenWidth-800,screenHeight/2-80,600.0f,160.0f},{0,0},0.0f,RAYWHITE);
                DrawTexturePro(textwall,{0.0f,0.0f,300.0f,80.0f},{screenWidth-800,screenHeight/2+80,600.0f,160.0f},{0,0},0.0f,RAYWHITE);
                DrawText("USE ARROW KEYS TO",screenWidth-750,screenHeight/2-200,45,RAYWHITE);
                DrawText("MOVE LEFT AND RIGHT",screenWidth-770,screenHeight/2-150,45,RAYWHITE);
                DrawText("LSHIFT TO SPRINT",screenWidth-720,screenHeight/2-50,45,RAYWHITE);
                DrawText("SPACE TO JUMP",screenWidth-690,screenHeight/2,45,RAYWHITE);
                DrawText("ESC TO PAUSE",screenWidth-680,screenHeight/2+110,45,RAYWHITE);
                DrawText("ENT FOR BACKGROUND",screenWidth-760,screenHeight/2+160,45,RAYWHITE);
            }
        }
        EndDrawing();
    }
    Bg.UnloadBackground();
    CloseWindow();
    return 0;
}