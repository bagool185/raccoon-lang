//
// Created by bagool on 26/02/2018.
//

#include <regex>

#include "../TrashPanda/Token.h"

using namespace RCC;
/* check if a given string is a pre-defined token */
bool test_token(const std::string& literal) {

    try {

        mapped_operators.at(literal);

        return true;

    } catch(...) {  }

    try {

        mapped_keywords.at(literal);
        return true;
    } catch(...) {}

    if (std::regex_match(literal, decimal_literals)) {
        return true;
    }

    if (std::regex_match(literal, integer_literals)) {
        return true;
    }

    if (std::regex_match(literal, string_literal)) {
        return true;
    }

    return std::regex_match(literal, identifier_literal);
}