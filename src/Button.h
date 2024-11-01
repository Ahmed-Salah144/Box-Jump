#include<raylib.h>
class Button
{
public:
    Texture2D button_texture;
    Texture2D hover[50];
    Rectangle hitbox;
    int hoverframes=0;
    float elapsedtime=0.0f,Updatetime=0.07f;
    int currentframe=0;

    Button(Rectangle);
    void LoadPlayButton();
    void LoadOptionsButton();
    void LoadQuitButton();
    bool Update();
    ~Button();
};