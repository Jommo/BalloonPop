#ifndef INCLUDED_MOUSEHANDLER
#define INCLUDED_MOUSEHANDLER

#include <SFML\Graphics.hpp>

class MouseHandler{
public:
	MouseHandler(sf::RenderWindow& window);
	~MouseHandler();
	int getMousePositionX();
	int getMousePositionY();
	void onClick();
	sf::IntRect getTextureRect();
	void collision(sf::IntRect &rect);
	void loadImage();
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	bool getMousePressed();
private:
	void setPosition(sf::RenderWindow& window);
	sf::View m_view;
	sf::Mouse m_mouse;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::IntRect m_textureRect;
	sf::Vector2f mousePosition;
	bool mIsDown;
	bool m_m1pressed;
	bool m_mouse1_was_pressed;
};

#endif