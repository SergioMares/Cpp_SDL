#pragma once
#include "SDL.h"

#include <iostream>
#include <string>

using namespace std;

class Unicorn
{
	SDL_Surface* image = nullptr;
	int x, y;
	//SDL_Rect position;
public:
	SDL_Rect position;
	bool alive;
	bool loadMedia(string filename);
	void setRandomPos(int W, int H);
	void draw(SDL_Surface* surface);
	void clear();
	void click(int x, int y);

};

