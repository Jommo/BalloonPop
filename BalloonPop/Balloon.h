#ifndef INCLUDED_BALLOON
#define INCLUDED_BALLOON

#include <SFML\Graphics.hpp>

class Balloon{
public:
	Balloon(int id, int x, int y, int wait, int expiredTime);
	~Balloon();
	void createBalloon();
	void drawBalloon(sf::RenderWindow &window);
	sf::IntRect getTextureRect();
	void setDead();
	bool isDead();
	void moveBalloon();
	void setWaitTime(int nr);
	int getWait();
	int getExpiredTime();
	int getId();
	
private:
	void loadImage();
	void setSprite();
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	bool isAlive;
	sf::IntRect m_textureRect;
	float xPos;
	float yPos;
	float m_speed;
	int m_wait;
	int m_expiredTime;
	int m_id;
};

#endif