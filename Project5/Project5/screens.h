#pragma once
#include<C:\Users\kolsu\source\repos\Project5\Project5\definations.h>

int res() {

	if (!splashscreent.loadFromFile("s.png"))
		return EXIT_FAILURE;

	if (!playbuttont.loadFromFile("PlayButton.png"))
		return EXIT_FAILURE;

	splashscreens.setTexture(splashscreent);
	splashscreens.setPosition(280, 100);
	
	playbuttons.setTexture(playbuttont);
	playbuttons.setPosition(400, 500);
	playbuttons.setScale(0.75, 0.65);

	buffer1.loadFromFile("paddlecollusionsound.wav");
	sound1.setBuffer(buffer1);
	buffer.loadFromFile("brickcollusionsound.wav");
	sound.setBuffer(buffer);
	buffer2.loadFromFile("buttonhoversound.wav");
	sound2.setBuffer(buffer2);
	buffer3.loadFromFile("retrosoundtrack.wav");
	sound3.setLoop(true);
	sound3.setVolume(30.f);
	sound3.setPlayingOffset(seconds(2.f));
	sound3.setBuffer(buffer3);
}
void createText(Font& f) {
	

	score.setFont(f);
	score.setFillColor(sf::Color::White);
	score.setStyle(sf::Text::Regular);
	score.setString("Score");
	score.setCharacterSize(70);
	score.setPosition(250, 570);

    scoreCurrent.setFont(f);
	scoreCurrent.setFillColor(sf::Color::Yellow);
	scoreCurrent.setStyle(sf::Text::Regular);
	scoreCurrent.setCharacterSize(70);
	scoreCurrent.setPosition(600, 570);

	gameovertext.setFont(f);
	gameovertext.setFillColor(sf::Color::White);
	gameovertext.setStyle(sf::Text::Regular);
	gameovertext.setString("Game Over");
	gameovertext.setCharacterSize(100);
	gameovertext.setPosition(180, 250);

	gametitletext.setFont(f);
	gametitletext.setFillColor(sf::Color::White);
	gametitletext.setStyle(sf::Text::Regular);
	gametitletext.setString("UNLIMITED BREAKOUT");
	gametitletext.setCharacterSize(50);
	gametitletext.setPosition(170, 100);

	gametitletextc.setFont(f);
	gametitletextc.setFillColor(sf::Color::Yellow);
	gametitletextc.setStyle(sf::Text::Regular);
	gametitletextc.setString("CLONE");
	gametitletextc.setCharacterSize(30);
	gametitletextc.setPosition(720, 160);

	etext.setFont(f);
	etext.setFillColor(sf::Color::Yellow);
	etext.setStyle(sf::Text::Regular);
	etext.setString("exit");
	etext.setCharacterSize(30);
	etext.setPosition(470, 720);

	etext2.setFont(f);
	etext2.setFillColor(sf::Color::Yellow);
	etext2.setStyle(sf::Text::Regular);
	etext2.setString("exit");
	etext2.setCharacterSize(30);
	etext2.setPosition(470, 720);

	emntext.setFont(f);
	emntext.setFillColor(sf::Color::Yellow);
	emntext.setStyle(sf::Text::Regular);
	emntext.setString("Main Menu");
	emntext.setCharacterSize(40);
	emntext.setPosition(400, 100);
}
