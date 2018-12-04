#ifndef _CONWAY_CELL_H
#define _CONWAY_CELL_H

#include "Sprite.h"
#include "Constants.h"

class ConwayCell : public Sprite
{
	public:
		ConwayCell();
		~ConwayCell();
		void Update();
		bool GetPrevState();
		void SetPrevState();
		bool GetCurrentState();
		void SetCurrentState(bool _state);
		void AddNeighbour(ConwayCell* neighbour);
	private:
		bool _prevState;
		bool _currentState = true;
		void SpawnLife();
		void Kill();
		std::vector<ConwayCell*> neighbours;
		Texture* _dead;
		Texture* _alive;
};

#endif