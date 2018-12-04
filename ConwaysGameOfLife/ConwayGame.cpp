#include "ConwayGame.h"

ConwayGame* ConwayGame::_instance = NULL;

ConwayGame::ConwayGame()
{
	
}

ConwayGame::~ConwayGame()
{

}

ConwayGame* ConwayGame::GetInstance()
{
	if (!_instance)
	{
		return _instance = new ConwayGame();
	}
	return _instance;
}

void ConwayGame::Run()
{
	Game::Run(CONWAYSCENE);
}

void ConwayGame::ResourceSetup(SDL_Renderer* sdlrenderer)
{
	TextureManager* textureManager = TextureManager::getInstance();
	textureManager->SetRenderer(sdlrenderer);
	textureManager->AddTexture(BACKGROUND, "Textures\\background.png");
	textureManager->AddTexture(DEFAULTDEAD, "Textures\\defaultDead.png");
	textureManager->AddTexture(DEAD, "Textures\\dead.png");
	textureManager->AddTexture(DEFAULTLIVING, "Textures\\defaultLiving.png");
	textureManager->AddTexture(LIVING, "Textures\\living.png");
	SceneManager* sceneManager = SceneManager::GetInstance();
	sceneManager->AddScene(CONWAYSCENE, new ConwayScene());
}