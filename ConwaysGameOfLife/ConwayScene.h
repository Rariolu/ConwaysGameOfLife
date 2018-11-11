#ifndef _CONWAY_SCENE_H
#define _CONWAY_SCENE_H

#include "Scene.h"
#include "ConwayCell.h"
#include "CSRand.h"

class ConwayScene : public Scene
{
	public:
		ConwayScene();
		~ConwayScene();
		void Initialise(SDL_Renderer* sdlrenderer);
	private:
		bool GetInput();
		void Update(float deltaTime);
		void SetPrevState();
		ConwayCell* cells[ArrayWidth][ArrayHeight];
		float aggregateDelta = 0;
		CSRand* rand = new CSRand();
};

#endif