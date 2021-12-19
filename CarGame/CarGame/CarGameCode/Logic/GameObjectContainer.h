#ifndef CARGAME_GAMEOBJECTCONTAINER_H
#define CARGAME_GAMEOBJECTCONTAINER_H

#include <vector>
using namespace std;

class GameObject;
class Collider;

class GameObjectContainer 
{
    vector<GameObject*> gameObjects;
public:

    GameObjectContainer(){};
    ~GameObjectContainer();
    void update();
    void draw();
    void drawDebug();
    void add(GameObject *gameObject);
    void removeDead();
    bool hasCollision(GameObject *g);
    vector<GameObject*> getObjects();
    vector<Collider*> getCollisions(GameObject *g);
    vector<Collider*> getCollisions(int x, int y, int range);
    vector<Collider*> getCollisions();
};


#endif //CARGAME_GAMEOBJECTCONTAINER_H
