#ifndef INCLUDED_BUTTON
#define INCLUDED_BUTTON

#include "GameState.h"
#include <sfml/Graphics.hpp>

class Button{
public:
	Button(std::string name, GameState::GameStates state);
	void draw(sf::RenderWindow &window);
	void onCreate();
	void setColor(sf::Color color);
	void setSize();
	void setPosition(float x, float y);
	sf::IntRect getButtonRect();
	void update();
	GameState::GameStates Button::getGameState();
	~Button();
private:
	void setRect();
	sf::Text mText;
	sf::RectangleShape mShape;
	sf::Vector2f mPos;
	std::string mName;
	sf::Font mFont;
	GameState::GameStates mState;
};

#endif