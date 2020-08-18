#include "../include/stack-vm.h"

/**
 * @file main.cpp
 * @author Levi Bland
 * @date Aug 18 2020
 */

int main()
{
    StackVm vm;
    std::vector<i32> prog{3, 4, 0x40000001, 5, 0x40000002, 3, 0x40000003, 2, 0x40000004, 0x40000000};
    vm.loadProgram(prog);
    vm.run();
    return 0;
}