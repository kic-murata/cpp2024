#include <stdio.h>
#include "classB.h"
#include <iostream>

void hogeB::Set_HogeA(const FUNC_POINTER& func) {
    p = func;
//    std::cout << func << std::endl;
    printf("%x\n", p);
}

void hogeB::Set_func() {
    p(1, 2);
}