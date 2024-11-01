#include "Background.h"
void Background::LoadBackground3()
{
    layers.push_back(LoadTexture("game_background_3/layers/sky.png"));
    layers.push_back(LoadTexture("game_background_3/layers/clouds_1.png"));
    layers.push_back(LoadTexture("game_background_3/layers/rocks.png"));
    layers.push_back(LoadTexture("game_background_3/layers/clouds_2.png"));
    layers.push_back(LoadTexture("game_background_3/layers/ground_1.png"));
    layers.push_back(LoadTexture("game_background_3/layers/ground_2.png"));
    layers.push_back(LoadTexture("game_background_3/layers/ground_3.png"));
    layers.push_back(LoadTexture("game_background_3/layers/plant.png"));
    layerspeed=vector<float>(layers.size());
    layerspeed[0]=10;
    for(int i=1;i<layerspeed.size();i++)
    {
        layerspeed[i]=layerspeed[i-1]+15;
    }
    layerx=vector<float>(layers.size());
}
void Background::LoadBackground2()
{
    layers.push_back(LoadTexture("game_background_2/layers/sky.png"));
    layers.push_back(LoadTexture("game_background_2/layers/clouds_1.png"));
    layers.push_back(LoadTexture("game_background_2/layers/rocks_3.png"));
    layers.push_back(LoadTexture("game_background_2/layers/clouds_2.png"));
    layers.push_back(LoadTexture("game_background_2/layers/rocks_2.png"));
    layers.push_back(LoadTexture("game_background_2/layers/clouds_3.png"));
    layers.push_back(LoadTexture("game_background_2/layers/birds.png"));
    layers.push_back(LoadTexture("game_background_2/layers/rocks_1.png"));
    layers.push_back(LoadTexture("game_background_2/layers/pines.png"));
    layerspeed=vector<float>(layers.size());
    layerspeed[0]=10;
    for(int i=1;i<layerspeed.size();i++)
    {
        layerspeed[i]=layerspeed[i-1]+15;
    }
    layerx=vector<float>(layers.size());
}
void Background::LoadBackground1()
{
    layers.push_back(LoadTexture("game_background_1/layers/sky.png"));
    layers.push_back(LoadTexture("game_background_1/layers/clouds_1.png"));
    layers.push_back(LoadTexture("game_background_1/layers/clouds_2.png"));
    layers.push_back(LoadTexture("game_background_1/layers/rocks_1.png"));
    layers.push_back(LoadTexture("game_background_1/layers/clouds_3.png"));
    layers.push_back(LoadTexture("game_background_1/layers/rocks_2.png"));
    layers.push_back(LoadTexture("game_background_1/layers/clouds_4.png"));
    layerspeed=vector<float>(layers.size());
    layerspeed[0]=10;
    for(int i=1;i<layerspeed.size();i++)
    {
        layerspeed[i]=layerspeed[i-1]+15;
    }
    layerx=vector<float>(layers.size());
}
void Background::LoadBackground4()
{
    layers.push_back(LoadTexture("game_background_4/layers/sky.png"));
    layers.push_back(LoadTexture("game_background_4/layers/clouds_1.png"));
    layers.push_back(LoadTexture("game_background_4/layers/rocks.png"));
    layers.push_back(LoadTexture("game_background_4/layers/clouds_2.png"));
    layers.push_back(LoadTexture("game_background_4/layers/ground_.png"));

    layerspeed=vector<float>(layers.size());
    layerspeed[0]=10;
    for(int i=1;i<layerspeed.size();i++)
    {
        layerspeed[i]=layerspeed[i-1]+15;
    }
    layerx=vector<float>(layers.size());
}
void Background::LoadNextBackground()
{
    key++;
    key%=4;
    UnloadBackground();
    switch(key)
    {
        case 0:LoadBackground1();break;
        case 1:LoadBackground2();break;
        case 2:LoadBackground3();break;
        case 3:LoadBackground4();break;
    }
}
void Background::UpdateBackground()
{
    int swap = 5^10;
    if(IsKeyPressed(KEY_LEFT_SHIFT))
        speed=swap^(int)speed;
    for(int i=0;i<layers.size();i++)
    {
        layerx[i]-=layerspeed[i]*GetFrameTime()*speed;
        if(layerx[i]<=-layers[i].width)
            layerx[i]=0;
        if(layerx[i]>=layers[i].width)
            layerx[i]=0;
    }
    for(int i=0;i<layers.size();i++)
    {
        DrawTextureEx(layers[i],Vector2{layerx[i],0},0.0f,1.0f,WHITE);
        DrawTextureEx(layers[i],Vector2{layerx[i]+layers[i].width,0},0.0f,1.0f,WHITE);
    }
}
void Background::UnloadBackground()
{
    for(int i=0;i<layers.size();i++)
    {
        UnloadTexture(layers[i]);
    }
    layerspeed.clear();
    layerx.clear();
    layers.clear();
}
Background::~Background()
{
    UnloadBackground();
}