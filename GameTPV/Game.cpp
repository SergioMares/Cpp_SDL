#include "Game.h"

int Game::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "could not initialize sdl2: " << SDL_GetError() << endl;
        return -1;
    }
    window = SDL_CreateWindow(
        "octopus killer 1.0",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr) {
        cout << "could not create window: " << SDL_GetError() << endl;
        return -1;
    }
    screenSurface = SDL_GetWindowSurface(window);

    octopus = SDL_LoadBMP("../images/octopus.bmp");


    if (octopus == nullptr) {
        cout << "could not load file" << endl;
        return -1;
    }

    return 0;

}

void Game::run()
{
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {

        int x = rand() % SCREEN_WIDTH;
        int y = rand() % SCREEN_HEIGHT;

        SDL_Rect r = { x, y, 80, 80 };
        SDL_BlitSurface(octopus, NULL, screenSurface, &r);

        SDL_UpdateWindowSurface(window);
        SDL_Delay(30);
    }

    SDL_Event event;
    while (true) {
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT)
            break;
    }
}

void Game::clear()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

