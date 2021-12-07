#include "Game.h"

Game::Game(string name, int width, int height, int roadLength) {
    this->name = name;
    this->roadLength = roadLength;
    this->width = width;
    this->height = height;
    
    font = new Font("../Images/Monospace.ttf", 12);
    infoSize = int(font->getSize() * 1.8);

    time = 0;
    record = 0;
    doExit = false;       
    bMoveBackward = false;
    bMoveUp = false;
    bMoveDown = false;
    bMoveForward = false;        
    goodEnding = false;
    debug = false;
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
}

void Game::startGame() {   
    //check memory leaks here      
    if (car != nullptr)
        delete car;
    if (goal != nullptr)
        delete goal;
    if (goContainer != nullptr)
        delete goContainer;
    
    car = new Car(this);
    car->setDimension(CAR_WIDTH, CAR_HEIGHT);
    car->setPosition(car->getWidth(), height/ 2.0);

    goal = new Goal(this);
    goal->setDimension(50, height);
    goal->setPosition(roadLength, height / 2.0);    

    goContainer = new GameObjectContainer();   
    GameObjectGenerator::generateObjects(this, 20, 3, 10, 5, 3, 5);
    //GameObjectGenerator::GeneratePU(this, 5);
    

    power = car->getPower();
    initTime = int(SDL_GetTicks());    
}

string Game::getGameName() {
    return name;
}

Game::~Game() {
    delete font;
    delete textureContainer;
    delete car;
    delete goal;
    delete goContainer;

    

    cout << "[DEBUG] deleting game" << endl;
}

void Game::update()
{
    //car movement Y axis
    if (bMoveUp && !(car->getY() <= CAR_HEIGHT) && !bMoveDown)
        car->moveCar(0, 1);
    else if (bMoveDown && !(car->getY() >= height - CAR_HEIGHT / 2) && !bMoveUp)
        car->moveCar(0, -1);
    //car movement X axis
    if (bMoveForward && !bMoveBackward)
        car->moveCar(1, 0);
    else if (bMoveBackward && !bMoveForward)
        car->moveCar(-1, 0);

    //check for car get to goal
    if (car->getX() > roadLength)
    {
        goodEnding = true;
        state = GameOver;
    }
        
      
    //update GameObjects    
    car->update();
    if (bullet != nullptr)
        bullet->update(); 
    goContainer->update();
    goContainer->removeDead();    
    
    

}

//call everything that has to be rendered
void Game::draw()
{
    if (state == Playing)
    {
        car->draw();
        goContainer->draw();
        goal->draw();
        if (bullet != nullptr)
            bullet->draw();
    }    
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

bool Game::modPower(int  _PowerModifier)
{
    power += _PowerModifier;

    if (power <= 0)
        return true;
    else
        return false;
}

void Game::modCoins(int coinsModifier)
{
    coins += coinsModifier;
}

void Game::setDebug(bool _DebugStatus)
{
    debug = _DebugStatus;
}

bool Game::isRebased(GameObject* go)
{
    if (go->getX() < car->getX())
        return true;
    else
        return false;
}

void Game::spawnBullet()
{
   bullet = new Bullet(this);
   bullet->setDimension(20, 5);
   bullet->setPosition(car->getX(), car->getY());

   /*car = new Car(this);
   car->setDimension(CAR_WIDTH, CAR_HEIGHT);
   car->setPosition(car->getWidth(), height / 2.0);*/
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

int Game::getRoadLength()
{
    return roadLength;
}

int Game::getInfoSize()
{
    return infoSize;
}

int Game::getCoins()
{
    return coins;
}

int Game::getCarX()
{
    return car->getX();
}

int Game::getCarY()
{
    return car->getY();
}

GameObjectContainer* Game::getContainer()
{
    return goContainer;
}

SDL_Renderer *Game::getRenderer() {
    return renderer;
}

void Game::setEnding(bool ending)
{
    goodEnding = ending;
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

/*
* exe and then esc
*/