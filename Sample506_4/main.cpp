#include <iostream>
#include "bird.h"
#include "crow.h"
#include "chicken.h"
using namespace std;
int main() {
	Bird* pBird1{}, * pBird2{};
	//Crow* pBird1{};
	//Chicken* pBird2{};
	Bird* pBird = new Bird();
	pBird1 = new Crow();
	pBird2 = new Chicken();
	pBird1->fly();	//�J���X
	pBird2->fly();	//�j���g��
	pBird1->sing();	//�J���X
	pBird2->sing();	//�j���g��
	delete pBird1;
	delete pBird2;
	return 0;
}