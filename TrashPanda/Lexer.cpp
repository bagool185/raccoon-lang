//
// Created by bagool on 07/02/2018.
//
#include <fstream>

#include "Lexer.h"
#include "../Common/Util/StringUtil.h"

#define COMMENT "//"

using namespace RCC;

/* populate the data from the source file */
void Lexer::_populate_data() {
    std::ifstream instream(_data_filename);
    std::string line;

    while (instream >> line) {
        _data.push_back(line);
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

    for (const std::string& line : data_copy) {
        printf("#%s#\n", line.c_str());
    }
}