#include <iostream>
#include <fstream>
#include "sasminclude/lexer.h"

typedef uint32_t i32;

using namespace std;

// Sasm compiler
vector<i32> compileToInstructions(strings s);

bool isInteger(string s);

bool isPrimitive(string s);

i32 mapToNUmber(string s);

int main(int argc, char *argv[])
{
    // Check for input errors
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <sasm-file-name>" << endl;
        exit(1);
    }

    // Read sasm input file
    ifstream infile;
    infile.open(argv[1]);
    if (!infile.is_open()) {
        cout << "Error: Could not open [" << argv[1] << "]" << endl;
        exit(1);
    }

    string line;
    string contents;
    while (getline(infile, line)) {
        contents += line + "\n";
    }
    infile.close();

    // Parse the input file
    Lexer lexer;
    strings lexemes = lexer.lex(contents);

    // Compile to binary
    vector<i32> instructions = compileToInstructions(lexemes);

    // Write binary instructions to binary file
    ofstream outfile;
    outfile.open("out.bin", ios::binary);
    for (i32 i = 0; i < instructions.size(); i++) {
        outfile.write(reinterpret_cast<char *>(&instructions[i]), sizeof(i32));
    }
    outfile.close();
    return 0;
}

vector<i32> compileToInstructions(strings s) {
    vector<i32> instructions;
    for (i32 i = 0; i < s.size(); i++) {
        if (isInteger(s[i])) {
            instructions.push_back(stoi(s[i]));
        } else {
            i32 instruction = mapToNUmber(s[i]);
            if (instruction != -1) {
                instructions.push_back(instruction);
            } else {
                cout << "Error: Invalid instruction [" << s[i] << "]" << endl;
            }
        }
    }
    return instructions;
}

bool isInteger(string s) {
    for (i32 i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

i32 mapToNumber(string s) {
    if (s == "+") {
        return 0x40000001;
    } else if (s == "-") {
        return 0x40000002;
    } else if (s == "*") {
        return 0x40000003;
    } else if (s == "/") {
        return 0x40000004;
    }
    return -1;  // Invalid instruction
}