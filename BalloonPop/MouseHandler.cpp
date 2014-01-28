#include "MouseHandler.h"


MouseHandler::MouseHandler(sf::RenderWindow& window) : mIsDown(false), m_m1pressed(false), m_mouse1_was_pressed(false){
	loadImage();
	m_sprite.setTexture(m_texture);

	m_view.setSize(800, 600);
	m_view.setCenter(400, 300);
}

MouseHandler::~MouseHandler(){


}

bool MouseHandler::getMousePressed(){
	return m_mouse1_was_pressed;
}

void MouseHandler::loadImage(){
	if(!m_texture.loadFromFile("aim.png")){
		//Error
	}
}

sf::IntRect MouseHandler::getTextureRect(){
	return m_textureRect;
}

void MouseHandler::update(sf::RenderWindow &window){
	window.setView(m_view);

	mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window), m_view);

	m_sprite.setPosition(mousePosition.x - m_texture.getSize().x/2, mousePosition.y-m_texture.getSize().y/2);


	// Mouse 1 was pressed
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if(m_m1pressed)
		{
			m_mouse1_was_pressed = false;
		}
		else
		{
			m_mouse1_was_pressed = true;
			m_m1pressed = true;
		}
	}
	else
	{
		m_mouse1_was_pressed = false;
		m_m1pressed = false;
	}


}

void MouseHandler::draw(sf::RenderWindow &window){
	sf::IntRect rect(m_sprite.getPosition().x, m_sprite.getPosition().y, m_texture.getSize().x, m_texture.getSize().y);
	m_textureRect = rect;
	window.draw(m_sprite);
}