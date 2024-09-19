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

	pCrow->fly();    //Birdクラスのfly()を実行
	pChicken->fly(); //Birdクラスのfly()を実行
	pCrow->sing();   //Crowクラスのsing()を実行
	pChicken->sing();//Chickenクラスのsing()を実行
	//delete pCrow;
	//delete pChicken;
	return 0;
}