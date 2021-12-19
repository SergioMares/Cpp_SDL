#include "CheatCommand.h"

bool CheatCommand::parse(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN) {
        SDL_Keycode key = event.key.keysym.sym;
        id = 0;
        if (key == SDLK_1) id = 1;
        if (key == SDLK_2) id = 2;
        if (key == SDLK_3) id = 3;
        if (key == SDLK_4) id = 4;
        if (key == SDLK_5) id = 5;
        if (key == SDLK_6) id = 6;
        if (key == SDLK_7) id = 7;
        if (key == SDLK_8) id = 8;
        if (key == SDLK_9) id = 9;
        if (id != 0)
            return true;
    }
    return false;
}

void CheatCommand::execute()
{
    GameObjectGenerator::forceAddObject(game, id);
}
