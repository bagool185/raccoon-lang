#include <iostream>

#include "TrashPanda/Lexer.h"
#include "Common/Util/ExceptionHandlingUtil.h"
#include "Common/Util/LogUtil.h"

int main() {

    try {
        RCC::Lexer test_lexer("../Tests/test_tokens.rcc");

        test_lexer.tokenise();
        RCC::Log::save_logs();
        RCC::Log::print_logs();
        RCC::Log::clear_logs();
    }
    catch (std::exception& e) {
        printf("%s", e.what());
        RCC::Log::save_logs();
        RCC::Log::print_logs();
        RCC::Log::clear_logs();
    }

    return 0;
}