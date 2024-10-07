#pragma once
#include <iostream>
#include "bird.h"
using namespace std;
class Crow : public Bird {
public:
	void sing();
	void fly();
};