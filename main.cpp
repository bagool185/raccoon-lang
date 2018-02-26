#include <iostream>

#include "TrashPanda/Lexer.h"
#include "Common/Util/LogUtil.h"

#include "Tests/test_tokens.h"

int main() {

    try {
        RCC::Lexer test_lexer("../Tests/test_tokens.rcc");

        FILE* log_file = fopen("log_file.log", "w");
        setbuf(log_file, nullptr);
        test_lexer.tokenise();
        RCC::Log::save_logs(log_file);
        RCC::Log::clear_logs();
    }
    catch (std::exception& e) {
        printf("%s", e.what());
        RCC::Log::save_logs();
        RCC::Log::clear_logs();
    }

    return 0;
}