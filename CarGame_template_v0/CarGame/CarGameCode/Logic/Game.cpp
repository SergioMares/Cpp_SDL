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
    
    car = new Car(this);
    car->setDimension(CAR_WIDTH, CAR_HEIGHT);
    car->setPosition(car->getWidth(), height/ 2.0);    

    goal = new Goal(this);
    goal->setDimension(50, height);
    goal->setPosition(roadLength, height / 2.0);

    goContainer = new GameObjectContainer();

    GameObjectGenerator::generate(this, 20);
    
    power = car->getPower();
    initTime = int(SDL_GetTicks());    

    //rocks.clear(); clean when game ends, put eveyone as dead
    /*for (size_t i = 0; i < OBSTACLES; i++)
    {        
        rocks.push_back(new Rock(this));
    }*/

    /*for (size_t i = 0; i < OBSTACLES; i++)    
        goContainer->add(new Rock(this));*/
    

    
    /*
    for (auto a : rocks) 
    {        
        unsigned int tempoSize = rand() % ROCK_SIZE + ROCK_RANGE;
        a->setDimension(tempoSize, tempoSize);

        unsigned int tempoPosX = rand() % roadLength + (ROCK_SIZE + CAR_WIDTH);
        unsigned int tempoPosY = rand() % (height-ROCK_SIZE) + infoSize;

        a->setPosition(tempoPosX, tempoPosY);


    }*/
    
    /*
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
                            puts("rock colision btw each other");
                            //break;
                        }
                    }                    
                }                
            }            
        }
    }*/
}

string Game::getGameName() {
    return name;
}

Game::~Game() {
    delete font;
    delete textureContainer;
    delete car;
    delete goal;
    /*for (auto a : rocks)
        delete a;    */
    goContainer->~GameObjectContainer();

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

    //check collisions car-rock
    /*
    for (size_t i = 0; i < OBSTACLES; i++)
    {
        if (rocks[i] != nullptr)
        {
            if (Collisions(car->getCollider(), rocks[i]->getCollider()))
            {
                rocks[i] = nullptr;

                car->setVelocity(0);
                if (modPower(-1))
                {
                    goodEnding = false;
                    state = GameOver;
                }
                    
            }
        }
    }*/

    //check if objects out of the window
    for (size_t i = 0; i < OBSTACLES; i++)
    {
        /*if (rocks[i] != nullptr)
        {
            if (rocks[i]->getX() < 0)
                rocks[i] = nullptr;            
        }*/
    }

    //check for car get to goal
    if (car->getX() > roadLength)
    {
        goodEnding = true;
        state = GameOver;
    }
        
      
    //update GameObjects    
    car->update();
   /* for (auto a : rocks)
    {
        if (a != nullptr)
            a->update();
    }*/       
    goContainer->update();
}

//call everything that has to be rendered
void Game::draw()
{
    drawInfo();
    if (state == Playing)
    {
        car->draw();
       /* for (auto a : rocks)
        {
            if (a != nullptr)
                a->draw();
        }*/
        goContainer->draw();
        goal->draw();
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

void Game::drawInfo() {
    switch (state)
    {
    case Game::Menu:
    {        
        renderText("Welcome to ¡A todo gas!", width/3, height/3);
        renderText("Record: (soon!)", width / 3, (height / 3) + font->getSize());
        renderText("Press Space to begin", width / 3, (height / 3) + font->getSize()*2);
        renderText("Press Esc at any time to close the game", width / 3, (height / 3) + font->getSize()*3);

        break;
    }
    case Game::Playing:
    {        
        int x = font->getSize() / 2;
        int y = font->getSize() / 2;
        time = (int(SDL_GetTicks()) - initTime) / 1000;

        SDL_Rect rect = { 0, 0, getWindowWidth(),
                         infoSize };
        Box(rect, BLACK).render(renderer);

        string s =
            "   Position: " + to_string(int(car->getX())) + " " + to_string(int(car->getY())) +
            "   Distance: " + to_string(int(roadLength - car->getX())) +
            "   Velocity: " + to_string(int(car->getVelocity())) +
            "   Power: " + to_string(power) +
            "   Time: " + to_string(time) +
            "   Obstacles: (soon!)"
                ;
        
        
        renderText(s, x, y);

        break;
    }
    case Game::GameOver:
        if (goodEnding)
        {            
            renderText("Congratulations!", width / 3, height / 3);
            renderText("You win!", width / 3, (height / 3) + font->getSize());
            renderText("Your time: " + to_string(time), width / 3, (height / 3) + font->getSize() * 2);
            if (time <= record)
            {
                record = time;
                renderText("!!NEW RECORD!!", width / 3, (height / 3) + font->getSize() * 3);
            }
            else
                renderText("Press SPACE to play again", width / 3, (height / 3) + font->getSize() * 3);
        }
        else
        {
            renderText("Oops :(", width / 3, height / 3);
            renderText("You loose!", width / 3, (height / 3) + font->getSize());
            renderText("Your time: " + to_string(time), width / 3, (height / 3) + font->getSize() * 2);
            renderText("Press SPACE to try again", width / 3, (height / 3) + font->getSize() * 3);
        }
        break;
    default:
        break;
    }
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

bool Game::modPower(int  _PowerModifier)
{
    power += _PowerModifier;

    if (power <= 0)
        return true;
    else
        return false;

}

void Game::setDebug(bool _DebugStatus)
{
    debug = _DebugStatus;
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

GameObjectContainer* Game::getContainer()
{
    return goContainer;
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