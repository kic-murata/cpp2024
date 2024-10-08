#include "bird.h"
Bird::~Bird() {
	cout << "Birdのデストラクタ" << endl;
}

void Bird::sing() {
	cout << "鳥が鳴く" << endl;
}
void Bird::fly() {
	cout << "鳥が飛ぶ" << endl;
}