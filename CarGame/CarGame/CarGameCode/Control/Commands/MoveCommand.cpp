#include "MoveCommand.h"
#include "../../Logic/Game.h"

bool MoveCommand::parse(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
        bool v = (event.type == SDL_KEYDOWN);
        SDL_Keycode key = event.key.keysym.sym;
        switch (key) {
        case SDLK_UP:
        case SDLK_w:
            bUp = v;
            return true;
            break;
        case SDLK_DOWN:
        case SDLK_s:
            bDown = v;
            return true;
            break;
        case SDLK_RIGHT:
        case SDLK_d:
            bForward = v;
            return true;
            break;
        case SDLK_LEFT:
        case SDLK_a:
            bBackward = v;
            return true;
            break;
        default:
            break;
        }
    }
    return false;
}

void MoveCommand::execute() {
    if (bUp && !bDown)
        game->setMovement(8);
    else if (bDown && !bUp)
        game->setMovement(2);
    else if (bForward && !bBackward)
        game->setMovement(6);
    else if (bBackward && !bForward)
        game->setMovement(4);
    else
        game->setMovement(0);
}