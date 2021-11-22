#ifndef CARGAME_QUITCOMMAND_H
#define CARGAME_QUITCOMMAND_H

#include "Command.h"

class QuitStartCommand : public Command{
    bool bStart = false;
    bool bEnd = false;
public:
    const string INFO_STRING = "[ESC] to quit";

    QuitStartCommand(){
        info_string = INFO_STRING;
    };
    ~QuitStartCommand()=default;
    bool parse(SDL_Event &event) override;
    void execute() override;
};


#endif //CARGAME_QUITCOMMAND_H
