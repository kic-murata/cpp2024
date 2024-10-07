#pragma once
#include <iostream>
#include <string>
#include "bird.h"
class Crow :public Bird {
public:
	void sing();
	void fly();
};