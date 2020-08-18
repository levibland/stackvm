#include "sasminclude/lexer.h"

/**
 * @file lexer.cpp
 * @author Levi Bland
 * @date Aug 18 2020
 * The function of lexer.cpp is to create tokens from a stack-vm assembly file.
 */

strings Lexer::lex(std::string s) {
    strings strlst;
    char lexeme[256];
    int i = 0;
    int j = 0;
    State state = START;
    int done = 0;
    int len = s.length();
    int balance = 0;

    while (i < len) {
        switch (state) {
            case START:
                break;
            case READCHAR:
                break;
            case READBLOCK:
                break;
            case SKIP:
                break;
            case DUMP:
                break;
            case COMMENT:
                break;
            case END:
                break;
        }
    }

    return strlst;
}