#include "b.h"

std::unique_ptr<B> B::create() {
  std::unique_ptr<B> ptr(new B);
  return ptr;
}
int B::getHp() {
  return 100;
}