#ifndef INCLUDED_BUTTONMENU
#define INCLUDED_BUTTONMENU

#include "Button.h"
#include <SFML/Graphics.hpp>

class ButtonMenu{
public:
	ButtonMenu(sf::Vector2f pos);
	~ButtonMenu();
	void draw(sf::RenderWindow &window);
	void setPosition();
	void setSize();
	void addButton(Button* button);
	void mouseOver(sf::IntRect rect);
	void onClickListener(GameState::GameStates &state, sf::IntRect rect);
private:
	void update();
	sf::RectangleShape mShape;
	sf::Vector2f mPos;
	typedef std::vector<Button*>ButtonVector;
	ButtonVector m_buttons;
	Button *mButton;
};

#endif