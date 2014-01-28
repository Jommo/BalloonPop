#include "Balloon.h"

Balloon::Balloon(int id, int x, int y, int wait, int expiredTime) : isAlive(true), xPos(x), yPos(y), m_wait(wait), m_expiredTime(expiredTime), m_id(id){
	loadImage();
	setSprite();
	m_sprite.setPosition(xPos, yPos);
}

Balloon::~Balloon(){

}

int Balloon::getWait(){
	return m_wait;
}

int Balloon::getExpiredTime(){
	return m_expiredTime;
}

void Balloon::loadImage(){

	if(!m_texture.loadFromFile("balloon.png")){
		//Error
	}
}

void Balloon::setSprite(){
	m_sprite.setTexture(m_texture);
}

void Balloon::drawBalloon(sf::RenderWindow& window){
	sf::IntRect rect(m_sprite.getPosition().x, m_sprite.getPosition().y, m_texture.getSize().x, m_texture.getSize().y);
	m_textureRect = rect;
	window.draw(m_sprite);
}

void Balloon::moveBalloon(){
	m_sprite.move(0, m_speed);
}


sf::IntRect Balloon::getTextureRect(){
	return m_textureRect;
}

void Balloon::setDead(){
	isAlive = false;
}

bool Balloon::isDead(){
	return isAlive;
}

int Balloon::getId(){
	return m_id;
}

void Balloon::setWaitTime(int nr){
	m_wait = nr;
}

