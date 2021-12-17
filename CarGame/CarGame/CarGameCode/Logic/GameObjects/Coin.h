#pragma once
#include "GoodObject.h"
class Coin : public GoodObject
{
public:
	Coin(Game* game) : GoodObject(game) 
	{ 
		setDimension(20,20);
	};
	~Coin() = default;

	void draw();
	void update();

	bool receiveCarCollision(Car* car) override;
};

