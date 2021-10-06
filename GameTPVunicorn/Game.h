#pragma once
#include "SDL.h"
#include "Unicorn.h"

#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
using namespace std;

class Game
{ 
public:

	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	//SDL_Surface* octopus;
	Unicorn* obj1 = nullptr;

	enum { INITIALIZING, KILL, RESULT } state;

	int init();
	void run();
	void clear();

	void showBlack();
	//void showOctopus();

};

