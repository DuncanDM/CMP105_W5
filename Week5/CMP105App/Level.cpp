#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	zombie.setInput(input);

	zombTexture.loadFromFile("gfx/animZombie.png");
	zombie.setSize(sf::Vector2f(55, 108));
	zombie.setPosition(100, 100);
	zombie.setTexture(&zombTexture);

	mario.setInput(input);

	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	mario.setSize(sf::Vector2f(45, 63));
	mario.setPosition(600, 300);
	mario.setTexture(&marioTexture);

	speed = 100.f;
	speedMario = 500.f;

	view = window->getView();
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	if (input->isKeyDown(sf::Keyboard::D))
	{
		zombie.move(speed * dt, 0);
	}

	if (input->isKeyDown(sf::Keyboard::A))
	{
		zombie.move(-speed * dt, 0);
	}

	if (input->isKeyDown(sf::Keyboard::Down))
	{
		
	}
	else if (input->isKeyDown(sf::Keyboard::Right))
	{
		mario.move(speedMario * dt, 0);
	}
	else if (input->isKeyDown(sf::Keyboard::Left))
	{
		mario.move(-speedMario * dt, 0);
	}
}

// Update game objects
void Level::update(float dt)
{
	winSize = window->getSize();
	marioPos = mario.getPosition();
	viewPos = view.getCenter().x;
	rightBorder = viewPos + (winSize.x / 2) - 400.f;
	leftBorder = viewPos - (winSize.x / 2) + 400.f;

	if (marioPos.y != winSize.y / 2)
	{
		mario.setPosition(marioPos.x, winSize.y / 2);
	}

	if (marioPos.x >= rightBorder)
	{
		view = window->getView();
		view.move(speedMario * dt, 0);
		window->setView(view);
	}

	if (marioPos.x <= leftBorder && viewPos >=0)
	{
		view = window->getView();
		view.move(-speedMario * dt, 0);
		window->setView(view);
	}

	zombie.update(dt);
	mario.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(zombie);
	window->draw(mario);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}