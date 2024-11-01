#pragma once
#include<raylib.h>
#include"Player.h"
class Player;
class Terrain{
public:
    float length,height;
    float posx,posy;
    Texture2D texture;
    Terrain(Texture2D t,float l,float h,float x,float y);
    Terrain();
    void Genrandom();
    void Update(Player* playerptr);
    Rectangle GetHitbox();
};