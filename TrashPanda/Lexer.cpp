//
// Created by bagool on 07/02/2018.
//
#include <fstream>

#include "Lexer.h"
#include "../Common/Util/StringUtil.h"
#include "../Common/Util/ExceptionHandlingUtil.h"
#include "../Common/Util/LogUtil.h"

using namespace RCC;

/* populate the data from the source file */
void
Lexer::_populate_data() {
    std::ifstream instream(_data_filename);
    std::string line;
    Log::load_log({LogLevel::INFO, "getting data for tokenizer", ""});
    while (std::getline(instream, line)) {
        // add the line only if it's not empty
        trim(line);
        if (!line.empty()) {
            _data.push_back(line);
            Log::load_log({LogLevel::DEBUG, line.c_str(), " line read by tokenizer"});
        }
    }

    instream.close();
}
/* populates the token stack with
 * tokens generated from the provided
 * data
 */
void Lexer::tokenise() {
    _populate_data();
    vect_s data_copy = get_data();

    Log::load_log({LogLevel::INFO, "iterating through tokens", ""});

    for (std::string& line : data_copy) {
        vect_s split_line = split(line, ' ');

        for (ct_str& token : split_line) {

            if (token[0] == token[1] && token[0] == '/') {
                break;
            }

            try {
                Token new_token(token);
                _token_stack.push(new_token);
            }
            catch (std::exception& e) {
                Log::load_log({LogLevel::ERROR, e.what(), "in Lexer::tokenise()"});
            }
        }
    }
}