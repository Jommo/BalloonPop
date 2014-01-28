#ifndef INCLUDED_GAMEMANAGER
#define INCLUDED_GAMEMANAGER

#include <SFML/Graphics.hpp>

class GameManager{
public:
	GameManager();
	~GameManager();
	sf::RenderWindow &getWindow();
	void drawInfo();
private:
	sf::RenderWindow m_window;
};

#endif