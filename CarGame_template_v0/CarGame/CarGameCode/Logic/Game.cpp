//
// Created by eys on 20/8/21.
//

#include "Game.h"

Game::Game(string name, int width, int height, int roadLength) {
    this->name = name;
    this->roadLength = roadLength;
    this->width = width;
    this->height = height;
    
    font = new Font("../Images/Monospace.ttf", 12);
    infoSize = int(font->getSize() * 1.8);


    doExit = false;       
    bMoveBackward = false;
    bMoveUp = false;
    bMoveDown = false;
    bMoveForward = false;    
}

void Game::startGame() {
    //later work: create vector<> of game objects
    //            çheck memory leaks here

    car = new Car(this);
    car->setDimension(CAR_WIDTH, CAR_HEIGHT);
    car->setPosition(car->getWidth(), height/ 2.0);

    for (size_t i = 0; i < OBSTACLES; i++)
    {        
        rocks.push_back(new Rock(this));
    }
       
    for (auto a : rocks) 
    {        
        unsigned int tempoSize = rand() % ROCK_SIZE + ROCK_RANGE;
        a->setDimension(tempoSize, tempoSize);

        unsigned int tempoPosX = rand() % roadLength + (ROCK_SIZE + CAR_WIDTH);
        unsigned int tempoPosY = rand() % (height-ROCK_SIZE) + infoSize;

        a->setPosition(tempoPosX, tempoPosY);
    }

    for (size_t i = 0; i < OBSTACLES; i++)
    {
        if (rocks[i] != nullptr)
        {
            for (size_t j = 0; j < OBSTACLES; j++)
            {
                if (i != j)
                {
                    if (rocks[j] != nullptr)
                    {
                        if (Collisions(rocks[i]->getCollider(), rocks[j]->getCollider()))
                        {
                            rocks[j] = nullptr;
                            puts("colision");
                            //break;
                        }
                    }                    
                }                
            }            
        }
    }
}

string Game::getGameName() {
    return name;
}

Game::~Game() {
    cout << "[DEBUG] deleting game" << endl;
}

void Game::update()
{
    //car movement Y axis
    if (bMoveUp && !(car->getY() <= car->getHeight()))
        car->moveCar(0, 1);
    else if (bMoveDown && !(car->getY() >= height - CAR_HEIGHT / 2))
        car->moveCar(0, -1);
    //car movement X axis
    if (bMoveForward)
        car->moveCar(1, 0);
    else if (bMoveBackward)
        car->moveCar(-1, 0);

    //check collisions

    for (size_t i = 0; i < OBSTACLES; i++)
    {
        if (rocks[i] != nullptr)
        {
            if (Collisions(car->getCollider(), rocks[i]->getCollider()))
            {
                rocks[i] = nullptr;

                car->setVelocity(0);
                car->setPower(-1);
            }
        }
    }

    //check if objects out of the window
    for (auto a : rocks)
    {
        
    }

    for (size_t i = 0; i < OBSTACLES; i++)
    {
        if (rocks[i] != nullptr)
        {
            if (rocks[i]->getX() < 0)
                rocks[i] = nullptr;            
        }
    }
      
    //update GameObjects    
    car->update();
    for (auto a : rocks)
    {
        if (a != nullptr)
            a->update();
    }        
}

//call everything that has to be rendered
void Game::draw()
{
    car->draw();
    for (auto a : rocks)
    {
        if (a != nullptr)
            a->draw();
    }
    drawInfo();
}

//bool movement control
void Game::setMovement(int _direction)
{
    switch (_direction)
    {
    case 8:        
        bMoveUp = true;        
        break;

    case 2:
        bMoveDown = true;
        break;

    case 4:
        bMoveBackward = true;
        break;

    case 6:
        bMoveForward = true;
        break;

    case 0:        
        bMoveUp = false;
        bMoveDown = false;
        bMoveForward = false;
        bMoveBackward = false;

    default:
        break;
    }
}

void Game::drawInfo() {
    int x = font->getSize() / 2;
    int y = font->getSize() / 2;

    SDL_Rect rect = {0, 0, getWindowWidth(),
                     infoSize};
    Box(rect, BLACK).render(renderer);

    string s = "Pos: " + to_string(int(car->getX())) + " "
               + to_string(int(car->getY()));
    renderText(s, x, y);
}

//check for collisions
bool Game::Collisions(SDL_Rect _GO1, SDL_Rect _GO2)
{
    Point2D<int> l1, r1, l2, r2;
    
    l1 = { _GO1.x, _GO1.y };
    r1 = { _GO1.x + _GO1.w, _GO1.y + _GO1.h };

    l2 = { _GO2.x, _GO2.y };
    r2 = { _GO2.x + _GO2.w, _GO2.y + _GO2.h };

    // If one rectangle is on left side of other
    if (l1.getX() >= r2.getX() || l2.getX() >= r1.getX())
        return false;

    // If one rectangle is above other
    if (r1.getY() <= l2.getY() || r2.getY() <= l1.getY())
        return false;

    return true;
}

void Game::setUserExit() {
    doExit = true;
}

bool Game::isUserExit() {
    return doExit;
}

int Game::getWindowWidth(){
    return width;
}

int Game::getWindowHeight() {
    return height;
}

SDL_Renderer *Game::getRenderer() {
    return renderer;
}

void Game::setRenderer(SDL_Renderer *_renderer) {
    renderer = _renderer;
}

void Game::loadTextures() {
    if(renderer == nullptr)
        throw string("Renderer is null");

    textureContainer = new TextureContainer(renderer);
}

void Game::renderText(string text, int x, int y, SDL_Color color){
    font->render(renderer, text.c_str(), x, y, color);
}

bool Game::doQuit() {
    return isUserExit();
}

Texture *Game::getTexture(TextureName name) {
    return textureContainer->getTexture(name);
}

Point2D<int> Game::getOrigin() {
    return {int(-(car->getX() - car->getWidth())), 0};
}