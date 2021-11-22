#include "QuitStartCommand.h"
#include "../../Logic/Game.h"

bool QuitStartCommand::parse(SDL_Event &event) {
    if (event.type == SDL_QUIT)
    {
        bEnd = true;
        return true;
    }        
    if(event.type == SDL_KEYDOWN){
        SDL_Keycode key = event.key.keysym.sym;
        if (key == SDLK_ESCAPE)
        {
            bEnd = true;
            return true;
        }
        else if (key == SDLK_SPACE)
        {
            bStart = true;
            return true;
        }
    }
    return false;
}

void QuitStartCommand::execute() {
    if (bStart)
    {        
        if (game->state != game->Playing)
        {
            game->startGame();
            game->state = game->Playing;            
        }
    }
    if (bEnd)
        game->setUserExit();
}
