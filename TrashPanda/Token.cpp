//
// Created by bagool on 07/02/2018.
//

#include <exception>
#include <cstdio>

#include "Token.h"

using namespace RCC;




inline bool Token::is_set() {
    // first character is \0 <=> string is empty
    return (_token_name[0] != 0);
}

Token::Token(ct_str& token_name) {
    // test if the token is a valid keyword
    try {
        _token_type.keyword_ = mapped_keywords.at(token_name);
        _token_name = token_name;
        return;
    }
    catch (std::exception &e) {
        // if the key doesn't exist in the map
        // it wil throw an out_of_range exception
        // and nothing is to be done
    };
    // test if the token is a valid operator
   try {
       _token_type.operator_ = mapped_operators.at(token_name);
       _token_name = token_name;
       return;
   }
   catch (std::exception& e) {
       // if the key doesn't exist in the map
       // it will throw an out_of_range exception
       // and nothing is to be done
   }
    // if the token is not set yet, it will be a literal
    if (!is_set()) {
        _token_name = token_name;

        if (std::regex_match(token_name, integer_literals)) {
            _token_type.literal_ = LiteralTypes::LT_INT;
        }
        else if (std::regex_match(token_name, decimal_literals)) {
            _token_type.literal_ = LiteralTypes::LT_DEC;
        }
        else if (std::regex_match(token_name, string_literal)) {
            _token_type.literal_ = LiteralTypes::LT_ID;
        }
        else if (std::regex_match(token_name, identifier_literal)) {
            _token_type.literal_ = LiteralTypes::LT_ID;
        }
        else {
            printf("#%s#", token_name);
            throw E("Invalid token name");
        }
    }
}

void Token::print() {
    printf("Token: #%s#\n", _token_name.c_str());
}