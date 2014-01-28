#ifndef INCLUDED_GAMESTATE
#define INCLUDED_GAMESTATE

class GameState{
public:
	typedef enum GameStates{running, pause, menu, tutorial, exit};
	GameStates mStates;
};

#endif