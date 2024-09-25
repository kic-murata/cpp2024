#pragma once
#include <memory>

class B {
public:
  static std::unique_ptr<B> create();
  int getHp();
};