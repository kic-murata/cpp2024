#pragma once
#include <stdio.h>
#include "classB.h"

class hogeA {
private:
    int NumA;
    int NumB;
    hogeB m_hogeB = hogeB();
public:
    hogeA();
    //hogeA() {
    //    NumA = 0;
    //    NumB = 0;
    //}
    void DoingFunc();
    void SetNumber(int a, int b);
    int GetNumberA() { return NumA; }
    int GetNumberB() { return NumB; }
};