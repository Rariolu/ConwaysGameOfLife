#include "ConwayGame.h"
#include "SDL_Window_Manager.h"

#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#define WINDOW_TITLE "Conway's Game of Life"

ConwayGame* conwayGame = ConwayGame::GetInstance();

SDL_Window_Manager* sdlWindowManager = SDL_Window_Manager::getInstance();

int main(int argc, char *argv[])
{
	//Attempt to initialise an SDL window.
	if (!sdlWindowManager->initWND(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT))
	{
		//End the program if the window cannot be initialised.
		return -1;
	}
	//A pointer to the sdl renderer from the sdl window.
	SDL_Renderer* renderer = sdlWindowManager->getSDLRenderer();
	conwayGame->ResourceSetup(renderer);
	conwayGame->Initialise(sdlWindowManager->getSDLWindow(), renderer);
	conwayGame->Run();
	conwayGame->Dispose();
	return 0;
}