#pragma once
#include <stdio.h>
#include <functional>

class hogeB {
    typedef std::function<void(int, int)> FUNC_POINTER;
    FUNC_POINTER p;

public:
    void Set_HogeA(const FUNC_POINTER& func);
    void Set_func();
};