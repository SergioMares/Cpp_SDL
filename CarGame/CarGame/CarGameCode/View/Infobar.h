#ifndef CARGAME_INFOBAR_H
#define CARGAME_INFOBAR_H

class Game;

class Infobar {
    Game *game;
public:
    Infobar(Game *game):game(game){}

    void drawInfo();
    void drawHelp();
    void drawState();
};


#endif //CARGAME_INFOBAR_H
