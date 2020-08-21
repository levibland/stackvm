CFLAGS = -std=c++11

all: stack-vm

stack-vm: stack-vm.o main.o
	$(CXX) $(CFLAGS) stack-vm.o main.o -o bin/stack-vm

main.o: src/main.cpp
	$(CXX) $(CFLAGS) -c src/main.cpp

stack-vm.o: include/stack-vm.h src/stack-vm.cpp
	$(CXX) $(CFLAGS) -c src/stack-vm.cpp

install: stack-vm src/sasm/sasm
	sudo mv stack-vm src/sasm/sasm /usr/local/bin

clean:
	rm -f *.o 
