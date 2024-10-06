#include "classA.h"
#include "classB.h"

int main() {
    hogeA m_hogeA = hogeA();
    hogeB m_hogeB = hogeB();
//    auto pf = m_hogeA.DoingFunc;
    void (hogeA:: * fpFunc)(int,int) = &hogeA::SetNumber;

    printf("%x\n", fpFunc);

    printf("hogeA:%d \n", m_hogeA.GetNumberA());
    printf("hogeB:%d \n", m_hogeA.GetNumberB());
    printf("============================ \n");
    m_hogeA.DoingFunc();
    m_hogeB.Set_func();

    printf("hogeA:%d \n", m_hogeA.GetNumberA());
    printf("hogeB:%d \n", m_hogeA.GetNumberB());
    printf("============================ \n");
}