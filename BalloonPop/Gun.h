#ifndef INCLUDED_GUN
#define INCLUDED_GUN

#include <SFML\Graphics.hpp>

class Gun{
public:
	Gun();
	~Gun();
	float getPositionX();
	float getPositionY();
	void fire();

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};

#endif