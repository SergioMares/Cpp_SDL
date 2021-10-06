
#include "SDL.h"
//#include "SDL_image.h"
//#include "SDL_ttf.h"
#include <iostream>
#include "Game.h"

using namespace std;



int main(int argc, char* argv[]){

	Game g = Game();

	if (g.init() == -1)
		exit(-1);

	g.run();
	g.clear();


	return 0;
}



