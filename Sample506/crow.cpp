#include "crow.h"
Crow::~Crow() {
	cout << "Crowのデストラクタ" << endl;
}

void Crow::sing() {
	cout << "カーカー" << endl;
}
void Crow::fly() {
	cout << "カラスが飛ぶ" << endl;
}