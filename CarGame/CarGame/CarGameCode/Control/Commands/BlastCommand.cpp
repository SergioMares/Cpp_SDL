#include "BlastCommand.h"
#include "../../Logic/Game.h"

bool BlastCommand::parse(SDL_Event& event)
{
    if (event.type == SDL_MOUSEBUTTONDOWN) {       
        SDL_GetMouseState(&x, &y);
        //obj1->click(x, y);
        return true;
        //cout << "posXi: " << x << endl;
        //cout << "posYi: " << y << endl;
    }

    return false;
}

void BlastCommand::execute()
{
    fixedX = x + (game->getOrigin().getX() * -1);
    if (game->getCoins() > 2)
    {
        for (Collider* c : game->getCollisions(fixedX,y,range))
            c->blast();

        game->modCoins(-3);
    }

    /*if (game->getCoins() > 2) {
        for (Collider* c : game->getCollisions(x, y, RANGE))
            c->blast();
    }*/
}

/*if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                obj1->click(x, y);
                

                //cout << "posXi: " << x << endl;
                //cout << "posYi: " << y << endl;

            }*/

/*if (x >= position.x &&
        x < (position.x + image->w) &&
        y >= position.y &&
        y < (position.y + image->h))
    {
        cout << "nice cock!" << endl;
        SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
    }*/