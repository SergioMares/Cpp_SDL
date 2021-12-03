#pragma once
#include "GoodObject.h"
class Coin : public GoodObject
{
public:
	Coin(Game* game) : GoodObject(game) 
	{ 
		onEnter(); 
		setDimension(20,20);
	};
	~Coin();

	void draw();
	void update();

	bool receiveCarCollision(Car* car) override;
};

