# A Simple implementation of a stack based Virtual Machine.

## NOTE
I do not intend to continue developing this.

### Releases
v0.1-prerelease is the first and last version to be released, it comes with binaries for stack-vm and sasm.

### Installation
To install both the stack-vm and sasm executable, use the command `sudo mv stack-vm sasm /usr/local/bin` so that you can use the executables universally.

### Info
The current version of the VM has five instructions: halt(0), add(1), sub(2), mul(3), div(4).
- Halt stops execution.
- Add pops the first two values off the stack and pushes the sum of the two values back on to the stack.
- Sub pops the first two values off the stack and pushes the difference of the two values back onto the stack.
- Mul pops the first two values off the stack and pushes the product of the two value back onto the stack.
- Div pops the first two values off the stack and pushes the quotient of the two values back onto the stack.

You can write a program in this VM's native language, Sasm: a simple assembly language.
You can compile you program into executable binaries using the steps below.

### Building from source
Prerequisites:
- Your system must be Unix based, you can not build on Windows.
- You must ensure you have g++ installed on your system(All Unix based OS's should ship with it, but some light releases may not).

To Build:
- Navigate to the project directory in terminal, and type `make`.

### Building Sasm from source
Prerequisites:
- Same as building the vm.

To Build:
- Navigate to projectdir/src/sasm in terminal, and type `make`.

### Installing from source
To install from source, make sure you have built both binaries, stack-vm and sasm. then navigate to the project directory and use the command `make install` to install the binaries globally.

### Compiling .sasm files to binary 
To compile a .sasm file use the executable created when you built Sasm from source.
Have a .sasm file located in the same directory as the Sasm executable.
Use the command `./sasm *yourfilenamehere*.sasm` to compile your .sasm file into a binary that can be executed by this stack vm. After doing this you will have a new file called out.bin in the same directory as Sasm.

### Running out.bin files in the VM
To run an out.bin file, move the out.bin file to the same directory as the stack-vm executable. Then type the command `./stack-vm out.bin` to run your binary file.

### Sasm syntax
There are 4 operators in sasm, integer addition(+), integer subtraction(-), integer multiplication(*) and integer division(/). 

Writing a basic program: 3 6 + 2 * 3 -

The program written above pushes 3 and 6 to the stack, then pops 3 and 6 off the stack, adds 3 and 6 together and then pushes the result(9) back onto the stack, it then pops 9(top of stack) of the stack and multiplies it by 2 pushing the product(18) back onto the stack, next, 3 is pushed onto the stack, then 3 and 18 are popped off the stack and 3 is subtracted from 18, to give a final result of 15.
