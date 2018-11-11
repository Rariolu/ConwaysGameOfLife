#ifndef _CONWAY_GAME_H
#define _CONWAY_GAME_H

#include "Game.h"
#include "ConwayScene.h"
#include"Constants.h"

class ConwayGame : public Game
{
	public:
		static ConwayGame* GetInstance();
		~ConwayGame();
		void Run();
		void ResourceSetup(SDL_Renderer* sdlrenderer);
	private:
		ConwayGame();
		static ConwayGame* _instance;
};

#endif