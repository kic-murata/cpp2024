#include <iostream>
//関数ポインタの例
int plus(int x, int y)
{
  return x + y;
}
int minus(int x, int y)
{
  return x - y;
}

int main()
{
//  int (*op)(int, int) { plus };
  int (*op)(int, int);
  op = plus;
  std::cout << op(10, 1) << "\n";

  op = minus;
  std::cout << op(10, 1) << "\n";
}