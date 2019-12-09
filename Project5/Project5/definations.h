#pragma once
#include <Graphics.hpp> 
#include <iostream>
#include<cmath>
#include <windows.h> 
#include <sstream>
#include <Audio.hpp>




using namespace std;
using namespace sf;

constexpr float ballradius{ 10.f }, ballvelocity{ 3.f },
paddlewidth{ 30.f }, paddleheight{ 150.f }, paddlevelocity{ 5.f },
brickwidth{ 60.f }, brickheight{ 20.f };
int i, j, splashscreenflag=1,endgameflag;
int restartflag = 0;

SoundBuffer buffer,buffer1,buffer2,buffer3;
Sound sound,sound1,sound2,sound3;
Clock clock1,clock2;
Time elapsed1;

Texture gameovert;
Sprite gameovers;
Texture splashscreent;
Sprite splashscreens;
Texture playbuttont;
Sprite playbuttons;

Text scoreCurrent,score,gameovertext,gametitletext,gametitletextc,etext,emntext,etext2;


VideoMode desktop = VideoMode::getDesktopMode();
RenderWindow window(VideoMode(1024, 768, desktop.bitsPerPixel), "Unlimited Breakout Clone V.1", Style::Resize | Style::Close);








