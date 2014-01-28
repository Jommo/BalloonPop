#include "GameManager.h"
#include "BalloonHandler.h"
#include "MouseHandler.h"
#include "ButtonMenu.h"
#include "GameState.h"
#include <iostream>
#include <sstream>


int main()
{
    GameManager gameManager;
	BalloonHandler balloonHandler;
	balloonHandler.createBalloons();

	GameState::GameStates state;
	state = GameState::menu;

	ButtonMenu buttonMenu(sf::Vector2f(gameManager.getWindow().getSize().x/2-250, 150));
	buttonMenu.addButton(new Button("Start", GameState::running));
	buttonMenu.addButton(new Button("Tutorial", GameState::tutorial));
	buttonMenu.addButton(new Button("High Score", GameState::menu));
	buttonMenu.addButton(new Button("Exit", GameState::exit));


	MouseHandler mouseHandler(gameManager.getWindow());

    while (gameManager.getWindow().isOpen())
    {
        sf::Event event;
        while (gameManager.getWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameManager.getWindow().close();
        }

        gameManager.getWindow().clear();

		switch(state){
		case GameState::running:
			balloonHandler.update(gameManager.getWindow());
			if(mouseHandler.getMousePressed()){
				balloonHandler.collision(mouseHandler.getTextureRect());
			}
			break;
		case GameState::pause:

			break;

		case GameState::menu:
			buttonMenu.draw(gameManager.getWindow());
			buttonMenu.mouseOver(mouseHandler.getTextureRect());
			if(mouseHandler.getMousePressed()){
				buttonMenu.onClickListener(state, mouseHandler.getTextureRect());
			}
			break;
		case GameState::tutorial:

			break;
		}

		mouseHandler.update(gameManager.getWindow());

		mouseHandler.draw(gameManager.getWindow());

        gameManager.getWindow().display();
    }

    return 0;
}