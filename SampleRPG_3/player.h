#include "chara.h"

class Player : public Chara {
private:
	int m_Sp;
public:
	Player();
	Player(int hp, int atk, int def, int sp);
	int getSp();
};