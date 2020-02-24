#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include "Zombie.h"
#include "Mario.h"
#include <string>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	Zombie zombie;
	sf::Texture zombTexture;

	Mario mario;
	sf::Texture marioTexture;

	float speed;
	float speedMario;

	sf::View view;

	float viewPos;
	float leftBorder;
	float rightBorder;
	sf::Vector2f marioPos;
	sf::Vector2u winSize;
};