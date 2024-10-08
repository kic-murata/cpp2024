#pragma once
#include<iostream>
using namespace std;

class Bird {
public:
	Bird() = default;
	virtual ~Bird();
	virtual void sing() = 0;
	void fly();
};