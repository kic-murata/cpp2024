#include "classA.h"
#include "classB.h"

hogeA::hogeA(): NumA(1),NumB(1){}

void hogeA::SetNumber(int a, int b) {
    NumA = a;
    NumB = b;
}
void hogeA::DoingFunc() {
    
    printf("aaa");
    m_hogeB.Set_HogeA([&](int a, int b) {
        SetNumber(a, b);
        });
}

