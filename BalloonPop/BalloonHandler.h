#ifndef INCLUDED_BALLOONHANDLER
#define INCLUDED_BALLOONHANDLER

#include "Balloon.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

const int columns = 8;
const int rows = 6;

class BalloonHandler{
public:
	BalloonHandler();
	~BalloonHandler();
	void addBalloon(Balloon *ballon);
	void drawBalloons(sf::RenderWindow &window);
	typedef std::vector<Balloon*>BalloonVector;
	void collision(sf::IntRect &rect);
	bool isDead();
	void removeBalloon();
	void update(sf::RenderWindow &window);
	void loadBalloons();
	void createBalloons();
	void timeExpired();
	// Sort Container by age function
	void orderBalloons();

private:
	std::ifstream m_mapFile;
	void moveBalloon();
	BalloonVector m_balloons;
	sf::Clock m_clock;
	bool m_time;

	typedef int m_mapArray[rows][columns];
	m_mapArray maps;
};

#endif