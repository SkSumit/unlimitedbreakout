#pragma once

#include<C:\Users\kolsu\source\repos\Project5\Project5\definations.h>
//#define EXIT_FAILURE 0

using namespace std;
using namespace sf;

struct ball
{
	CircleShape ballshape;

	Vector2f velocity{ -ballvelocity,-ballvelocity };
	float bpx() { return ballshape.getPosition().x; }
	float bpy() { return ballshape.getPosition().y; }
	float bdleft() { return bpx() - ballshape.getRadius(); }
	float bdright() { return bpx() + ballshape.getRadius(); }
	float bdtop() { return bpy() - ballshape.getRadius(); }
	float bdbottom() { return bpy() + ballshape.getRadius(); }

	ball()
	{
		ballshape.setOrigin(ballradius, ballradius);
		ballshape.setRadius(ballradius);
		ballshape.setFillColor(Color::Yellow);
		ballshape.setPosition(512, 720);
	}

	void ballmove()
	{
		ballshape.move(velocity);
		if (bdleft() < 0)
		{
			velocity.x = ballvelocity;
		}
		else if (bdright() > 1024)
		{
			velocity.x = -ballvelocity;
		}

		else if (bdtop() < 0)
		{
			velocity.y = ballvelocity;
		}

		else if (bdbottom() > 768)
		{
			velocity.y = -ballvelocity;
		}
	}
};

struct paddle
{
	RectangleShape paddleshape;
	Vector2f paddlesize{ paddleheight,paddlewidth };
	Vector2f velocity{ -paddlevelocity ,0 };
	float ppx() { return paddleshape.getPosition().x; }
	float ppy() { return paddleshape.getPosition().y; }
	float pdleft() { return ppx() - paddleshape.getSize().x / 2.f; }
	float pdright() { return ppx() + paddleshape.getSize().x / 2.f; }
	float pdtop() { return ppy() - paddleshape.getSize().y / 2.f; }
	float pdbottom() { return ppy() + paddleshape.getSize().y / 2.f; }
	paddle()
	{
		paddleshape.setFillColor(Color::Red);
		paddleshape.setSize(paddlesize);
		paddleshape.setPosition(512, 750);
		paddleshape.setOrigin(paddleheight / 2.f, paddlewidth / 2.f);
	}
	void paddlemove()
	{
		paddleshape.move(velocity);
		if (Keyboard::isKeyPressed(Keyboard::Key::Right) && pdright() < 1024)
		{
			velocity.x = paddlevelocity;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left) && pdleft() > 0)
		{
			velocity.x = -paddlevelocity;
		}
		else
			velocity.x = 0;
	}

};

struct Brick
{
	RectangleShape shapebrick;
	static int bricksD;
	bool destroyed{ false };
	bool destroyednot{ true };

	Brick(float x , float y)
	{
		shapebrick.setPosition(x, y);
		shapebrick.setSize({ brickwidth, brickheight });
		shapebrick.setFillColor(Color::Yellow);
		shapebrick.setOrigin(brickheight / 2.f, brickwidth / 2.f);
	}

	float x() { return shapebrick.getPosition().x; }
	float y() { return shapebrick.getPosition().y; }
	float left() { return x() - shapebrick.getSize().x / 2.f; }
	float right() { return x() + shapebrick.getSize().x / 2.f; }
	float top() { return y() - shapebrick.getSize().y / 2.f; }
	float bottom() { return y() + shapebrick.getSize().y / 2.f; }
	

	
};
int Brick::bricksD = 0;


	
	

        