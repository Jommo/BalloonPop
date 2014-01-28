#include "GameManager.h"
#include "MouseHandler.h"


GameManager::GameManager(){
	m_window.create(sf::VideoMode(800, 600), "My Window");
	m_window.setFramerateLimit(60);
	m_window.setMouseCursorVisible(false);

}

GameManager::~GameManager(){
	//Destructor
}

sf::RenderWindow &GameManager::getWindow(){
	return m_window;
}

void GameManager::drawInfo(){

}