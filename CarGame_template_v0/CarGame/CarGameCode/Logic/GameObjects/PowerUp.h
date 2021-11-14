#pragma once
#include "GoodObject.h"


class PowerUp : public GoodObject
{
public:
	PowerUp(Game* game) : GoodObject(game) { onEnter(); };
	~PowerUp();

	void draw();
	void update();

	bool receiveCarCollision(Car* car) override;
};

