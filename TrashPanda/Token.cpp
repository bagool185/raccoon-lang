//
// Created by bagool on 07/02/2018.
//

#include <cstdio>

#include "Token.h"
#include "../Common/Util/ExceptionHandlingUtil.h"
#include "../Common/Util/LogUtil.h"

using namespace RCC;

inline bool Token::is_set() {
    return (!_token_name.empty());
}

Token::Token(ct_str& token_name) {
    // test if the token is a valid keyword
    try {
        _token_type.keyword_ = mapped_keywords.at(token_name);
        _token_name = token_name;
        _token_type.union_type = 1;
        Log::load_log({LogLevel::DEBUG, token_name.c_str(), "keyword"});
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
       _token_type.union_type = 0;
       Log::load_log({LogLevel::DEBUG, token_name.c_str(), "operator"});
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
        _token_type.union_type = 2;

        if (std::regex_match(token_name, integer_literals)) {
            _token_type.literal_ = LiteralTypes::LT_INT;
            Log::load_log({LogLevel::DEBUG, token_name.c_str(), "integer"});
        }
        else if (std::regex_match(token_name, decimal_literals)) {
            _token_type.literal_ = LiteralTypes::LT_DEC;
            Log::load_log({LogLevel::DEBUG, token_name.c_str(), "decimal"});
        }
        else if (std::regex_match(token_name, string_literal)) {
            _token_type.literal_ = LiteralTypes::LT_ID;
            Log::load_log({LogLevel::DEBUG, token_name.c_str(), "string"});
        }
        else if (std::regex_match(token_name, identifier_literal)) {
            _token_type.literal_ = LiteralTypes::LT_ID;
            Log::load_log({LogLevel::DEBUG, token_name.c_str(),"identifier"});
        }
        else {
            throw E("Invalid token name");
        }
    }
}

template <typename T>
const T Token::get_token_type() {
    switch(_token_type.union_type) {
        case 0: return _token_type.operator_;
        case 1: return _token_type.keyword_;
        case 2: return _token_type.literal_;
        default: return nullptr;
    }
}

