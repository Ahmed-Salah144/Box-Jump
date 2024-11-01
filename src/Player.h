#pragma once
#include<raylib.h>
#include"Terrain.h"
#include <queue>
using namespace std;
class Terrain;
class Player
{
private:
    void prepareidleanimation();
    void preparewalkinganimation();
    void preparejumpinganimation();
    void preparedustanimation();
    void preparerunninganimation();
    void preparefallinganimation();
    void animation(int);
public:
    float posx,posy;
    int framecount[10],currentframe[10];
    float updatetime[10],frametime[10];
    int direction=1;
    bool jumping=false;
    float airtime=0;
    bool sprinting=false;
    bool falling=false;
    queue<int> animationqueue;
    Rectangle Hitbox;
    float centerx,centery;
    Texture2D spritesheet[10];
    Rectangle frames[10][100];
    Player();
    void UpdateData(Terrain* obstacles,int n);
    void animate();
    bool Check_Collision_Up(Terrain* obstacles,int n);
    bool Check_Collision_Down(Terrain* obstacles,int n);
    bool Check_Collision_Horizontal(Terrain* obstacles,int n);
    bool Check_Collision_Hitbox(Terrain* obstacles,int n);
    void Unclip(Terrain* obstacles,int n);
    Rectangle GetHitbox();
};