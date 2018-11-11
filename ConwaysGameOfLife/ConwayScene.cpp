#include "ConwayScene.h"



ConwayScene::ConwayScene() : Scene(BACKGROUND)
{

}


ConwayScene::~ConwayScene()
{

}

void ConwayScene::Initialise(SDL_Renderer* sdlrenderer)
{
	Scene::Initialise(sdlrenderer);
	for (int x = 0; x < ArrayWidth; x++)
	{
		for (int y = 0; y < ArrayHeight; y++)
		{
			cells[x][y] = new ConwayCell();
			cells[x][y]->SetPosition(x * 20, y * 20);
			cells[x][y]->SetCurrentState(rand->NextDouble() < 0.25);
			cells[x][y]->SetActive(true);
			AddSprite(cells[x][y], 10);
		}
	}
	for (int x = 0; x < ArrayWidth; x++)
	{
		for (int y = 0; y < ArrayHeight; y++)
		{
			std::vector<ConwayCell*> n;
			n.push_back(x > 0 ? cells[x - 1][y] : 0);
			n.push_back(x > 0 && y > 0 ? cells[x - 1][y - 1] : 0);
			n.push_back(x > 0 && y < ArrayHeight - 1 ? cells[x - 1][y + 1] : 0);
			n.push_back(y > 0 ? cells[x][y - 1] : 0);
			n.push_back(y < ArrayHeight - 1 ? cells[x][y + 1] : 0);
			n.push_back(x < ArrayWidth - 1 ? cells[x + 1][y] : 0);
			n.push_back(x < ArrayWidth - 1 && y > 0 ? cells[x + 1][y - 1] : 0);
			n.push_back(x < ArrayWidth - 1 && y < ArrayHeight - 1 ? cells[x + 1][y + 1] : 0);
			for (int i = 0; i < 8; i++)
			{
				if (n[i])
				{
					cells[x][y]->AddNeighbour(n[i]);
				}
			}
		}
	}
}

bool ConwayScene::GetInput()
{
	SDL_Event event;
	SDL_Point mpos;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return false;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						return false;
				}
			default:
				break;
		}
	}
	return true;
}

void ConwayScene::Update(float deltaTime)
{
	aggregateDelta += deltaTime;
	if (aggregateDelta >= INTERVAL)
	{
		aggregateDelta = 0;
		SetPrevState();
		for (int x = 0; x < ArrayWidth; x++)
		{
			for (int y = 0; y < ArrayHeight; y++)
			{
				cells[x][y]->Update();
			}
		}
	}
	else
	{
		//std::cout << aggregateDelta << std::endl;
	}
}


void ConwayScene::SetPrevState()
{
	for (int x = 0; x < ArrayWidth; x++)
	{
		for (int y = 0; y < ArrayHeight; y++)
		{
			cells[x][y]->SetPrevState();
		}
	}
}