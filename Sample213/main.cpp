#include <iostream>
#include <memory>

namespace A {
  auto b = 0;
  namespace B {
    auto b = 9;
    auto c() { return 100; }
  }
}

using namespace A::B;

int main()
{
  std::shared_ptr<int> a(new int(100));
  int* p = a.get();

  std::cout << "*a=" << *a << std::endl;
  std::cout << "*p=" << *p << std::endl;

  *p = 200;
  std::cout << "*pの値を200に変更" << std::endl;
  std::cout << "*a=" << *a << std::endl;

  *a = 300;
  std::cout << "*aの値を300に変更" << std::endl;
  std::cout << "*p=" << *p << std::endl;

  std::cout << "b:" << b << std::endl;
  std::cout << "b:" << A::b << std::endl;
  std::cout << "b:" << A::B::b << std::endl;
  std::cout << "c:" << A::B::c() << std::endl;


  return 0;
}
