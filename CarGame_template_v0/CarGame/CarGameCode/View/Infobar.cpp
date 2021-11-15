#include "Infobar.h"
#include "../Logic/Game.h"

void Infobar::drawInfo() {
    switch (game->state)
    {
    case Game::Menu:
    {
        game->renderText("Welcome to ¡A todo gas!", game->width / 3, game->height / 3);
        game->renderText("Record: (soon!)", game->width / 3, (game->height / 3) + game->font->getSize());
        game->renderText("Press Space to begin", game->width / 3, (game->height / 3) + game->font->getSize() * 2);
        game->renderText("Press Esc at any time to close the game", game->width / 3, (game->height / 3) + game->font->getSize() * 3);

        break;
    }
    case Game::Playing:
    {
        int x = game->font->getSize() / 2;
        int y = game->font->getSize() / 2;
        game->time = (int(SDL_GetTicks()) - game->initTime) / 1000;

        SDL_Rect rect = { 0, 0, game->getWindowWidth(),
                        game->infoSize };
        Box(rect, BLACK).render(game->renderer);

        string s =
            "   Position: " + to_string(int(game->car->getX())) + " " + to_string(int(game->car->getY())) +
            "   Distance: " + to_string(int(game->roadLength - game->car->getX())) +
            "   Velocity: " + to_string(int(game->car->getVelocity())) +
            "   Power: " + to_string(game->power) +
            "   Time: " + to_string(game->time) +
            "   Obstacles: " + to_string(BadObject::instances);
        ;


        game->renderText(s, x, y);

        break;
    }
    case Game::GameOver:
        if (game->goodEnding)
        {
            game->renderText("Congratulations!", game->width / 3, game->height / 3);
            game->renderText("You win!", game->width / 3, (game->height / 3) + game->font->getSize());
            game->renderText("Your time: " + to_string(game->time), game->width / 3, (game->height / 3) + game->font->getSize() * 2);
            if (game->time <= game->record)
            {
                game->record = game->time;
                game->renderText("!!NEW RECORD!!", game->width / 3, (game->height / 3) + game->font->getSize() * 3);
            }
            else
                game->renderText("Press SPACE to play again", game->width / 3, (game->height / 3) + game->font->getSize() * 3);
        }
        else
        {
            game->renderText("Oops :(", game->width / 3, game->height / 3);
            game->renderText("You loose!", game->width / 3, (game->height / 3) + game->font->getSize());
            game->renderText("Your time: " + to_string(game->time), game->width / 3, (game->height / 3) + game->font->getSize() * 2);
            game->renderText("Press SPACE to try again", game->width / 3, (game->height / 3) + game->font->getSize() * 3);
        }
        break;
    default:
        break;
    }
}