#include "Player.h"
Player::Player()
{
    posx=GetScreenWidth()/10.0f;
    posy=GetScreenHeight()-250;
    Hitbox=Rectangle{posx+50,posy+40,120,200};
    prepareidleanimation();
    preparewalkinganimation();
    preparejumpinganimation();
    preparedustanimation();
    preparerunninganimation();
    preparefallinganimation();
}
void Player::UpdateData(Terrain* obstacles,int n)
{
    if(posy<GetScreenHeight()-250 && !jumping && !Check_Collision_Down(obstacles,n)&& falling)
    {
        posy+=10+airtime*20;
        animationqueue.push(5);
    }
    else if(!jumping && falling)
    {
        airtime=0;
        falling=false;
        do
        {
            posy-=5;
        }while(Check_Collision_Down(obstacles,n));
        posy+=5;
    }
    if(jumping && airtime < 1)
    {
        animationqueue.push(2);
        posy-=10-airtime*10+sprinting*5;
        if(Check_Collision_Up(obstacles,n))
        {
            jumping=false;
            airtime=0;
            do
            {
                posy+=4;
            }while(Check_Collision_Up(obstacles,n));

        }
    }
    else if(jumping)
    {
        animationqueue.push(2);
        jumping=false;
        falling=true;
        airtime=0;
    }
    if(IsKeyPressed(KEY_LEFT_SHIFT))
    {
        sprinting^=1;
    }
    if(IsKeyPressed(KEY_SPACE) && !jumping && !falling)
    {
        animationqueue.push(2);
        animationqueue.push(3);
        jumping=true;
        airtime=0;
    }
    if(!(IsKeyDown(KEY_LEFT) ^ IsKeyDown(KEY_RIGHT)) && ! jumping && ! falling)
    {    
        animationqueue.push(0);
        if(posx>-100)
        {
            posx-=5;
        }
        else
            posx=-100;
        if(Check_Collision_Horizontal(obstacles,n)|| (jumping && Check_Collision_Down(obstacles,n)))
        {
            posx+=5;
        }
    }
    if(IsKeyDown(KEY_RIGHT) && ! IsKeyDown(KEY_LEFT))
    {
        if(posx<GetScreenWidth()-100)
        {    
            if(sprinting)
                posx+=10;
            else
                posx+=5;
            if(Check_Collision_Horizontal(obstacles,n) || (jumping && Check_Collision_Down(obstacles,n)))
            {
                posx-=10;
                if(sprinting)
                    posx-=5;
            }
        }
        else
            posx=GetScreenWidth()-100;
        direction=1;
        if(!jumping && !falling)
        {
            animationqueue.push(3);
            if(sprinting)
                animationqueue.push(4);
            else
                animationqueue.push(1);
        }
    }
    if(IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT))
    {
        if(posx>-100)
        {
            if(sprinting)
                posx-=15;
            else
                posx-=7;
            if(Check_Collision_Horizontal(obstacles,n) || (jumping && Check_Collision_Down(obstacles,n)))
            {
                posx+=2;
                if(sprinting)
                    posx+=8;
            }
        }
        else
            posx=-100;
        direction=-1;
        if(!jumping&& !falling)
        {
            animationqueue.push(3);
            if(sprinting)
                animationqueue.push(4);
            else
                animationqueue.push(1);
            
        }
    }
    Unclip(obstacles,n);
    if(posy<GetScreenHeight()-256)
    {
        posy+=10;
        if(Check_Collision_Down(obstacles,n)) 
            falling=false; 
        else
            falling=true;
        posy-=10;
    }
}
void Player::animate()
{
    //GetHitbox();
    //DrawRectangleRec(Hitbox,RAYWHITE);
    while(!animationqueue.empty())
    {
        animation(animationqueue.front());
        animationqueue.pop();
    }
}
void Player::prepareidleanimation()
{
    framecount[0]=4;
    updatetime[0] = 0.15f;
    spritesheet[0]=LoadTexture("Dude_Monster/Dude_Monster_Idle_4.png");
    for(int i=0;i<framecount[0];i++)
    {
        frames[0][i]={(float)(i*32),0.0f,32.0f,32.0f};
    }
    currentframe[0] = 0;
    frametime[0] = 0.0f;
}
void Player::preparewalkinganimation()
{
    framecount[1]=6;
    updatetime[1] = 0.1f;
    spritesheet[1]=LoadTexture("Dude_Monster/Dude_Monster_Walk_6.png");
    for(int i=0;i<framecount[1];i++)
    {
        frames[1][i]={i*32.0f,0.0f,32.0f,32.0f};
    }
    currentframe[1] = 0;
    frametime[1] = 0.0f;
    
}
void Player::preparejumpinganimation()
{
    framecount[2]=5;
    updatetime[2] = 0.2f;
    spritesheet[2]=LoadTexture("Dude_Monster/Dude_Monster_Jump_8.png");
    for(int i=0;i<framecount[2];i++)
    {
        frames[2][i]={i*32.0f,0.0f,32.0f,32.0f};
    }
    currentframe[2] = 0;
    frametime[2] = 0.0f;
    
}
void Player::preparedustanimation()
{
    framecount[3]=6;
    updatetime[3] = 0.1f;
    spritesheet[3]=LoadTexture("Dude_Monster/Walk_Run_Push_Dust_6.png");
    for(int i=0;i<framecount[3];i++)
    {
        frames[3][i]={i*32.0f,0.0f,32.0f,32.0f};
    }
    currentframe[3] = 0;
    frametime[3] = 0.0f;
}
void Player::preparerunninganimation()
{
    framecount[4]=6;
    updatetime[4] = 0.1f;
    spritesheet[4]=LoadTexture("Dude_Monster/Dude_Monster_Run_6.png");
    for(int i=0;i<framecount[4];i++)
    {
        frames[4][i]={i*32.0f,0.0f,32.0f,32.0f};
    }
    currentframe[4] = 0;
    frametime[4] = 0.0f;
}
void Player::preparefallinganimation()
{
    framecount[5]=3;
    updatetime[5] = 0.15f;
    spritesheet[5]=LoadTexture("Dude_Monster/Dude_Monster_Jump_8.png");
    for(int i=5;i<framecount[5]+5;i++)
    {
        frames[5][i-5]={i*32.0f,0.0f,32.0f,32.0f};
    }
    currentframe[5] = 0;
    frametime[5] = 0.0f;
    
}
void Player::animation(int index)
{
    frametime[index]+=GetFrameTime();
    if(index==2 || index==5)
        airtime+=GetFrameTime();
    if(frametime[index]>=updatetime[index])
    {
        frametime[index]=0.0f;
        currentframe[index]++;
        currentframe[index]%=framecount[index];
    }
    Rectangle source=frames[index][currentframe[index]];
    source.width*=direction;
    DrawTexturePro(spritesheet[index], source,Rectangle{posx,posy,256.0f,256.0f} ,{ 16.0f, 16.0f },0.0f,WHITE);
}
bool Player::Check_Collision_Up(Terrain* obstacles,int n)
{
    GetHitbox();
    for(int i=0;i<n;i++)
    {
        if(CheckCollisionPointRec({centerx,centery-100},obstacles[i].GetHitbox()))
            return true;
    }
    return false;
}
bool Player::Check_Collision_Down(Terrain* obstacles,int n)
{
    GetHitbox();
    for(int i=0;i<n;i++)
    {
        if(CheckCollisionPointRec({centerx,centery+100},obstacles[i].GetHitbox()))
            return true;
    }
    return false;
}
bool Player::Check_Collision_Hitbox(Terrain* obstacles,int n)
{
    GetHitbox();
    for(int i=0;i<n;i++)
    {
        if(CheckCollisionRecs(obstacles[i].GetHitbox(),Hitbox))
            return true;
    }
    return false;
}
bool Player::Check_Collision_Horizontal(Terrain* obstacles,int n)
{
    GetHitbox();
    for(int i=0;i<n;i++)
    {
        if(CheckCollisionPointRec({centerx+60,centery},obstacles[i].GetHitbox()))
            return true;
        if(CheckCollisionPointRec({centerx-60,centery},obstacles[i].GetHitbox()))
            return true;
    }
    return false;
}
void Player::Unclip(Terrain* obstacles,int n)
{
    do
    {
      posy-=5;
    } while (Check_Collision_Down(obstacles,n));
    posy+=5;
    
}
Rectangle Player::GetHitbox()
{
    Hitbox.x=posx+50;
    Hitbox.y=posy+40;
    centerx=Hitbox.x+60;
    centery=Hitbox.y+100;
    return Hitbox;
}
