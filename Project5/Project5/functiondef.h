#pragma once
#define EXIT_FAILURE 0
#include<C:\Users\kolsu\source\repos\Project5\Project5\definations.h>


bool intersection(paddle& p, ball& b)
{
	return (p.pdright() >= b.bdleft() && p.pdleft() <= b.bdright() &&
		p.pdbottom() >= b.bdtop() && p.pdtop() <= b.bdbottom());
}

bool intersectionb(Brick& p, ball& b)
{
	return (p.right() >= b.bdleft() && p.left() <= b.bdright() &&
		p.bottom() >= b.bdtop() && p.top() <= b.bdbottom());
}

void collusion(paddle& p, ball& b)
{
	if (!intersection(p, b)) return;

	
	sound1.play();
	sound1.setVolume(10.f);
	float overlapLeft{ b.bdright() - p.pdleft() };
	float overlapRight{ p.pdright() - b.bdleft() };
	float overlapTop{ b.bdbottom() - p.pdtop() };
	float overlapBottom{ p.pdbottom() - b.bdtop() };

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

	if (abs(minOverlapX) < abs(minOverlapY))
		b.velocity.x = ballFromLeft ? -ballvelocity : ballvelocity;
	else
		b.velocity.y = ballFromTop ? -ballvelocity : ballvelocity;
}

void collusionb(Brick& p, ball& b)
{
	if (!intersectionb(p, b)) return;
	p.destroyed = true;
	
	
	sound.play();
	sound.setVolume(10.f);

	float overlapLeft{ b.bdright() - p.left() };
	float overlapRight{ p.right() - b.bdleft() };
	float overlapTop{ b.bdbottom() - p.top() };
	float overlapBottom{ p.bottom() - b.bdtop() };

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

	if (abs(minOverlapX) < abs(minOverlapY))
		b.velocity.x = ballFromLeft ? -ballvelocity : ballvelocity;
	else
		b.velocity.y = ballFromTop ? -ballvelocity : ballvelocity;
}
void createbricks(vector<Brick>& bricksgrid)
{
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			bricksgrid.emplace_back(
				(i + 1) * (brickwidth + 10) + 100, (j + 2) * (brickheight + 10));

		}
	}
}

void menucontrol() {
	Event event;
	while (window.pollEvent(event))
	{


		switch (event.type)
		{
		case Event::MouseMoved:
		{
			Vector2i mousePos = Mouse::getPosition(window);
			Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			if (playbuttons.getGlobalBounds().contains(mousePosF))
			{
				playbuttons.setColor(Color::Red);
				sound2.play();
				sound2.setVolume(10.f);

			}
			else if (etext.getGlobalBounds().contains(mousePosF))
			{
				etext.setFillColor(Color::Red);
				sound2.play();
				sound2.setVolume(10.f);

			}
			else if (gametitletext.getGlobalBounds().contains(mousePosF))
			{
				gametitletext.setFillColor(Color::Yellow);
				sound2.play();
				sound2.setVolume(10.f);

			}

			else
			{
				playbuttons.setColor(Color(255, 255, 255));
				etext.setFillColor(Color(255, 255, 255));
				gametitletext.setFillColor(Color::White);
				sound2.stop();
			}
		}

		case Event::MouseButtonPressed:
		{
			Vector2i mousePos = Mouse::getPosition(window);
			Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			if (Mouse::isButtonPressed(sf::Mouse::Left) && playbuttons.getGlobalBounds().contains(mousePosF))
			{
				clock1.restart();
				splashscreenflag = 0;

			}
			else if (Mouse::isButtonPressed(sf::Mouse::Left) && etext.getGlobalBounds().contains(mousePosF))
			{
				window.close();
			}


		}

		}
	}
}

void mainmenu()
{
	while (splashscreenflag == 2)
	{
		window.clear(Color::Black);
		window.draw(playbuttons);
		window.draw(gametitletext);
		window.draw(gametitletextc);
		window.draw(etext);
		window.display();
		menucontrol();
		window.clear();

	}

}

void gameovermenu() {
	Event event;
	while (window.pollEvent(event))
	{

	  switch (event.type)
	  {
		case Event::MouseMoved:
		{
			Vector2i mousePos = Mouse::getPosition(window);
			Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			if (score.getGlobalBounds().contains(mousePosF))
			{
				score.setFillColor(Color::Yellow);
				

			}
			else if (scoreCurrent.getGlobalBounds().contains(mousePosF))
			{
				scoreCurrent.setFillColor(Color::White);
				

			}
			else if (gameovertext.getGlobalBounds().contains(mousePosF))
			{
				gameovertext.setFillColor(Color::Yellow);
				sound2.play();
				sound2.setVolume(10.f);

			}

			else if (etext2.getGlobalBounds().contains(mousePosF))
			{
				etext2.setFillColor(Color::Red);
				sound2.play();
				sound2.setVolume(10.f);

			}
			else if (emntext.getGlobalBounds().contains(mousePosF))
			{
				emntext.setFillColor(Color::Red);
				sound2.play();
				sound2.setVolume(10.f);

			}

			else
			{
				score.setFillColor(Color(255, 255, 255));
				scoreCurrent.setFillColor(Color(255, 255, 255));
				gameovertext.setFillColor(Color::White);
				etext2.setFillColor(Color(255, 255, 255));
				emntext.setFillColor(Color(255, 255, 255));
				sound2.stop();
			}
		}

		case Event::MouseButtonPressed:
		{
			Vector2i mousePos = Mouse::getPosition(window);
			Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			if (Mouse::isButtonPressed(sf::Mouse::Left) && etext2.getGlobalBounds().contains(mousePosF))
			{
				window.close();
			}
			else if (Mouse::isButtonPressed(sf::Mouse::Left) && emntext.getGlobalBounds().contains(mousePosF))
			{
				splashscreenflag = 2;
				endgameflag= 0;
				ball b;
				b.ballshape.setPosition(512, 720);
				mainmenu();
			}
		}

	  }
	}
}

void startsc()
{
	while (splashscreenflag == 1)
	{
		window.clear(Color::Black);
		window.draw(splashscreens);
		window.display();
		if (clock1.getElapsedTime().asSeconds() > 5)
		{
			splashscreenflag = 2;
			window.clear();
		}
	}
}

void gameoversc(Brick &b )
{
	
	while (endgameflag == 1)
	{
		std::ostringstream s;
		s << b.bricksD;
		scoreCurrent.setString(s.str());
		window.clear();
		window.draw(gameovertext);
		window.draw(score);
		window.draw(scoreCurrent);
		window.draw(emntext);
		window.draw(etext2);
		gameovermenu();
		restartflag = 1;
		window.display();

	}
}

