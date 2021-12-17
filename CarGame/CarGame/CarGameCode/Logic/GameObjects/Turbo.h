#pragma once
#include "GoodObject.h"
class Turbo : public GoodObject
{
public:
	Turbo(Game* game) : GoodObject(game)
	{
		setDimension(50, 50);
	};
	~Turbo() = default;

	void draw();
	void update();

	bool receiveCarCollision(Car* car) override;
};

