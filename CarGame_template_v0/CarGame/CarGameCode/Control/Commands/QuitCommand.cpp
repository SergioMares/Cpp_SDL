#include "QuitCommand.h"
#include "../../Logic/Game.h"

bool QuitCommand::parse(SDL_Event &event) {
    if( event.type == SDL_QUIT)
        return true;
    if(event.type == SDL_KEYDOWN){
        SDL_Keycode key = event.key.keysym.sym;
        if(key == SDLK_ESCAPE)
            return true;
    }
    return false;
}

void QuitCommand::execute() {
    game->setUserExit();
}
