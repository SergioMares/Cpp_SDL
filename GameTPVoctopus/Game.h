#pragma once
#include "SDL.h"

#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
using namespace std;

class Game
{ 
public:

	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Surface* octopus;
	enum { INITIALIZING, WAITING, READY, RESULT } state;

	int init();
	void run();
	void clear();

	void showBlack();
	void showOctopus();

};

