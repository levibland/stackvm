# A Simple implementation of a stack based Virtual Machine.

### Info
The current version of the VM has two instructions: halt(0) and add(1).
Halt stops execution.
Add pops two values off the stack and pushes the sum of the two values back on to the stack.

Currently the only way to call either instruction is to modify the main.cpp, anf then re-build the entire application.

### Building from source
Prerequisites:
- Your system must be Unix based, you can not build on Windows.
- You must ensure you have g++ installed on your system(All Unix based OS's should ship with it, but some light releases may not).

To Build:
 - Navigate to the project directory in terminal, and type make.
 
To Run:
 - Navigate to the project directory in terminal, and type ./bin/stack-vm, do this ONLY after you have built form source as this repo does not have the binary     files.
