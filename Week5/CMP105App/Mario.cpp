#include "Mario.h"

Mario::Mario()
{
	// Setup walk animation.
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.setFrameSpeed(1.f / 10.f);

	swim.addFrame(sf::IntRect(0, 0, 16, 20));
	swim.addFrame(sf::IntRect(15, 21, 16, 20));
	swim.addFrame(sf::IntRect(31, 21, 16, 20));
	swim.setFrameSpeed(1.f / 4.f);

	duck.addFrame(sf::IntRect(0, 41, 16, 20));
	//duck.setFrameSpeed(1.f / 2.f);

	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());
}

Mario::~Mario()
{

}

void Mario::update(float dt)
{
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());

	if (input->isKeyDown(sf::Keyboard::Down))
	{
		if (currentAnimation->getFlipped())
		{
			currentAnimation = &duck;
			currentAnimation->setFlipped(true);
			setTextureRect(currentAnimation->getCurrentFrame());
		}
		else
		{
			currentAnimation = &duck;
			currentAnimation->setFlipped(false);
			setTextureRect(currentAnimation->getCurrentFrame());
		}
	}
	else if (input->isKeyDown(sf::Keyboard::Right))
	{
		currentAnimation = &walk;
		currentAnimation->setFlipped(false);
		setTextureRect(currentAnimation->getCurrentFrame());
	}
	else if (input->isKeyDown(sf::Keyboard::Left))
	{
		currentAnimation = &walk;
		currentAnimation->setFlipped(true);
		setTextureRect(currentAnimation->getCurrentFrame());
	}
	else
	{
		currentAnimation = &walk;
		currentAnimation->reset();
	}
}