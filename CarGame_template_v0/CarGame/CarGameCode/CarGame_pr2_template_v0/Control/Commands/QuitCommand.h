#ifndef CARGAME_QUITCOMMAND_H
#define CARGAME_QUITCOMMAND_H

#include "Command.h"

class QuitCommand : public Command{

public:
    const string INFO_STRING = "[ESC] to quit";

    QuitCommand(){
        info_string = INFO_STRING;
    };
    ~QuitCommand()=default;
    bool parse(SDL_Event &event) override;
    void execute() override;
};


#endif //CARGAME_QUITCOMMAND_H
