#pragma once
#include<iostream>
using namespace std;

class Bird {
public:
	virtual void sing() = 0;
	void fly();
};