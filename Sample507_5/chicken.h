#pragma once
#include <iostream>
#include <string>
#include "bird.h"
class Chicken : public Bird {
public:
	void sing();
	void fly();
};