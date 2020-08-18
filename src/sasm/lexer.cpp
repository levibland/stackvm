#include "sasminclude/lexer.h"

/**
 * @file lexer.cpp
 * @author Levi Bland
 * @date Aug 18 2020
 * The function of lexer.cpp is to create tokens from a stack-vm assembly file input file.
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

    // NOTE: having this many switch/case and if statements is very bad for performance.
    while (i < len) {
        switch (state) {
            case START:
                if (my_isspace(s[i])) {
                    state = SKIP;
                } else if (isgroup(s[i])) {
                    if (s[i] == '"') {
                        lexeme[j] = s[i];
                        j++;
                        i++;
                    }
                    state = READBLOCK;
                } else if (s[i] == '/' && s[i + 1] == '/') {
                    i += 2;
                    state = COMMENT;
                } else {
                    state = READCHAR;
                }
                break;
            case READCHAR:
                if (my_isspace(s[i])) {
                    state = DUMP;
                } else if (s[i] == '\\') {
                    i += 2;
                } else if (isgroup(s[i])) {
                    if (s[i] == '"') {
                        lexeme[j] = s[i];
                        j++;
                        i++;
                    }
                    state = READBLOCK;
                } else if (isspecial(s[i])) {
                    if (j == 0) {
                        lexeme[j] = s[i];
                        j++;
                        i++;
                    }
                    state = DUMP;
                } else if (s[i] == '/' && s[i + 1] == '/') {
                    i += 2;
                    state = COMMENT;
                } else {
                    lexeme[j] = s[i];
                    j++;
                    i++;
                }
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