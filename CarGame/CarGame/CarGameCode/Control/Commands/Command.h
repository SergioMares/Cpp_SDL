
#ifndef CARGAME_COMMAND_H
#define CARGAME_COMMAND_H

#include <string>
#include <SDL_events.h>
using namespace std;

class Game;

class Command {
protected:
    string info_string;
    Game *game;
public:

    Command(){};
    virtual ~Command()=default;
    virtual bool parse(SDL_Event &event)=0;
    virtual void execute()=0;
    void bind(Game *game){
        this->game = game;
        //game->appendHelpInfo(info_string);
    }
};


#endif //CARGAME_COMMAND_H
