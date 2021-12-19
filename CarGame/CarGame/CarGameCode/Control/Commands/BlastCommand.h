#pragma once
#include "Command.h"
class BlastCommand : public Command
{
	int fixedX, x, y, range = 300;
public:
	const string INFO_STRING = "Click on screen to blast some obstacles";
	BlastCommand()
	{
		info_string = INFO_STRING;
	};
	~BlastCommand() = default;
	bool parse(SDL_Event & event) override;
	void execute() override;
};

