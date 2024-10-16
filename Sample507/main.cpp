#include <iostream>
#include "bird.h"
#include "crow.h"
#include "chicken.h"
using namespace std;

int main()
{
	//Bird* pCrow{}, * pChicken{}, * pBird{};
	//Bird* pChicken{}, * pBird{};
	unique_ptr<Bird> pCrow = make_unique<Crow>();
	unique_ptr<Bird> pChicken = make_unique<Chicken>();
	//	pCrow = new Crow();
  //pChicken = new Chicken();
	//pBird = new Bird();
	//unique_ptr<Bird> pCrow = make_unique<Crow>();
	//unique_ptr<Bird> pChicken = make_unique<Chicken>();
	//unique_ptr<Bird> pCrow(new Crow());
	//unique_ptr<Bird> pChicken(new Chicken());
	pCrow->fly();
	pChicken->fly();
	pCrow->sing();
	pChicken->sing();
	//delete pCrow;
	//delete pChicken;
	return 0;
}