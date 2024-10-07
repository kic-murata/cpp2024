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
	pBird1->fly();	//カラス
	pBird2->fly();	//ニワトリ
	pBird1->sing();	//カラス
	pBird2->sing();	//ニワトリ
	delete pBird1;
	delete pBird2;
	return 0;
}