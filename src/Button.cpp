#include"Button.h"

Button::Button(Rectangle r)
{
    hitbox=r;
}
void Button::LoadPlayButton()
{
    button_texture=LoadTexture("Blue_buttons/Play_blue_button_300x80.png");
    hover[0]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000001.png");
    hover[1]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000002.png");
    hover[2]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000003.png");
    hover[3]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000004.png");
    hover[4]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000005.png");
    hover[5]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000006.png");
    hover[6]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000007.png");
    hover[7]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000008.png");
    hover[8]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000009.png");
    hover[9]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000010.png");
    hover[10]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000011.png");
    hover[11]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000012.png");
    hover[12]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000013.png");
    hover[13]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000014.png");
    hover[14]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000015.png");
    hover[15]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000016.png");
    hover[16]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000017.png");
    hover[17]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000018.png");
    hover[18]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000019.png");
    hover[19]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000020.png");
    hover[20]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000021.png");
    hover[21]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000022.png");
    hover[22]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000023.png");
    hover[23]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000024.png");
    hover[24]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000025.png");
    hover[25]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000026.png");
    hover[26]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000027.png");
    hover[27]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000028.png");
    hover[28]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000029.png");
    hover[29]=LoadTexture("Blue_buttons/play blue button 300x80 hover/Play button blue 300x80 hover000030.png");
    hoverframes=30;
    
}
void Button::LoadOptionsButton()
{
    button_texture=LoadTexture("Blue_buttons/options blue button 300x80.png");
    hover[0]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000001.png");
    hover[1]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000002.png");
    hover[2]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000003.png");
    hover[3]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000004.png");
    hover[4]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000005.png");
    hover[5]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000006.png");
    hover[6]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000007.png");
    hover[7]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000008.png");
    hover[8]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000009.png");
    hover[9]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000010.png");
    hover[10]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000011.png");
    hover[11]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000012.png");
    hover[12]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000013.png");
    hover[13]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000014.png");
    hover[14]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000015.png");
    hover[15]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000016.png");
    hover[16]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000017.png");
    hover[17]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000018.png");
    hover[18]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000019.png");
    hover[19]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000020.png");
    hover[20]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000021.png");
    hover[21]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000022.png");
    hover[22]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000023.png");
    hover[23]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000024.png");
    hover[24]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000025.png");
    hover[25]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000026.png");
    hover[26]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000027.png");
    hover[27]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000028.png");
    hover[28]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000029.png");
    hover[29]=LoadTexture("Blue_buttons/options blue button 300x80 hover/option button blue 300x80 hover000001000030.png");
    hoverframes=30;
}
void Button::LoadQuitButton()
{
    button_texture=LoadTexture("Blue_buttons/Quit blue button 300x80.png");
    hover[0]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000001.png");
    hover[1]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000002.png");
    hover[2]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000003.png");
    hover[3]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000004.png");
    hover[4]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000005.png");
    hover[5]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000006.png");
    hover[6]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000007.png");
    hover[7]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000008.png");
    hover[8]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000009.png");
    hover[9]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000010.png");
    hover[10]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000011.png");
    hover[11]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000012.png");
    hover[12]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000013.png");
    hover[13]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000014.png");
    hover[14]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000015.png");
    hover[15]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000016.png");
    hover[16]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000017.png");
    hover[17]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000018.png");
    hover[18]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000019.png");
    hover[19]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000020.png");
    hover[20]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000021.png");
    hover[21]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000022.png");
    hover[22]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000023.png");
    hover[23]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000024.png");
    hover[24]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000025.png");
    hover[25]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000026.png");
    hover[26]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000027.png");
    hover[27]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000028.png");
    hover[28]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000029.png");
    hover[29]=LoadTexture("Blue_buttons/Quit blue button 300x80 hover/Quit button blue 300x80 hover000030.png");
    hoverframes=30;
}
bool Button::Update()
{
    Vector2 mouse_position=GetMousePosition();
    if(CheckCollisionPointRec(mouse_position,hitbox))
    {
        elapsedtime+=GetFrameTime();
        if(elapsedtime>Updatetime)
        {
            elapsedtime=0; 
            currentframe++;
            currentframe%=hoverframes;
        }
        DrawTexturePro(hover[currentframe],{0.0f,0.0f,300.0f,80.0f},hitbox,{0,0},0.0f,RAYWHITE);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return true;
    }
    else
    {
        DrawTexturePro(button_texture,{0.0f,0.0f,300.0f,80.0f},hitbox,{0,0},0.0f,RAYWHITE);
        currentframe=0;
    }
    return false;
}
Button::~Button()
{
    UnloadTexture(button_texture);
    for(int i=0;i<hoverframes;i++)
        UnloadTexture(hover[i]);
}