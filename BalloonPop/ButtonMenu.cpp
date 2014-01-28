#include "ButtonMenu.h"

ButtonMenu::ButtonMenu(sf::Vector2f pos) : mPos(pos){
	setPosition();
	setSize();
	mShape.setFillColor(sf::Color::White);
	mShape.setPosition(mPos);
}

ButtonMenu::~ButtonMenu(){
	while(!m_buttons.empty()){
		delete m_buttons.back();
		m_buttons.pop_back();
	}
}

void ButtonMenu::addButton(Button* button){
	m_buttons.push_back(button);
	update();
}

void ButtonMenu::draw(sf::RenderWindow &window){
	window.draw(mShape);
	for(int i = 0; i < m_buttons.size(); i++){
		m_buttons[i]->draw(window);
	}
}

void ButtonMenu::mouseOver(sf::IntRect rect){

	for(int i = 0; i < m_buttons.size(); i++){
		if(rect.intersects(m_buttons[i]->getButtonRect())){
			m_buttons[i]->setColor(sf::Color::Magenta);
		}else{
			m_buttons[i]->setColor(sf::Color::Blue);
		}
	}
}

void ButtonMenu::onClickListener(GameState::GameStates &state, sf::IntRect rect){
	for(int i = 0; i < m_buttons.size(); i++){
		if(rect.intersects(m_buttons[i]->getButtonRect())){
			state = m_buttons[i]->getGameState();
		}else{
			m_buttons[i]->setColor(sf::Color::Blue);
		}
	}
}

void ButtonMenu::update(){
	for(int i = 0; i < m_buttons.size(); i++){
		m_buttons[i]->setPosition(mPos.x + mShape.getSize().x/4, mPos.y + (i * 70) +10 );
	}
}

void ButtonMenu::setPosition(){
	mShape.setPosition(mPos);
}

void ButtonMenu::setSize(){
	mShape.setSize(sf::Vector2f(500, 300));
}
