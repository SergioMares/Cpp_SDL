
#include <iostream>
#include "Logic/Game.h"
#include "Control/ViewController.h"
#include "../checkML.h"

using namespace std;


void exampleLeak() {
    int* a = new int(5);
}

int main(int argc, char* argv[]){

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks

    try {
        Game *game = new Game("Car game 1.0", 800, 320, 3000);
        ViewController controller(game);
        controller.run();
        delete game;
    } catch (const string& e){
        cout << e;
    }

    exampleLeak(); // You can remove this line
	return 0;
}


