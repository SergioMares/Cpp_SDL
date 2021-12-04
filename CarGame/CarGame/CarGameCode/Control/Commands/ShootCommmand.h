#pragma once
#include "Command.h"
class ShootCommmand : public Command
{
	bool bShoot;

public:
	const string INFO_STRING = "[E] to shoot";
	ShootCommmand()
	{
		info_string = INFO_STRING;
	};
	~ShootCommmand() = default;
	bool parse(SDL_Event& event) override;
	void execute() override;
};

