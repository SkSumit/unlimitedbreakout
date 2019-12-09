#include <Graphics.hpp> 
#include <iostream>
#include<cmath>
#include <windows.h> 
#include <sstream>
#include<C:\Users\kolsu\source\repos\Project5\Project5\structdef.h>
#include<C:\Users\kolsu\source\repos\Project5\Project5\definations.h>
#include<C:\Users\kolsu\source\repos\Project5\Project5\functiondef.h>
#include<C:\Users\kolsu\source\repos\Project5\Project5\screens.h>

using namespace std;
using namespace sf;

int main()
{   
	window.setFramerateLimit(144);

	ball ball;
	paddle paddle;
	Brick b(10,20);
	Font arial;
	arial.loadFromFile("Rega.ttf");
	vector<Brick>bricksgrid;
	
	res();
	createText(arial);
    createbricks(bricksgrid);

	while (window.isOpen())
	{
		Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			window.clear();

			startsc();
			sound3.play();
			mainmenu();
          
		   if (ball.bpy() >= 759)
			{
				endgameflag=1;
				ball.ballshape.setPosition(512, 720);
				 gameoversc(b);
			}
			
			for (auto& brick : bricksgrid) collusionb(brick, ball);
			

			bricksgrid.erase
			(remove_if(begin(bricksgrid), end(bricksgrid), [](const Brick& mBrick)
				{    return mBrick.destroyed; }),
				end(bricksgrid));

		    elapsed1 = clock1.getElapsedTime();
			if (elapsed1.asSeconds() > 60 || restartflag == 1) {
				window.clear();
				createbricks(bricksgrid);
				if (restartflag == 1)
				{
					restartflag = 0;
					b.bricksD=0;
				}
			    clock1.restart();
			}

			if (b.destroyed == false) {
				++b.bricksD;
			}

			for (auto& brick : bricksgrid) window.draw(brick.shapebrick);
			
			ball.ballmove();
			paddle.paddlemove();
			collusion(paddle, ball);
			window.draw(ball.ballshape);
			window.draw(paddle.paddleshape);
			window.display();
			sound3.stop();
    }
	
return 0;

}