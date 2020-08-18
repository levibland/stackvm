#include "include/stack-vm.h"

/**
 * Instruction format
 * Header: 2 bits
 * Data: 30 bits
 * 
 * Header format:
 * 0 => positive integer
 * 1 => primitive instruction
 * 2 => negative integer
 * 3 => undefined (currently)
 */

// Function implementations
StackVm::StackVm() {
    memory.reserve(1000000);
}

i32 StackVm::getType(i32 instruction) {
    i32 type = 0xc0000000;
    type = (type & instruction) >> 30;
    return type;
}

i32 StackVm::getData(i32 instruction) {
    i32 data = 0x3fffffff;
    data = data & instruction;
    return data;
}

void StackVm::fetch() {
    pc++;
}

void StackVm::decode() {
    typ = getType(memory[pc]);
    dat = getData(memory[pc]);
}

void StackVm::execute() {
    // If type of instruction is positive or negative
    // Increment the stack pointer and set the top of the stack dat.
    // If the instruction is not a number => doPrimitive().
    if (typ == 0 || typ == 2) {
        sp++;
        memory[sp] = dat;
    } else {
        doPrimitive();
    }
}

/**
 * doPrimitve():
 * doPrimitive is the equivalent of the control mechanism in a physical CPU
 */
void StackVm::doPrimitive() {
    // Define instruction set
    switch (dat) {
        case 0: // Halt execution
            // TEMPORARY: for debug purposes
            std::cout << "Halt" << std::endl;
            running = 0;
            break;
        case 1: // Add
            // TEMPORARY: for debug purposes
            std::cout << "Add " << memory[sp - 1] << " " << memory[sp] << std::endl;
            memory[sp - 1] = memory[sp - 1] + memory[sp];
            break;
    }
}

void StackVm::run() {
    /**
     * System is loaded at the program counter.
     * To bootstrap the system, pc needs to be set to
     * pc's previous value - 1
     */
    pc -= 1;
    // While CPU is not halted, infinitely loop through: fetch(), decode(), execute().
    while (running == 1) {
        fetch();
        decode();
        execute();
        std::cout << "TOS: " << memory[sp] << std::endl;
    }
}

void StackVm::loadProgram(std::vector<i32> prog) {
    for (i32 i = 0; i < prog.size(); i++) {
        memory[pc + i] = prog[i];
    }
}