#include "bird.h"
#include "crow.h"
#include "chicken.h"

int main() { //pCrow{} ‚Í pCrow = nullptr ‚Æ“¯‚¶
	Bird* pCrow{}, * pChicken{}, * pBird{};
	//Crow* pCrow{};
	//Chicken* pChicken{};
	pBird = new Bird();
	pCrow = new Crow();
	pChicken = new Chicken();
	pCrow->fly();
	pChicken->fly();
	pCrow->sing();
	pChicken->sing();
	delete pCrow;
	delete pChicken;
	return 0;
}