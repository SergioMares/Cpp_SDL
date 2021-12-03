#pragma once
#include "GoodObject.h"
class Turbo : public GoodObject
{
public:
	Turbo(Game* game) : GoodObject(game)
	{
		onEnter();
		setDimension(50, 50);
	};
	~Turbo();

	void draw();
	void update();

	bool receiveCarCollision(Car* car) override;
};

