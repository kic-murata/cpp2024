#pragma once
#include "bird.h"

class Crow : public Bird {
public:
	Crow() = default;
	~Crow();
	void sing();
	void fly();
};