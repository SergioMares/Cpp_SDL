#include "WaveCommand.h"
#include "../../Logic/Game.h"

bool WaveCommand::parse(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
        bool v = (event.type == SDL_KEYDOWN);
        SDL_Keycode key = event.key.keysym.sym;
        switch (key) {
        case SDLK_q:
            bWave = v;
            return true;
            break;
        }
    }
    return false;
}

void WaveCommand::execute()
{
    if (bWave)
    {
        if (game->getCoins() > 2)
        {
            for (auto colls : game->getCollisions())
                colls->wave();

            game->modCoins(-3);
        }
    }
}
