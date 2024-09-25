#include "a.h"
#include "b.h"
#include <iostream>

int main(void) {
  auto a = A::create();
  std::cout << a->getHp() << std::endl;
  std::cout << a->_b->getHp() << std::endl;
  return 0;
}