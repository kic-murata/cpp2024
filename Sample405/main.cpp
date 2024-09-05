#include "rat.h"

int main()
{
  Rat* r1, * r2, * r3;
  r1 = new Rat();
  r1->squeak();
  Rat::showNum();
  r2 = new Rat();
  r3 = new Rat();
  r2->squeak();
  r3->squeak();
  Rat::showNum();
  delete r1;
  delete r2;
  Rat::showNum();
  delete r3;
  Rat::showNum();
  return 0;
}
