#include"Terrain.h"
void Terrain::Update(Player* playerptr)
{
    posx-=5;
    /*if(CheckCollisionRecs({posx,posy,length*210.0f,height*210.0f},playerptr->GetHitbox()))
    {
        if(playerptr->posx<=posx)
            playerptr->posx-=5;
        else if(playerptr->posy+playerptr->GetHitbox().height<posy)
            playerptr->posy=posy-playerptr->GetHitbox().height;
        else if(playerptr->posy>posy+height*210.0f)
            playerptr->posy+=10;
    }*/
    if(posx+length*210<0)
        Genrandom();
    for(int i=0;i<length;i++)
        for(int j=0;j<height;j++)
            {
                DrawTexturePro(texture,Rectangle{0.0f,0.0f,70.0f,70.0f},Rectangle{posx+210*i,posy+210*j,210.0f,210.0f},{35.0f,35.0f},0.0f,WHITE);
            }
}
Terrain::Terrain(Texture2D t,float l,float h,float x,float y)
{
    length=l;
    height=h;
    posx=x;
    posy=y;
    texture=t;
}
Terrain::Terrain()
{
    Genrandom();
}
void Terrain::Genrandom()
{
    posx=GetRandomValue(10,15)*210.0f;
    posy=GetRandomValue(1,4)*210.0f-30.0f;
    length=GetRandomValue(1,4);
    height=GetRandomValue(1,1);
    if(height+posy>GetScreenHeight()-200)
        posy=810;
    texture=LoadTexture("Tiles/box.png");
}
Rectangle Terrain::GetHitbox()
{
    return Rectangle{posx-20,posy-20,length*210.0f-20,height*210.0f-30};
}