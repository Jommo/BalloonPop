#include "Button.h"


Button::Button(std::string name, GameState::GameStates state) : mName(name), mState(state){
	onCreate();
	mShape.setFillColor(sf::Color::Blue);
	mShape.setSize(sf::Vector2f(200, 50));
	mShape.setOutlineThickness(5);
	mText.setString(mName);
}

Button::~Button(){

}

GameState::GameStates Button::getGameState(){
	return mState;
}

void Button::onCreate(){
	mFont.loadFromFile("wendy.ttf");
	mText.setFont(mFont);
	mText.setCharacterSize(50);
	mText.setColor(sf::Color::Black);
}

void Button::setColor(sf::Color color){
	mShape.setOutlineColor(color);
}

void Button::setPosition(float x, float y){
	mShape.setPosition(x, y);
	mText.setPosition(x, y);
	setRect();
}

void Button::setRect(){
	sf::IntRect rect(mShape.getPosition().x, mShape.getPosition().y, mShape.getSize().x, mShape.getSize().y);
	mShape.setTextureRect(rect);
}

sf::IntRect Button::getButtonRect(){
	return mShape.getTextureRect();
}


void Button::update(){
}


void Button::draw(sf::RenderWindow& window){
	window.draw(mShape);
	window.draw(mText);
}

