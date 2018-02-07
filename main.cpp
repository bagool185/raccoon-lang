#include <iostream>

#include "TrashPanda/Lexer.h"

int main() {

    RCC::Lexer test_lexer("../Tests/test_tokens.rcc");

    test_lexer.tokenise();

    return 0;
}