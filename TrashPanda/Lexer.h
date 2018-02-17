//
// Created by bagool on 07/02/2018.
//

#ifndef RACCOONLANG_LEXER_H
#define RACCOONLANG_LEXER_H

#include <string>
#include <vector>
#include <stack>

#include "Token.h"

namespace RCC {

    typedef std::vector<std::string> vect_s;

    class Lexer {
        std::string _data_filename = nullptr;
        vect_s _data;
        std::stack<Token> _token_stack;
        // prevent the creation of default constructor
        explicit Lexer() = default;
        void _populate_data();

    public:
        explicit Lexer(ct_str& data_filename) : _data_filename(data_filename){}
        void tokenise();
        vect_s get_data() { return _data; }
    };

}

#endif //RACCOONLANG_LEXER_H
