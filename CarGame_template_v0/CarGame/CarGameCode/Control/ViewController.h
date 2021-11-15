//
// Created by eys on 20/8/21.
//

#ifndef CARGAME_VIEWCONTROLLER_H
#define CARGAME_VIEWCONTROLLER_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "CommandFactory.h"

#include "../Logic/Game.h"

const int FRAME_RATE = 30;

class ViewController {
private:
    Game *game;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    CommandFactory* commandFactory;
    Infobar *info = nullptr;

    void initSDL();
public:
    ViewController(Game *game);

    ~ViewController();

    void run();
    void handleEvents();
    void clearBackground();

    unsigned int frameDuration();
};


#endif //CARGAME_VIEWCONTROLLER_H
