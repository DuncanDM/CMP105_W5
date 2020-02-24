#include "Zombie.h"

Zombie::Zombie()
{
	// Setup walk animation.
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);

	setTextureRect(walk.getCurrentFrame());
}

Zombie::~Zombie()
{

}

void Zombie::update(float dt)
{
	if (input->isKeyDown(sf::Keyboard::D))
	{
		walk.setFlipped(false);
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
	else if (input->isKeyDown(sf::Keyboard::A))
	{
		walk.setFlipped(true);
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
}
