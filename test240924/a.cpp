#include "a.h"
#include "b.h"
#include <iostream>
std::unique_ptr<A> A::create() {
  std::unique_ptr<A> ptr(new A);
  ptr->init();
  std::cout << ptr << std::endl;
  return ptr;
}

A::~A() = default;

int A::getHp() {
  return 10;
}

void A::init() {
  _b = B::create();
  std::cout << _b->getHp() << std::endl;
  
}