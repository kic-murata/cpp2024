#pragma once
#include <iostream>
#include "bird.h"
using namespace std;
class Chicken : public Bird {
public:
	void sing();
	void fly();
};