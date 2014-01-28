#include "BalloonHandler.h"
#include <algorithm>

BalloonHandler::BalloonHandler() : m_balloons(){
	loadBalloons();
}

BalloonHandler::~BalloonHandler(){

}

void BalloonHandler::addBalloon(Balloon *balloon){
	m_balloons.push_back(balloon);
}

void BalloonHandler::update(sf::RenderWindow &window){
	
	drawBalloons(window);
	//moveBalloon();
	timeExpired();
	removeBalloon();

}

void BalloonHandler::drawBalloons(sf::RenderWindow &window){
	for(int i = 0; i < m_balloons.size(); i++){
		if(m_balloons[i]->getWait() <= m_clock.getElapsedTime().asSeconds()){
			m_balloons[i]->drawBalloon(window);
		}
	}
}

void BalloonHandler::moveBalloon(){
	for(unsigned int i = 0; i < m_balloons.size(); i++){
		if(m_balloons[i]->getWait() <= m_clock.getElapsedTime().asSeconds()){
			m_balloons[i]-> moveBalloon();
		}
	}
}

void BalloonHandler::collision(sf::IntRect &rect){
	for(int i = 0; i < m_balloons.size(); i++){
		if(m_balloons[i]->getTextureRect().intersects(rect)){
			m_balloons[i]->setDead();
		}
	}
}

void BalloonHandler::timeExpired(){
	for(int i = 0; i < m_balloons.size(); i++){
		if(m_balloons[i]->getExpiredTime() <= m_clock.getElapsedTime().asSeconds()){
			m_balloons[i]->setDead();
		}
	}
}

void BalloonHandler::removeBalloon(){

	BalloonVector balloons;

	for(BalloonVector::iterator i = m_balloons.begin(); i != m_balloons.end(); i++){
		if(!(*i)->isDead())
		{
			delete (*i);
		}
		else
		{
			balloons.push_back(*i);
		}
	}
	m_balloons = balloons;
}

void BalloonHandler::loadBalloons(){

		//Loads and opens a text file
	m_mapFile.open("map.txt");

	int posX = 0;
	int posY = 0;
	int speed;
	int type = 0;
	int nr = 0;

	while(m_mapFile.good())
	{
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < columns; j++){
				m_mapFile >> maps[i][j];
				
			}
		}
	}
	m_mapFile.close();

}

void BalloonHandler::createBalloons(){
	int xPos = 0;
	int yPos = 0;
	int id = 0;
	for(int i = 0; i < rows; i++){
		xPos = 0;
		for(int j = 0; j < columns; j++){
			if(maps[i][j] == 1){
				id = maps[i][j];
				m_balloons.push_back(new Balloon(id, xPos, yPos, 5, 10));
			}else if(maps[i][j] == 2){
				id = maps[i][j];
				m_balloons.push_back(new Balloon(id, xPos, yPos, 10, 15));
			}else if(maps[i][j] == 3){
				id = maps[i][j];
				m_balloons.push_back(new Balloon(id, xPos, yPos, 15, 20));
			}else if(maps[i][j] == 4){
				id = maps[i][j];
				m_balloons.push_back(new Balloon(id, xPos, yPos, 20, 25));
			}else if(maps[i][j] == 5){
				id = maps[i][j];
				m_balloons.push_back(new Balloon(id, xPos, yPos, 25, 30));
			}else if(maps[i][j] == 6){
				id = maps[i][j];
				m_balloons.push_back(new Balloon(id, xPos, yPos, 30, 35));
			}else if(maps[i][j] == 7){
				id = maps[i][j];
				m_balloons.push_back(new Balloon(id, xPos, yPos, 35, 40));
			}else if(maps[i][j] == 8){
				id = maps[i][j];
				m_balloons.push_back(new Balloon(id, xPos, yPos, 40, 45));
			}else if(maps[i][j] == 9){
				id = maps[i][j];
				m_balloons.push_back(new Balloon(id, xPos, yPos, 45, 50));
			}
			std::cout << maps[i][j];
			xPos += 100;
		}
		yPos += 100;
		std::cout << std::endl;
	}
	orderBalloons();
}

bool sortById(Balloon *lballoon, Balloon *rballoon) {
	return lballoon->getId() < rballoon->getId();
}

void BalloonHandler::orderBalloons(){
	std::sort(m_balloons.begin(), m_balloons.end(), sortById);
}