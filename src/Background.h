#pragma once
#include <raylib.h>
#include <vector>
#include <string>
using namespace std;
class Background
{
    public:
    vector<Texture2D> layers;
    vector<float> layerx;
    vector<float> layerspeed;
    float speed = 5;
    int key=0;
    void LoadNextBackground();
    void LoadBackground3();
    void LoadBackground1();
    void LoadBackground2();
    void LoadBackground4();
    void UpdateBackground();
    void UnloadBackground();
    ~Background();
    
};