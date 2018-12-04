#include "ConwayCell.h"

ConwayCell::ConwayCell(bool alive) : Sprite(alive ? TextureManager::getInstance()->GetTexture(DEFAULTLIVING) : TextureManager::getInstance()->GetTexture(DEFAULTDEAD))
{
	_currentState = alive;
	_alive = TextureManager::getInstance()->GetTexture(LIVING);
	_dead = TextureManager::getInstance()->GetTexture(DEAD);
}

ConwayCell::~ConwayCell()
{

}

void ConwayCell::SpawnLife()
{
	SetTexture(_alive);
}

void ConwayCell::Kill()
{
	SetTexture(_dead);
}

void ConwayCell::Update()
{
	int livingNeighbours = 0;
	for (int i = 0; i < neighbours.size(); i++)
	{
		if (neighbours[i]->GetPrevState())
		{
			livingNeighbours++;
		}
	}
	if ((livingNeighbours < 2 || livingNeighbours > 3) && _currentState)
	{
		//std::cout << "killed" << std::endl;
		_currentState = false;
		Kill();
	}
	else if (livingNeighbours == 3 && !_currentState)
	{
		_currentState = true;
		SpawnLife();
	}
}

bool ConwayCell::GetPrevState()
{
	return _prevState;
}

void ConwayCell::SetPrevState()
{
	_prevState = _currentState;
}

bool ConwayCell::GetCurrentState()
{
	return _currentState;
}

void ConwayCell::SetCurrentState(bool _state)
{
	if (_currentState != _state)
	{
		_currentState = _state;
		if (_currentState)
		{
			SpawnLife();
		}
		else
		{
			Kill();
		}
	}
}

void ConwayCell::AddNeighbour(ConwayCell* neighbour)
{
	neighbours.push_back(neighbour);
}