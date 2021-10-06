#include "Unicorn.h"


bool alive;

bool Unicorn::loadMedia(string filename)
{    
    image = SDL_LoadBMP(filename.c_str());
    if (image == nullptr) {
        cout << "could not load file" << endl;
        return -1;
    }

    return false;
}

void Unicorn::setRandomPos(int W, int H)
{
    x = rand() % (W - image->w);
    y = rand() % (H - image->h);

    position = { x, y, image->w, image->h };    
}

void Unicorn::draw(SDL_Surface* surface)
{
    SDL_BlitSurface(image, NULL, surface, &position);


    //SDL_UpdateWindowSurface(window);
}

//Qué pretende esta wea? no sería mejor el deconstrucot? el ~
void Unicorn::clear()
{

}

void Unicorn::click(int x, int y)
{
    if (x >= position.x &&
        x < (position.x + image->w) &&
        y >= position.y &&
        y < (position.y + image->h))
    {
        cout << "nice cock!" << endl;
        SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
    }
        
        
    //if (y >= position.y && y < (position.y + image->h))
        
}

/*
octopus = SDL_LoadBMP("unicorn.bmp");
if (octopus == nullptr) {
    cout << "could not load file" << endl;
    return -1;
}*/


/*
void Game::showOctopus()
{
    int x = rand() % (screenSurface->w - octopus->w);
    int y = rand() % (screenSurface->h - octopus->h);

    SDL_Rect r = { x, y, octopus->w, octopus->h };
    SDL_BlitSurface(octopus, NULL, screenSurface, &r);

    SDL_UpdateWindowSurface(window);
}
*/



/*
if (event.type == SDL_MOUSEBUTTONDOWN){
int x, y;
SDL_GetMouseState( &x, &y );
// TODO handle mouse event
}
*/