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

    octopus = SDL_LoadBMP("octopus.bmp");


    if (octopus == nullptr) {
        cout << "could not load file" << endl;
        return -1;
    }

    unsigned int seed = time(NULL);
    srand(seed);

    return 0;

}
void Game::showBlack()
{
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
    SDL_UpdateWindowSurface(window);
}

void Game::showOctopus()
{
    int x = rand() % (screenSurface->w - octopus->w);
    int y = rand() % (screenSurface->h - octopus->h);

    SDL_Rect r = { x, y, octopus->w, octopus->h };
    SDL_BlitSurface(octopus, NULL, screenSurface, &r);

    SDL_UpdateWindowSurface(window);
}

void Game::run()
{
    state = INITIALIZING;

    bool bQuit = false;;
    bool bSpace = false;
    int waitingTime;
    unsigned int t0;
    unsigned int reactionTime;

    unsigned int record = INT_MAX;

    while (!bQuit) {

        switch (state)
        {
        case Game::INITIALIZING:
            showBlack();
            waitingTime = (rand() % 5000) + 1000;
            t0 = SDL_GetTicks();
            cout << "Waiting time: " << waitingTime << endl;
            state = WAITING;
            break;
        case Game::WAITING:
            if (bSpace) {
                state = INITIALIZING;
                bSpace = false;
                cout << "Too early mother fucker" << endl;
            }
            if (SDL_GetTicks() > t0 + waitingTime) {

                state = READY;
                showOctopus();
            }
            break;
        case Game::READY:
            if (bSpace) {
                state = INITIALIZING;
                bSpace = false;
                reactionTime = SDL_GetTicks() - (t0 + waitingTime);
                cout << "Your reaction time is: " << reactionTime << endl;
                if (reactionTime < record) {
                    cout << "New record!" << endl;
                    record = reactionTime;
                }
            }
            break;
        default:
            break;
        }

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                   bQuit = true;
            }
            if (event.type == SDL_KEYDOWN) {
                SDL_Keycode key = event.key.keysym.sym;
                if (key == SDLK_SPACE) {
                    bSpace = true;
                }
            }
        }

        SDL_Delay(30);

    }
 
 
}

void Game::clear()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

