#pragma once
#include "Command.h"
#include "../../Logic/GameObjectGenerator.h"

class CheatCommand : public Command
{
	int id = 0;
public:
	const string INFO_STRING = "[0...9] to instance different Game Objects";
	CheatCommand()
	{
		info_string = INFO_STRING;
	};
	~CheatCommand() = default;
	bool parse(SDL_Event & event) override;
	void execute() override;
};

