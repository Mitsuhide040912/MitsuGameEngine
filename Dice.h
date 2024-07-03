#pragma once
#include "Quad.h"
class Dice
	:public Quad
{
public:
	Dice() :Quad() {};
	~Dice();
	 void InitVertexData()override;
	 void InitIndexData()override;
};

