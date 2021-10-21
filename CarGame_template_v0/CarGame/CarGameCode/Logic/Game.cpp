//
// Created by eys on 20/8/21.
//

#include "Game.h"

Game::Game(string name, int width, int height, int roadLength) {
    this->name = name;
    this->roadLength = roadLength;
    this->width = width;
    this->height = height;
    doExit = false;
    font = new Font("../Images/Monospace.ttf", 12);

    //const new vars
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

    rock = new Rock(this);

    unsigned int tempoSize = rand() % ROCK_SIZE + ROCK_RANGE;
    rock->setDimension(tempoSize, tempoSize);

    unsigned int tempoPos = rand() % roadLength + ROCK_SIZE;
    cout << tempoPos << endl;
    rock->setPosition(tempoPos, height / 2.0);
}

string Game::getGameName() {
    return name;
}

Game::~Game() {
    cout << "[DEBUG] deleting game" << endl;
}

void Game::update()
{            
    if (bMoveUp && !(car->getY() <= car->getHeight()))
        car->moveCar(0, 1);
    else if (bMoveDown && !(car->getY() >= height - CAR_HEIGHT/2))
        car->moveCar(0, -1);

    if (bMoveForward)
        car->moveCar(1, 0);
    else if (bMoveBackward)
        car->moveCar(-1, 0);

    car->update();
}

void Game::draw(){
    car->draw();
    rock->draw();
    drawInfo();
}

//our definitions


//bool control
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
                     int(font->getSize() * 1.8)};
    Box(rect, BLACK).render(renderer);

    string s = "Pos: " + to_string(int(car->getX())) + " "
               + to_string(int(car->getY()));
    renderText(s, x, y);
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