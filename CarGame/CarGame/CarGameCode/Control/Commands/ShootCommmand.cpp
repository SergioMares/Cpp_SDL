#include "ShootCommmand.h"
#include "../../Logic/Game.h"

bool ShootCommmand::parse(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
        bool v = (event.type == SDL_KEYDOWN);
        SDL_Keycode key = event.key.keysym.sym;
        switch (key) {
        case SDLK_e:
            bShoot = v;
            return true;
            break;
        }
    }
    return false;
}

void ShootCommmand::execute()
{
    if (bShoot)
    {
        if (game->getCoins() > 0)
        {
            puts("shoot a bullet");
            //game->spawnBullet();
            Bullet *bullet = new Bullet(game);
            bullet->setPosition(game->getCarX(), game->getCarY());
            
            game->getContainer()->add(bullet);
            game->modCoins(-1);
        }        
    }
}
