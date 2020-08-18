#ifndef STACK_VM_H
#define STACK_VM_H

#include <iostream>
#include <vector>

// Type definitions
typedef int32_t i32;

class StackVm {
    i32 pc = 100;   // Program counter - starts at address 100.
    i32 sp = 0;     // Stack Pointer - starts at address 0.
    std::vector<i32> memory;  // Memory that virtual CPU will access.
    i32 typ = 0;    // Type register
    i32 dat = 0;    // Data register
    i32 running = 1;// Check if running

    // Private functions
    i32 getType(i32 instruction);
    i32 getData(i32 instrustion);
    // Main CPU function declarations
    void fetch();
    void decode();
    void execute();
    void doPrimitive();

    public:
    // Public functions
    StackVm();  // Constructor
    void run();
    void loadProgram(std::vector<i32> prog); // Initialize memory
};

#endif