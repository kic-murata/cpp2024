#include <iostream>
#include "bird.h"
#include "crow.h"
#include "chicken.h"
using namespace std;

int main()
{
	////Crow* pCrow(new Crow());
	////Chicken* pChicken(new Chicken());
	//Bird* pCrow(nullptr), * pChicken(nullptr);
	//pCrow = new Crow;
 // pChicken = new Chicken;
	unique_ptr<Bird> pCrow = make_unique<Crow>();
	unique_ptr<Bird> pChicken = make_unique<Chicken>();
	//unique_ptr<Bird> pCrow(new Crow());
	//unique_ptr<Bird> pChicken(new Chicken());

	pCrow->fly();    //Bird�N���X��fly()�����s
	pChicken->fly(); //Bird�N���X��fly()�����s
	pCrow->sing();   //Crow�N���X��sing()�����s
	pChicken->sing();//Chicken�N���X��sing()�����s
	//delete pCrow;
	//delete pChicken;
	return 0;
}