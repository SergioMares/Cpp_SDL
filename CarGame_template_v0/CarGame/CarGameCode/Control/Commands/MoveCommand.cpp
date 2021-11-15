#include "MoveCommand.h"
#include "../../Logic/Game.h"

bool MoveCommand::parse(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
        bool v = (event.type == SDL_KEYDOWN);
        SDL_Keycode key = event.key.keysym.sym;
        switch (key) {
        case SDLK_UP:
            bUp = v;
            return true;
        case SDLK_w:
            bUp = v;
            return true;
        case SDLK_DOWN:
            bDown = v;
            return true;
        case SDLK_s:
            bDown = v;
            return true;
        case SDLK_RIGHT:
            bForward = v;
            return true;
        case SDLK_d:
            bForward = v;
            return true;
        case SDLK_LEFT:
            bBackward = v;
            return true;
        case SDLK_a:
            bBackward = v;
            return true;
        default:
            break;
        }
    }
    return false;
}

void MoveCommand::execute() {
    if (bUp)
        game->setMovement(8);
    else if (bDown)
        game->setMovement(2);
    else if (bForward)
        game->setMovement(6);
    else if (bBackward)
        game->setMovement(4);
    else
        game->setMovement(0);
}