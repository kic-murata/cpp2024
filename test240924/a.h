#pragma once
#include <memory>
class B;

class A {

public:
  static std::unique_ptr<A> create();
  ~A();
  int getHp();
  std::unique_ptr<B> _b;

private:
  void init();

};