#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

#ifndef Game_hpp
#define Game_hpp
#endif

class Game {
	
public:
	Game();
	~Game();

	// initializes the game.
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscree);
	
	// handle inputs etc
	void handleEvents();

	// updates everything
	void update();

	// render everything
	void render();

	// clean up the game when we're done.
	void clean();
	bool running();

	// tell if the game is still running

private:
	bool isRunning = false;
	SDL_Window *window;
	SDL_Renderer *renderer;
};