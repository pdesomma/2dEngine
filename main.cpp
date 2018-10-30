#include "Game.hpp"
#undef main; // do this to make it run

Game *game = nullptr;
const int FPS = 60;
const int frameDelay = 1000 / FPS;

void throttleFPS(Uint32 frameStart)
{
	int frameTime = SDL_GetTicks() - frameStart;
	if (frameDelay > frameTime)
	{
		SDL_Delay(frameDelay - frameTime);
	}
}

int main(int argc, const char *argv[])
{
	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("new game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		throttleFPS(frameStart);
	}

	game->clean();

	return 0;
}